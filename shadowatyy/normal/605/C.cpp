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
#define SIZE(x) (int)(x).size()
using namespace std;

#define int long long
#define double long double
const int N = 1e5+7;

int n, p, q, ma, mb;

double res = 1e9;

int a[N];
int b[N];

VPII v;

bool prawo(PII &a, PII &b, PII &c)
{
	return (a.st-c.st)*(b.nd-c.nd)-(b.st-c.st)*(a.nd-c.nd)>0;
}

VPII hull(VPII v)
{
	if(v.size()==1)
		return v;

	sort(ALL(v));
	v.erase(unique(ALL(v)), v.end());
	
	VPII uh, lh, res;

	for(auto it:v)
	{
		while(uh.size()>=2 && !prawo(it, uh.back(), uh[uh.size()-2]))
			uh.pop_back();

		uh.pb(it);
	}

	reverse(ALL(v));

	for(auto it:v)
	{
		while(lh.size()>=2 && !prawo(it, lh.back(), lh[lh.size()-2]))
			lh.pop_back();

		lh.pb(it);
	}

	uh.pop_back();
	lh.pop_back();

	res.insert(res.end(), ALL(uh));
	res.insert(res.end(), ALL(lh));

	return res;
}

void inter(PII a, PII b)
{
	double l = 0, r = 1;

	for(int i = 1; i <= 100; ++i)
	{
		double m1 = (2*l+r)/3;
		double m2 = (l+2*r)/3;

		if(max(p/(m1*a.st+(1-m1)*b.st), q/(m1*a.nd+(1-m1)*b.nd))<max(p/(m2*a.st+(1-m2)*b.st), q/(m2*a.nd+(1-m2)*b.nd)))
			r = m2;
		else
			l = m1;

		res = min(res, max(p/(m1*a.st+(1-m1)*b.st), q/(m1*a.nd+(1-m1)*b.nd)));
		res = min(res, max(p/(m2*a.st+(1-m2)*b.st), q/(m2*a.nd+(1-m2)*b.nd)));
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> p >> q;

	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i] >> b[i];
		ma = max(ma, a[i]);
		mb = max(mb, b[i]);
		v.eb(a[i], b[i]);
		res = min(res, max((double)p/a[i], (double)q/b[i]));
	}

	v.eb(ma, 0);
	v.eb(0, mb);

	VPII h = hull(v);

	for(int i = 0; i < h.size(); ++i)
	{
		inter(h[i], h[(i+1)%h.size()]);
	}

	cout << fixed << setprecision(10) << res;
}