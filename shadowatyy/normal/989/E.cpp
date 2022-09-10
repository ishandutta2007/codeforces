#include <bits/stdc++.h>
#include <unistd.h>
#define ll long long
#define inf 1000000007
#define inf16 0x3f3f3f3f
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

const int N = 207;

int n, q;

ll x[N];
ll y[N];

struct mat
{
	double v[N][N];

	mat()
	{
		for(int i = 1; i <= n; ++i)
		{
			for(int j = 1; j <= n; ++j)
			{
				v[i][j] = 0;
			}
		}
	}
};

struct vec
{
	double v[N];

	vec()
	{
		for(int i = 1; i <= n; ++i)
		{
			v[i] = 0;
		}
	}
};

mat operator*(mat a, mat b)
{
	mat c;

	for(int i = 1; i <= n; ++i)
	{
		for(int k = 1; k <= n; ++k)
		{
			for(int j = 1; j <= n; ++j)
			{
				c.v[i][j] += a.v[i][k]*b.v[k][j];
			}
		}	
	}

	return c;
}

vec operator*(vec a, mat b)
{
	vec c;

	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= n; ++j)
		{
			c.v[i] += a.v[j]*b.v[i][j];
		}
	}

	return c;
}

mat pot[16];

vec go(vec a, int p)
{
	for(int i = 0; i <= 15; ++i)
	{
		if(p&(1<<i))
			a = a*pot[i];
	}

	return a;
}

int ile_prostych[N];
VI na_prostej[N][N];

int rep[N];

double prob[N][N];

int Find(int x)
{
	if(rep[x]!=x)
		rep[x] = Find(rep[x]);

	return rep[x];
}

bool col(int a, int b, int c)
{
	return (x[a]-x[c])*(y[b]-y[c])-(x[b]-x[c])*(y[a]-y[c])==0;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for(int i = 1; i <= n; ++i)
	{
		cin >> x[i] >> y[i];
	}

	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= n; ++j)
		{
			rep[j] = j;
		}

		for(int j = 1; j <= n; ++j)
		{
			for(int k = 1; k <= n; ++k)
			{
				if(i!=j && i!=k && j!=k && col(i, j, k))
				{
					int p = Find(j);
					int q = Find(k);
					rep[p] = q;
				}
			}
		}

		for(int j = 1; j <= n; ++j)
		{
			if(i!=j && Find(j)==j)
				++ile_prostych[i];
		}
	}

	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= n; ++j)
		{
			if(i!=j)
			{
				na_prostej[i][j] = {i, j};

				for(int k = 1; k <= n; ++k)
				{
					if(i!=k && j!=k && col(i, j, k))
						na_prostej[i][j].pb(k);
				}

				prob[i][j] = 1.0/ile_prostych[i]/na_prostej[i][j].size();
				prob[i][i] -= prob[i][j];
			}
		}

		prob[i][i] += 1;
	}

	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= n; ++j)
		{
			pot[0].v[i][j] = prob[i][j];
		}
	}

	for(int i = 1; i <= 15; ++i)
	{
		pot[i] = pot[i-1]*pot[i-1];
	}

	cin >> q;

	cout << fixed << setprecision(10) << endl;

	while(q--)
	{
		int t, m;
		cin >> t >> m;

		vec x;
		x.v[t] = 1;
		x = go(x, m-1);

		double ans = 0;

		for(int i = 1; i <= n; ++i)
		{
			for(int j = i+1; j <= n; ++j)
			{
				double sum = 0;

				for(auto it:na_prostej[i][j])
					sum += x.v[it];

				ans = max(ans, sum/na_prostej[i][j].size());
			}
		}

		cout << ans << endl;
	}
}