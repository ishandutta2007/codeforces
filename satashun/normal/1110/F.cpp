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
#define dump(x) cout << #x << " = " << (x) << endl

const int MN = 500010;
const int MQ = 500010;
const int SZ = 1 << 19;
const ll INF = 1e18;

struct starry_sky_tree {
    ll all[SZ * 2], ma[SZ * 2];

    void init() {
        memset(all, 0, sizeof(all));
        memset(ma, 0, sizeof(ma));
    }

    void add(int a, int b, ll x, int k = 0, int l = 0, int r = SZ) {
        if (b <= l || r <= a) return ;
        if (a <= l && r <= b) {
            all[k] += x; return ; 
        }

        add(a, b, x, k * 2 + 1, l, (l + r) / 2);
        add(a, b, x, k * 2 + 2, (l + r) / 2, r);
        ma[k] = min(ma[k * 2 + 1] + all[k * 2 + 1], ma[k * 2 + 2] + all[k * 2 + 2]);
    }

    ll get(int a, int b, int k = 0, int l = 0, int r = SZ) {
        if (b <= l || r <= a) return INF;
        if (a <= l && r <= b) {
            return ma[k] + all[k];
        }

        ll lc = get(a, b, k * 2 + 1, l, (l + r) / 2);
        ll rc = get(a, b, k * 2 + 2, (l + r) / 2, r);
        return min(lc, rc) + all[k];
    }
} seg;

int n, q;
int p[MN], w[MN];
int in[MN], out[MN]; //[in,out)

bool leaf[MN];
vi vleaf;
vector<pair<int, ll>> g[MN];
vector<pair<int, pii>> ask[MN];
ll ans[MQ];

void pre(int v) {
	in[v] = v, out[v] = v + 1;

	for (auto e : g[v]) {
		pre(e.fi);
		out[v] = max(out[v], out[e.fi]);
	}
}

void segadd(int l, int r, ll c) {
	int a = lower_bound(ALL(vleaf), l) - vleaf.begin();
	int b = lower_bound(ALL(vleaf), r) - vleaf.begin();
	if (a <= b) {
		seg.add(a, b, c);
	}
}

ll segask(int l, int r) { //[l,r)
	int a = lower_bound(ALL(vleaf), l) - vleaf.begin();
	int b = lower_bound(ALL(vleaf), r) - vleaf.begin();

	return a > b ? INF : seg.get(a, b);
}

void dfsL(int v) {
	int sz = g[v].size();
	for (int i = 0; i < sz; ++i) {
		int to = g[v][i].fi; ll c = g[v][i].se;
		segadd(0, to, c);
		dfsL(to);
		segadd(to, out[to], c);
		segadd(0, to, -c);
	}

	for (auto dt : ask[v]) {
		int id = dt.fi, l = dt.se.fi, r = min(dt.se.se + 1, out[v]);
		ans[id] = min(ans[id], segask(l, r));
	}
}

void dfsR(int v) {
	int sz = g[v].size();
	for (int i = sz - 1; i >= 0; --i) {
		int to = g[v][i].fi; ll c = g[v][i].se;
		segadd(out[to], n, c);
		dfsR(to);
		segadd(to, out[to], c);
		segadd(out[to], n, -c);
	}

	for (auto dt : ask[v]) {
		int id = dt.fi, l = max(dt.se.fi, in[v]), r = dt.se.se + 1;
		ans[id] = min(ans[id], segask(l, r));
	}	
}

int main() {
	scanf("%d %d", &n, &q);

	for (int i = 1; i < n; ++i) {
		scanf("%d%d", &p[i], &w[i]);
		--p[i];
		g[p[i]].eb(i, w[i]);
	}

	rep(i, n) {
		if ((int)g[i].size() == 0) {
			leaf[i] = true;
			vleaf.pb(i);
		}
	}

	rep(i, q) {
		int v, l, r;
		scanf("%d%d%d", &v, &l, &r);
		--v; --l; --r;
		ask[v].eb(i, mp(l, r));
	}

	rep(i, q) ans[i] = INF;
	pre(0);
	seg.init();
	dfsL(0);
	seg.init();
	dfsR(0);

	rep(i, q) {
		cout << ans[i] << "\n";
	}

	return 0;
}