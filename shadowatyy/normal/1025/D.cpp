//~ while (clock()<=69*CLOCKS_PER_SEC)
//~ #pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("O3")
//~ #pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
#include <unistd.h>
#pragma GCC optimize ("unroll-loops")
using namespace std;
using ll = long long;
using VI = vector<int>;
using VLL = vector<ll>;
using PII = pair<int, int>;
using VPII = vector<PII>;
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define endl '\n'
#define ALL(c) (c).begin(), (c).end()
const int inf = 1e9L+7;
const ll INF = 1e18L+7;

const int N = 707;

int n;

int ok[N][N];

bitset<N> dp[N][N];

int a[N];

bitset<N> lewo[N];
bitset<N> prawo[N];

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}

	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= n; ++j)
		{
			if(__gcd(a[i], a[j])>1)
				ok[i][j] = 1;
		}
	}

	for(int i = 1; i <= n; ++i)
	{
		dp[i][i][i] = 1;

		if(i-1>=1 && ok[i][i-1])
			lewo[i][i] = 1;

		if(i+1<=n && ok[i][i+1])
			prawo[i][i] = 1;
	}

	for(int i = 0; i <= n; ++i)
	{
		lewo[i+1][i] = 1;
		prawo[i+1][i] = 1;
	}

	for(int d = 2; d <= n; ++d)
	{
		for(int a = 1; a+d-1 <= n; ++a)
		{
			int b = a+d-1;

			for(int r = a; r <= b; ++r)
			{
				if(prawo[a][r-1] && lewo[r+1][b])
				{
					dp[a][b][r] = 1;

					if(ok[r][a-1])
						lewo[a][b] = 1;

					if(ok[r][b+1])
						prawo[a][b] = 1;
				}
			}
		}
	}

	for(int i = 1; i <= n; ++i)
	{
		if(dp[1][n][i])
		{
			cout << "Yes" << endl;
			return 0;
		}
	}

	cout << "No" << endl;
}