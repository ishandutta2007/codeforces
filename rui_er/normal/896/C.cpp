//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll MAXN = 100001;

ll n, m, seed, vmax;
ll a[MAXN];
struct Node
{
	ll l, r;
	mutable ll v;
	Node(ll x, ll y = -1, ll z = 0): l(x), r(y), v(z) {}
	bool operator < (const Node &a) const {return l < a.l;}
};
typedef set<Node>::iterator IT;
set<Node> ODT;

ll rnd() 
{
	ll ret = seed;
	seed = (seed * 7 + 13) % mod;
	return ret;
}

IT split(ll pos)
{
	IT iter = ODT.lower_bound(Node(pos));
	if(iter != ODT.end() && iter->l == pos) return iter;
	--iter;
	ll L = iter->l, R = iter->r, V = iter->v;
	ODT.erase(iter);
	ODT.insert(Node(L, pos-1, V));
	return ODT.insert(Node(pos, R, V)).first;
}

void update(ll l, ll r, ll dt)
{
	IT iterR = split(r+1), iterL = split(l);
	for(iterL;iterL!=iterR;++iterL) iterL->v += dt;
}

void assign_val(ll l, ll r, ll w)
{
	IT iterR = split(r+1), iterL = split(l);
	ODT.erase(iterL, iterR);
	ODT.insert(Node(l, r, w));
}

ll ranking(ll l, ll r, ll k)
{
	vector<pair<ll, ll> > v;
	IT iterR = split(r+1), iterL = split(l);
	for(iterL;iterL!=iterR;++iterL) v.push_back(make_pair(iterL->v, iterL->r-iterL->l+1));
	sort(v.begin(), v.end());
	for(vector<pair<ll, ll> >::iterator iter=v.begin();iter!=v.end();++iter)
	{
		k -= iter->second;
		if(k <= 0) return iter->first;
	}
}

ll qpow(ll x, ll y, ll MOD)
{
	ll ret = 1;
	ll ans = x % MOD;
	while(y)
	{
		if(y&1) ret = ret * ans % MOD;
		ans = ans * ans % MOD;
		y >>= 1;
	}
	return ret;
}

ll sum(ll l, ll r, ll x, ll y)
{
	ll ans = 0;
	IT iterR = split(r+1), iterL = split(l);
	for(iterL;iterL!=iterR;++iterL)
		ans = (ans + (iterL->r - iterL->l + 1) * qpow(iterL->v, x, y)) % y;
	return ans;
}

int main()
{
	scanf("%lld%lld%lld%lld", &n, &m, &seed, &vmax);
	for(ll i=1;i<=n;i++)
	{
		a[i] = (rnd() % vmax) + 1;
		ODT.insert(Node(i, i, a[i]));
	}
	for(ll i=1;i<=m;i++)
	{
		ll op = rnd() % 4 + 1;
		ll l = rnd() % n + 1;
		ll r = rnd() % n + 1;
		if(l > r) swap(l, r);
		ll x, y;
		if(op == 3) x = rnd() % (r - l + 1) + 1;
		else x = rnd() % vmax + 1;
		if(op == 4) y = rnd() % vmax + 1;
		if(op == 1) update(l, r, x);
		else if(op == 2) assign_val(l, r, x);
		else if(op == 3) printf("%lld\n", ranking(l, r, x));
		else printf("%lld\n", sum(l, r, x, y));
	}
	return 0;
}