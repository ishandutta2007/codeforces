#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()

const ll MOD = 1000000007;

const int sz = 1 << 18;

struct segtree {
    vector<vector<int> > dat;

    segtree(){}

    void init(vector<int> num)
    {
	dat.resize(sz * 2);

	rep(i, num.size()) dat[sz - 1 + i].pb(num[i]);

	for (int i = sz - 2; i >= 0; --i) {
	    int lc = i * 2 + 1, rc = i * 2 + 2;
	    dat[i].resize(dat[lc].size() + dat[rc].size());
	    merge(dat[lc].begin(), dat[lc].end(), dat[rc].begin(), dat[rc].end(), dat[i].begin());
	}
    }

    int ask(int a, int b, int t, int k = 0, int l = 0, int r = sz)
    {
	if (b <= l || r <= a) return 0LL;
	if (a <= l && r <= b) {
	    int i = lower_bound(ALL(dat[k]), t) - dat[k].begin();
	    return dat[k].size() - i;
	}

	return ask(a, b, t, k * 2 + 1, l, (l + r) / 2) + ask(a, b, t, k * 2 + 2, (l + r) / 2, r);
    }
} seg;

ll mod_pow(ll x, ll k)
{
    ll res = 1;
    for (; k; x = x * x % MOD, k /= 2) if (k & 1) res = res * x % MOD;
    return res;
}

int n, k;
pii iv[200010];
vector<int> xs;
ll ret;
ll fact[200010];
ll ifact[200010];

int main() {
    fact[0] = ifact[0] = 1;

    for (int i = 1; i <= 200000; ++i) {
	fact[i] = fact[i - 1] * i % MOD;
	ifact[i] = mod_pow(fact[i], MOD - 2);
    }

    scanf("%d %d", &n, &k);

    rep(i, n) {
	scanf("%d %d", &iv[i].fi, &iv[i].se);
	xs.pb(iv[i].fi);
	xs.pb(iv[i].fi - 1);
	xs.pb(iv[i].se);
	xs.pb(iv[i].se + 1);
    }

    sort(ALL(xs));
    xs.erase(unique(ALL(xs)), xs.end());

    sort(iv, iv + n);
    vi vec(n);
    rep(i, n) vec[i] = iv[i].se;

    seg.init(vec);

    rep(ii, (int)xs.size() - 1) {
	int x = xs[ii];
	int i = lower_bound(iv, iv + n, mp(x, INT_MAX)) - iv;

	if (i == 0) continue;

	int num = seg.ask(0, i, x);

	if (num < k) continue;

	ll ac = fact[num] * ifact[num - k] % MOD * ifact[k] % MOD;

	ret = (ret + (xs[ii + 1] - xs[ii]) * ac) % MOD;

	//cout << x << " " << num << " " << ac << endl;
    }

    cout << ret << endl;

    return 0;
}