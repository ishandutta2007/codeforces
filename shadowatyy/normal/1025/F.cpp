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

const int N = 2007;

int n;

ll ans;

int g[N];

struct P
{
	int x, y;

	P operator-()
	{
		return (P){-x, -y};
	}
};

bool prawo(const P &a, const P &b)
{
	return (ll)a.x*b.y-(ll)b.x*a.y>0;
}

bool comp(const pair<P, int> &a, const pair<P, int> &b)
{
	return prawo(a.st, b.st);
}

void solve(P s, vector<P> v)
{
	vector<pair<P, int> > u, l;
	int cnt = 0;

	for(auto &it:v)
	{
		it.x -= s.x;
		it.y -= s.y;

		if(it.x || it.y)
		{
			if(it.y>0 || (it.y==0 && it.x>0))
			{
				u.eb(it, ++cnt);
				l.eb(-it, -cnt);
			}
			else
			{
				l.eb(it, ++cnt);
				u.eb(-it, -cnt);
			}
		}
	}

	sort(ALL(u), comp);
	sort(ALL(l), comp);
	u.insert(u.end(), ALL(l));

	for(int i = 1; i < n; ++i)
	{
		g[i] = -1;
	}

	int licz = 0;

	for(auto it:u)
	{
		if(it.nd>0)
			++licz;

		if(g[abs(it.nd)]==-1)
			g[abs(it.nd)] = licz;
		else
		{
			int ile = licz-g[abs(it.nd)];

			if(it.nd>0)
				--ile;

			ans += (ll)ile*(ile-1)/2 * (n-2-ile)*(n-2-ile-1)/2;
		}
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	vector<P> in(n);

	for(int i = 0; i < n; ++i)
	{
		cin >> in[i].x >> in[i].y;
	}

	for(auto it:in)
	{
		solve(it, in);
	}

	cout << ans/2 << endl;
}