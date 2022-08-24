#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;
typedef long long ll;
typedef long double ld;
const int MAXN = 52;

int N, P;
int arr[MAXN];
ld dp[MAXN][MAXN][MAXN]; //cur person / how many taken / length

ld fac (int x)
{
	ld res = 1.0;
	for (int i = 1; i <= x; i++)
		res *= i;
	return res;
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	cin >> P;
	
	ld ans = 0.0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < MAXN; j++)
			for (int k = 0; k < MAXN; k++)
				for (int l = 0; l < MAXN; l++)
					dp[j][k][l] = 0.0;
		dp[0][0][arr[i]] = 1.0;
		
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < MAXN; k++)
				for (int l = 0; l < MAXN; l++)
				{
					dp[j+1][k][l] = dp[j][k][l];
				}
			
			if (i == j) continue;
			
			for (int k = 0; k <= N; k++)
				for (int l = 0; l <= P; l++)
				{
					if (l + arr[j] <= P)
					{
						dp[j+1][k+1][l+arr[j]] += dp[j][k][l];
					}
				}
		}
		
		for (int j = 0; j <= N; j++)
		{
			ld sum = 0.0;
			for (int k = 0; k <= P; k++)
			{
				sum += dp[N][j][k];
			}
			
			sum *= fac (j);
			sum *= fac (N - 1 - j);
			sum /= fac (N);
			ans += sum;
		}
	}
	
	cout << fixed << setprecision (7);
	cout << ans << "\n";
	return 0;
}