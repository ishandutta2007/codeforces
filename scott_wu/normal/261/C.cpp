#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;
typedef long long ll;
const int MAXD = 55;

ll N, T;
ll gres;
ll nval[MAXD][MAXD]; //[i][j] is # of 2^j in range [2^i, 2^(i+1))
ll P; // power of N;

ll solve (ll npow, ll goal, ll apow)
{
	//cout << npow << " " << goal << " " << apow << "\n";
	if (apow < 0) return 0;
	if (npow == 0)
	{
		if (goal == 1 && apow == 0)
			return 1;
		return 0;
	}
	
	if (goal == (1LL << (npow + 1)) - 1)
		return nval[npow][apow];
	
	ll sp = (1LL << npow) + (1LL << (npow - 1));
	if (goal < sp)
		return solve (npow - 1, goal - (1LL << (npow - 1)), apow);
	return solve (npow - 1, sp - 1 - (1LL << (npow - 1)), apow) + solve (npow - 1, goal - (1LL << npow), apow - 1);
}

int main()
{
	cin >> N >> T;
	N++;
	
	for (int i = 0; i < MAXD; i++)
		for (int j = 0; j < MAXD; j++)
			nval[i][j] = 0;
	nval[0][0] = 1;
	
	for (int i = 0; i < 50; i++)
	{
		for (int j = 0; j < 50; j++)
		{
			nval[i+1][j] += nval[i][j];
			nval[i+1][j+1] += nval[i][j];
		}
	}
	
	P = 0;
	while ((1LL << P) <= N)
		P++;
	P--;
	
	gres = 0;
	while ((1LL << gres) < T)
		gres++;
	if ((1LL << gres) != T)
	{
		cout << "0\n";
		return 0;
	}
	
	ll ans = 0;
	for (int i = 0; i < P; i++)
		ans += nval[i][gres];
	
	ans += solve (P, N, gres);
	if (T == 1) ans--;
	cout << ans << "\n";
	return 0;
}