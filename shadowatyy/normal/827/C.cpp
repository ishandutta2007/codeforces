#include <bits/stdc++.h>
#include <unistd.h>
#define ll long long
#define ull unsigned long long
#define inf 1000000007
#define inf16 0x3f3f3f3f
#define INF 1000000000000000007LL
#define VI vector<int>
#define VPII vector<pair<int, int> >
#define VLL vector<ll>
#define PII pair<int, int>
#define PLL pair<ll, ll>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define endl '\n'
#define ALL(c) (c).begin(), (c).end()
#define flush fflush(stdout)
using namespace std;

#define M (1<<17)

int n, q, t, l, r, x;

char c;

string s, e;

int pos[256];

int ile[4][11][10][2*M];

int query(int a, int b, char l, int m, int r)
{
	a += M;
	b += M;

	int res = ile[pos[l]][m][r][a];

	if(a!=b)
		res +=  ile[pos[l]][m][r][b];

	while(a<b-1)
	{
		if(a%2==0)
			res += ile[pos[l]][m][r][a+1];
		
		if(b%2==1)
			res += ile[pos[l]][m][r][b-1];

		a /= 2;
		b /= 2;
	}

	return res;
}

int insert(int p, char before, char after)
{
	int a = p+M;

	while(a>=1)
	{
		for(int i = 1; i <= 10; ++i)
		{
			ile[pos[before]][i][p%i][a]--;
			ile[pos[after]][i][p%i][a]++;
		}

		a /= 2;
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	pos['A'] = 0;
	pos['T'] = 1;
	pos['C'] = 2;
	pos['G'] = 3;

	cin >> s;
	n = s.size();

	for(int i = 0; i < n; ++i)
	{
		for(int j = 1; j <= 10; ++j)
		{
			ile[pos[s[i]]][j][i%j][i+M] = 1;
		}
	}

	for(int i = M-1; i >= 1; --i)
	{
		for(int j = 1; j <= 10; ++j)
		{
			for(int r = 0; r < j; ++r)
			{
				for(int t = 0; t < 4; ++t)
				{
					ile[t][j][r][i] = ile[t][j][r][2*i]+ile[t][j][r][2*i+1];
				}
			}
		}
	}

	cin >> q;

	while(q--)
	{
		cin >> t;

		if(t==1)
		{
			cin >> x >> c;
			--x;

			insert(x, s[x], c);
			s[x] = c;
		}
		else
		{
			cin >> l >> r >> e;
			--l;
			--r;

			int ans = 0;

			for(int i = 0; i < e.size(); ++i)
			{
				ans += query(l, r, e[i], e.size(), (i+l)%e.size());
			}

			cout << ans << endl;
		}
	}
}