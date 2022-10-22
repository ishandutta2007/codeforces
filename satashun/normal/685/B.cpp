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

typedef pair<pii, int> Val;

const int SZ = 1 << 19;

struct segtree {
    vector<vector<Val>> dat;
    vector<vector<pii>> ac;

    segtree(){}

    void init(vector<Val> &num)
    {
	dat.resize(SZ * 2);
	ac.resize(SZ * 2);

	rep(i, num.size()) {
	    ac[SZ - 1 + i].pb(mp(0, 0));
	    dat[SZ - 1 + i].pb(num[i]);
	    ac[SZ - 1 + i].pb(mp(num[i].fi.se, num[i].se));
	}

	for (int i = SZ - 2; i >= 0; --i) {
	    int lc = i * 2 + 1, rc = i * 2 + 2;
	    dat[i].resize(dat[lc].size() + dat[rc].size());
	    merge(dat[lc].begin(), dat[lc].end(), dat[rc].begin(), dat[rc].end(), dat[i].begin());

	    ac[i].pb(mp(0, 0));

	    for (Val &t : dat[i]) {
		pii nx = max(ac[i].back(), mp(t.fi.se, t.se));
		ac[i].pb(nx);
	    }
	}
    }

    pii ask(int a, int b, int s, int k = 0, int l = 0, int r = SZ)
    {
	if (b <= l || r <= a) return mp(0, 0);

	if (a <= l && r <= b) {
	    if (dat[k].size() == 0 || dat[k][0].fi.fi > s / 2) return mp(0, 0);
	    int lo = 0, hi = dat[k].size();

	    while (hi - lo > 1) {
		int m = (lo + hi) / 2;
		if (dat[k][m].fi.fi <= s / 2) lo = m;
		else hi = m;
	    }

	    return ac[k][lo + 1];
	}

	return max(ask(a, b, s, k * 2 + 1, l, (l + r) / 2), ask(a, b, s, k * 2 + 2, (l + r) / 2, r));
    }
} seg;

const int MN = 300010;

int n, q;
vi g[MN];
int sz[MN];
int md[MN];

int in[MN], out[MN];
vector<Val> vec;

void dfs(int v, int &k)
{
    sz[v] = 1;
    in[v] = k++;

    for (int to : g[v]) {
	dfs(to, k);
	sz[v] += sz[to];
	md[v] = max(md[v], sz[to]);
    }

    out[v] = k;
}

int main() {
    scanf("%d %d", &n, &q);

    rep(i, n - 1) {
	int p;
	scanf("%d", &p);
	--p;

	g[p].pb(i + 1);
    }

    int now = 0;
    dfs(0, now);

    vec.resize(n);
    rep(i, n) vec[in[i]] = mp(mp(md[i], sz[i]), i);
    seg.init(vec);

    while (q--) {
	int v;
	scanf("%d", &v);
	--v;

	pii ret = seg.ask(in[v], out[v], sz[v]);

	printf("%d\n", ret.se + 1);
    }

    return 0;
}