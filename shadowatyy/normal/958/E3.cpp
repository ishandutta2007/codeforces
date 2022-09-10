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

#define VP vector<pkt>
const int N = 2e4+7;

int n;

int ans[N];

struct pkt
{
	int x, y, col, ind;

	bool operator<(const pkt &a) const
	{
		if(x==a.x)
			return y<a.y;
		else
			return x<a.x;
	}

	bool operator==(const pkt &a) const
	{
		return x==a.x && y==a.y;
	}
};

bool prawo(pkt &a, pkt &b, pkt &c)
{
	return (a.x-c.x)*(b.y-c.y)-(b.x-c.x)*(a.y-c.y)>0;
}

pkt p[N];

VP hull(VP &p)
{
	VP u, l;

	sort(ALL(p));

	for(auto it:p)
	{
		while(u.size()>=2 && !prawo(it, u.back(), u[u.size()-2]))
			u.pop_back();

		u.pb(it);
	}

	reverse(ALL(p));

	for(auto it:p)
	{
		while(l.size()>=2 && !prawo(it, l.back(), l[l.size()-2]))
			l.pop_back();

		l.pb(it);
	}

	u.pop_back();
	l.pop_back();
	u.insert(u.end(), ALL(l));
	return u;
}

pkt curr;

bool comp(pkt a, pkt b)
{
	return prawo(a, b, curr);
}

VP sortuj(VP p, pkt &s)
{
	curr = s;
	sort(ALL(p), comp);
	return p;
}

void match(pkt &a, pkt &b)
{
	if(a.col!=1)
		swap(a, b);

	ans[a.ind] = b.ind;
}

void solve(VP &p)
{
	if(p.empty())
		return;

	if(p.size()==2)
	{
		match(p[0], p[1]);
		return;
	}

	VP h = hull(p);
	random_shuffle(ALL(h));

	for(auto &it:p)
	{
		if(it==h[0])
		{
			swap(it, p.back());
			p.pop_back();
			break;
		}
	}

	p = sortuj(p, h[0]);

	int cnt[] = {0, 0};

	VI moge;

	for(int i = 0; i < p.size(); ++i)
	{
		auto it = p[i];
		++cnt[it.col];

		if(cnt[h[0].col^1]==cnt[h[0].col]+1 && it.col==h[0].col^1)
			moge.pb(i);
	}

	random_shuffle(ALL(moge));

	match(h[0], p[moge[0]]);

	VP l, r;

	for(int j = 0; j < moge[0]; ++j)
	{	
		l.pb(p[j]);
	}

	for(int j = moge[0]+1; j < p.size(); ++j)
	{
		r.pb(p[j]);
	}

	solve(l);
	solve(r);
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	VP s;

	for(int i = 1; i <= n; ++i)
	{
		cin >> p[i].x >> p[i].y;
		p[i].ind = i;
		p[i].col = 1;
		s.pb(p[i]);
	}

	for(int i = n+1; i <= 2*n; ++i)
	{
		cin >> p[i].x >> p[i].y;
		p[i].ind = i-n;
		p[i].col = 0;
		s.pb(p[i]);
	}

	srand(24);
	solve(s);

	for(int i = 1; i <= n; ++i)
	{
		cout << ans[i] << endl;
	}
}