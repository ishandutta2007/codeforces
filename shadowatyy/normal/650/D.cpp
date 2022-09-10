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

const int N = 1<<20;
const int mod = 1e9+696969;

struct node
{
	node* L = NULL;
	node* R = NULL;
	PII sub = mp(0, 0);
};

int n, m;

int h[N];
int a[N];
int b[N];
int ans[N];

VI tutaj[N];

VI val;

node* root[N];

inline PII merge(const PII &a, const PII &b)
{
	if(a.st==b.st)
		return mp(a.st, (a.nd+b.nd)%mod);
	else
		return max(a, b);
}

PII query(int a, int b, node* v, int l = 0, int r = N-1)
{
	if(!v || a>r || l>b)
		return mp(0, 0);

	if(a<=l && r<=b)
		return v->sub;

	PII x = query(a, b, v->L, l, (l+r)/2);
	PII y = query(a, b, v->R, (l+r)/2+1, r);
	return merge(x, y);
}

node* insert(int a, PII val, node* v, int l = 0, int r = N-1)
{
	auto nv = new node();

	if(v)
	{
		nv->L = v->L;
		nv->R = v->R;
		nv->sub = v->sub;
	}

	if(l==r)
	{
		nv->sub = merge(nv->sub, val);
		return nv;
	}

	if(a<=(l+r)/2)
		nv->L = insert(a, val, nv->L, l, (l+r)/2);
	else
		nv->R = insert(a, val, nv->R, (l+r)/2+1, r);

	nv->sub = merge(nv->sub, val);
	return nv;
}

struct zwykle
{
	PII load[2*N];

	void insert(int a, PII val)
	{
		a += N;

		while(a)
		{
			load[a] = merge(load[a], val);
			a /= 2;
		}
	}

	PII query(int a, int b)
	{
		if(a>b)
			return mp(0, 0);

		a += N;
		b += N;

		PII res = merge(load[a], load[b]);

		while(a<b-1)
		{
			if(a%2==0)
				res = merge(res, load[a+1]);

			if(b%2==1)
				res = merge(res, load[b-1]);

			a /= 2;
			b /= 2;
		}

		return res;
	}
};

zwykle T;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> m;

	for(int i = 1; i <= n; ++i)
	{
		cin >> h[i];
		val.pb(h[i]);
	}

	for(int i = 1; i <= m; ++i)
	{
		cin >> a[i] >> b[i];
		tutaj[a[i]].pb(i);
		val.pb(b[i]);
	}

	sort(ALL(val));
	val.erase(unique(ALL(val)), val.end());

	for(int i = 1; i <= n; ++i)
	{
		h[i] = lower_bound(ALL(val), h[i])-val.begin();
	}

	for(int i = 1; i <= m; ++i)
	{
		b[i] = lower_bound(ALL(val), b[i])-val.begin();
	}

	for(int i = 1; i <= n; ++i)
	{
		auto q = query(0, h[i]-1, root[i-1]);

		if(q.st==0)
			root[i] = insert(h[i], mp(1, 1), root[i-1]);
		else
			root[i] = insert(h[i], mp(1+q.st, q.nd), root[i-1]);	
	}

	auto all = query(0, N-1, root[n]);

	for(int i = n; i >= 1; --i)
	{
		for(auto it:tutaj[i])
		{
			ans[it] = 1+query(0, b[it]-1, root[i-1]).st+T.query(b[it]+1, N-1).st;

			auto q1 = query(0, h[a[it]]-1, root[i-1]);
			auto q2 = T.query(h[a[it]]+1, N-1);

			if(q1.st+1+q2.st==all.st && (ll)(q1.st?q1.nd:1)*(q2.st?q2.nd:1)%mod==all.nd)
				ans[it] = max(ans[it], all.st-1);
			else
				ans[it] = max(ans[it], all.st);
		}

		auto q = T.query(h[i]+1, N-1);

		if(q.st==0)
			T.insert(h[i], mp(1, 1));
		else
			T.insert(h[i], mp(q.st+1, q.nd));
	}

	for(int i = 1; i <= m; ++i)
	{
		cout << ans[i] << endl;
	}
}