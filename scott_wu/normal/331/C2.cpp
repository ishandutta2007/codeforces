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

int mdig (ll x)
{
	return ((x == 0) ? 0 : max (x % 10, (ll) mdig (x / 10)));
}

int fmdig (ll x)
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
	
	ll ans = 0;
	if (N < (int) 1e6)
	{
		cout << solve (N) << "\n";
		return 0;
	}
	
	while ((N % (int) 1e6) < 999990)
	{
		N -= fmdig (N);
		ans++;
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