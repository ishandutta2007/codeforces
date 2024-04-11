#include <bits/stdc++.h>
#include <unistd.h>
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

int n, m, q;

int ans[1<<12][107];

int w[12];

int ile[1<<12];

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> m >> q;

	for(int i = 0; i < n; ++i)
	{
		cin >> w[i];
	}

	for(int i = 0; i < m; ++i)
	{
		string s;
		cin >> s;
		int x = 0;

		for(int j = 0; j < n; ++j)
		{
			if(s[j]=='1')
				x |= 1<<j;
		}

		++ile[x];
	}

	for(int i = 0; i < 1<<n; ++i)
	{
		for(int j = 0; j < 1<<n; ++j)
		{
			int zle = (i^j);
			int licz = 0;

			for(int k = 0; k < n; ++k)
			{
				if(!(zle&(1<<k)))
					licz += w[k];
			}

			if(licz<=100)
			{
				ans[j][licz] += ile[i];
			}
		}
	}

	for(int i = 0; i < 1<<n; ++i)
	{
		for(int j = 1; j <= 100; ++j)
		{
			ans[i][j] += ans[i][j-1];
		}
	}

	while(q--)
	{
		string s;
		int k;
		cin >> s >> k;
		int x = 0;

		for(int j = 0; j < n; ++j)
		{
			if(s[j]=='1')
				x |= 1<<j;
		}

		cout << ans[x][k] << endl;
	}
}