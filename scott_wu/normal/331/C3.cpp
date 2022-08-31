#include <iostream>
#include <cstdio>
#include <ctime>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <map>

using namespace std;
typedef long long ll;

ll N;
int dp[10][10]; //max digit other than first 6 is i, last 6 dig are 99999j
int nval[10][10];
int pm[1000010];

ll ndp[10][10]; //999999 -> 999999
int nnval[10][10];

int mdig (ll x)
{
	return ((x == 0) ? 0 : max (x % 10, (ll) mdig (x / 10)));
}

inline int fmdig (ll x)
{
	return max (pm[x / 1000000], pm[x % 1000000]);
}

void sdp (int x, int y)
{
	int yold = y;
	
	y += 999990;
	
	int res = 0;
	while (y >= 0)
	{
		y -= max (pm[y], x);
		res++;
	}
	
	dp[x][yold] = res;
	nval[x][yold] = y + 10;
}

void sndp (int x, int y)
{
	int yold = y;
	
	ll res = 0;
	for (int i = 999999; i >= 0; i--)
	{
		int xval = max (pm[i], x);
		res += dp[xval][y];
		y = nval[xval][y];
	}
	ndp[x][yold] = res;
	nnval[x][yold] = y;
}

int solve (int x)
{
	int count = 0;
	while (x)
	{
		count++;
		x -= pm[x];
	}
	return count;
}

int main()
{
	pm[0] = 0;
	for (int i = 1; i <= 1000000; i++)
		pm[i] = mdig (i);
	
	cin >> N;
	
	for (int i = 1; i < 10; i++)
		for (int j = 0; j < 10; j++)
		{
			sdp (i, j);
			//cout << dp[i][j] << " " << nval[i][j] << "\n";
		}
	for (int i = 1; i < 10; i++)
		for (int j = 0; j < 10; j++)
			sndp (i, j);
	
	ll ans = 0;
	if (N < (int) 1e6)
	{
		cout << solve (N) << "\n";
		return 0;
	}
	
	while ((N % (int) 1e6) < 999990)
	{
		N -= mdig (N);
		ans++;
	}
	
	if (N < 2e12)
	{
		while (N > (int) 1e6)
		{
			int x = fmdig (N / (int) 1e6), y = N % 10;
			ans += dp[x][y];
			N -= (int) 1e6 + N % 10;
			N += nval[x][y];
		}
		cout << ans + solve (N) << "\n";
		return 0;
	}
	
	while ((N / (int) 1e6) % (int) 1e6 != 999999)
	{
		int x = fmdig (N / (int) 1e6), y = N % 10;
		ans += dp[x][y];
		N -= (int) 1e6 + N % 10;
		N += nval[x][y];
	}
	while (N > (ll) 1e12)
	{
		int x = pm[(int) (N / ((ll) 1e12))], y = N % 10;
		ans += ndp[x][y];
		N -= (ll) 1e12 + N % 10;
		N += nnval[x][y];
	}
	
	while (N > (int) 1e6)
	{
		int x = fmdig (N / (int) 1e6), y = N % 10;
		ans += dp[x][y];
		N -= (int) 1e6 + N % 10;
		N += nval[x][y];
	}
	cout << ans + solve (N) << "\n";
	return 0;
}