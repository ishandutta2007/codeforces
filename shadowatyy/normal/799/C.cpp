#include <bits/stdc++.h>
#include <unistd.h>
#define ll long long
#define ull unsigned long long
#define inf 1000000007
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
using namespace std;

#define N 100007
#define M (1<<17)

int n, c, d, res; //c-0, d-1

int b[N];
int p[N];

char t[N];

int load[2][2*M];

void insert(int i, int a, int v)
{
	a += M;
	load[i][a] = max(load[i][a], v);
	a /= 2;

	while(a>=1)
	{
		load[i][a] = max(load[i][a*2], load[i][a*2+1]);
		a /= 2;
	}
}

int query(int i, int a, int b)
{
	if(a>b)
		return 0;

	a += M;
	b += M;

	int res = max(load[i][a], load[i][b]);

	while(a<b-1)
	{
		if(a%2==0)
			res = max(res, load[i][a+1]);

		if(b%2==1)
			res = max(res, load[i][b-1]);

		a /= 2;
		b /= 2;
	}

	return res;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> c >> d;

	for(int i = 1; i <= n; ++i)
	{
		cin >> b[i] >> p[i] >> t[i];

		if(t[i]=='C')
		{
			int q = query(0, 1, c-p[i]);

			if(q)
				res = max(res, q+b[i]);

			insert(0, p[i], b[i]);
		}
		else
		{
			int q = query(1, 1, d-p[i]);

			if(q)
				res = max(res, q+b[i]);

			insert(1, p[i], b[i]);
		}
	}

	memset(load[0], 0, sizeof load[0]);
	memset(load[1], 0, sizeof load[1]);

	for(int i = 1; i <= n; ++i)
	{
		if(t[i]=='C')
		{
			if(c>=p[i])
			{
				int q = query(1, 1, d);

				if(q)
					res = max(res, q+b[i]);
			}

			insert(0, p[i], b[i]);
		}
		else
		{
			if(d>=p[i])
			{
				int q = query(0, 1, c);

				if(q)
					res = max(res, q+b[i]);
			}

			insert(1, p[i], b[i]);
		}
	}

	cout << res;
}