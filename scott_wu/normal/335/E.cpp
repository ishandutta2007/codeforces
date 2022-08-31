#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
typedef long long ll;
typedef long double ld;
const int MAXN = 30100;
const int MAXH = 32;

string str;
int N, H;

ld dp[MAXN][MAXH]; // all i nodes are at most j and i+1-th node is j+1, expected dist for B
ld ppart[MAXN][MAXH];
ld prob[MAXH];

ld res[MAXH];

int main()
{
	cin >> str;
	cin >> N >> H;
	
	if (str[0] == 'B')
	{
		cout << N << "\n";
		return 0;
	}
	
	for (int i = 0; i < MAXN; i++)
		dp[i][0] = i;
	
	for (int i = 1; i < MAXH; i++)
	{
		dp[0][i] = ppart[0][i] = 0.0;
		
		ld ptot = 0.5;
		prob[0] = 0.5;
		for (int j = 1; j <= i; j++)
		{
			prob[j] = prob[j-1] / 2.0;
			ptot += prob[j];
		}
		
		for (int j = 0; j <= i; j++)
			prob[j] *= 1.0 / ptot;
		
		ld pnone = 1.0;
		for (int j = 1; j < MAXN; j++)
		{
			ld nnone = pnone * (1.0 - prob[i]);
			//pnone *= (1.0 - prob[i]);
			
			//if (j == 2 && i == 1)
			//	cout << pnone << " " << nnone << "\n";
			
			dp[j][i] = nnone * dp[j][i-1] + (pnone - nnone) * (dp[j-1][i-1] + (1 << i)) + ppart[j-1][i] + prob[i] * (1.0 - pnone) * (1 << i);
			ppart[j][i] = dp[j][i] - nnone * dp[j][i-1];
			
			pnone = nnone;
		}
	}
	
	res[0] = N - 1;
	for (int i = 1; i <= H; i++)
	{
		ld ptot = 0.5;
		prob[0] = 0.5;
		for (int j = 1; j <= i; j++)
		{
			prob[j] = prob[j-1] / 2.0;
			ptot += prob[j];
		}
		
		if (i == H)
		{
			ptot = 1.0;
			prob[i] *= 2.0;
		}
		
		for (int j = 0; j <= i; j++)
			prob[j] *= 1.0 / ptot;
		
		ld none = 1.0;
		for (int j = 0; j < N; j++)
			none *= (1.0 - prob[i]);
		
		res[i] = none * res[i-1];
		
		res[i] += (1.0 - none) * ((N * prob[i] / (1.0 - none) - 1) * (1 << i));
		
		ld pprob = prob[i];
		for (int j = 0; j < N; j++)
		{
			//cout << j << " " << i-1 << " " << dp[j][i-1] << " " << ppart[j][i-1] << "\n";
			res[i] += pprob * 2.0 * dp[j][i-1];
			pprob *= (1.0 - prob[i]);
		}
	}
	
	
	cout << fixed << setprecision (10);
	
	//for (int i = 0; i <= H; i++)
	//	cout << res[i] << "\n";
	
	cout << res[H] + 1.0 << "\n";
	return 0;
}