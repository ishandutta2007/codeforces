#include <bits/stdc++.h>
#include <unistd.h>
#define ll long long
#define inf 1000000007
#define INF 1000000000000000007LL
#define VI vector<int>
#define VPII vector<pair<int, int> >
#define VLL vector<ll>
#define PII pair<int, int>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define endl '\n'
#define ALL(c) (c).begin(), (c).end()
using namespace std;

const int N = 1e5+7;

int n, cnt;

ll all, ans;

ll a[N];
bitset<N> l[67];
bitset<N> m[67];
int res[N];

bool solve()
{
	for(int i = 1; i <= cnt; ++i)
	{
		l[i] = m[i];
	}

	int od = 1;

	for(int i = 1; i <= n; ++i)
	{
		for(int j = od; j <= cnt; ++j)
		{
			if(m[j][i])
			{
				for(int k = 1; k <= n+1; ++k)
				{
					if(m[od][k]!=m[j][k])
					{
						m[od][k] = m[od][k]^1;
						m[j][k] = m[j][k]^1;
					}

				}
			}
		}

		if(m[od][i])
		{
			for(int j = od+1; j <= cnt; ++j)
			{
				if(m[j][i])
				{
					for(int k = 1; k <= n+1; ++k)
					{
						m[j][k] = m[j][k]^m[od][k];
					}
				}
			}

			++od;
		}
	}

	if(m[cnt][n+1] && m[cnt].count()==1)
	{	
		for(int i = 1; i <= cnt; ++i)
		{
			m[i] = l[i];
		}

		return 0;
	}
	else
		return 1;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		all ^= a[i];
	}

	for(int i = 59; i >= 0; --i)
	{
		if(!(all&(1ll<<i)))
		{
			++cnt;

			for(int j = 1; j <= n; ++j)
			{
				m[cnt][j] = bool(a[j]&(1ll<<i));
			}

			m[cnt][n+1] = 1;

			if(!solve())
				--cnt;
			else
				ans += 1ll<<i;
		}
	}

	for(int i = 59; i >= 0; --i)
	{
		if(all&(1ll<<i))
		{
			++cnt;

			for(int j = 1; j <= n; ++j)
			{
				m[cnt][j] = bool(a[j]&(1ll<<i));
			}

			m[cnt][n+1] = 0;

			if(!solve())
			{
				--cnt;
				ans += 1ll<<i;
			}
		}
	}

	for(int i = cnt; i >= 1; --i)
	{
		int v = m[i].count()-m[i][n+1];

		for(int j = n; j >= 1; --j)
		{
			if(m[i][j])
			{
				if(v==1)
					res[j] = m[i][n+1];
				else
					m[i][n+1] = m[i][n+1]^res[j];

				--v;
			}
		}
	}

	cerr << ans+(all^ans) << endl;

	for(int i = 1; i <= n; ++i)
	{
		if(res[i])
			cout << 1 << " ";
		else
			cout << 2 << " ";
	}	

	cout << endl;
}