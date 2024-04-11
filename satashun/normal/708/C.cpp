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

const int MX = 400010;
const int SZ = 1 << 19;

struct segtree {
    vector<int> dat;

    void init() {
	dat.resize(SZ * 2);
	rep(i, SZ * 2) dat[i] = INT_MIN;
    }

    void update(int pos, int x) {
	pos += SZ - 1;
	dat[pos] = x;

	while (pos > 0) {
	    pos = (pos - 1) / 2;
	    dat[pos] = max(dat[pos * 2 + 1], dat[pos * 2 + 2]);
	}
    }

    int get(int a, int b, int k = 0, int l = 0, int r = SZ) {
	if (b <= l || r <= a) return INT_MIN;
	if (a <= l && r <= b) return dat[k];
	return max(get(a, b, k * 2 + 1, l, (l + r) / 2), get(a, b, k * 2 + 2, (l + r) / 2, r));
    }
} seg;

int n;
vi g[MX];
int sz[MX];
int ok[MX];
int in[MX], out[MX];

void pre(int v, int p, int &k)
{
    sz[v] = 1;
    in[v] = k++;

    for (int to : g[v]) if (to != p) {
	pre(to, v, k);
	sz[v] += sz[to];
    }

    out[v] = k;

    if (sz[v] <= n / 2) seg.update(in[v], sz[v]);
}

void dfs(int v, int p, int cur)
{
    bool is = 0;

    if (v != 0 && n - sz[v] > n / 2) {
	is = 1;
    }

    bool is2 = 0;

    seg.update(in[v], INT_MIN);

    for (int to : g[v]) if (to != p) {
	int nc = cur;
	if (n - sz[to] <= n / 2) nc = max(nc, n - sz[to]);

	dfs(to, v, nc);

	if (sz[to] > n / 2) {
	    is2 = 1;
	    int m = sz[to];
	    int r = seg.get(in[to], out[to]);
	    if (r != INT_MIN && m - r <= n / 2) ok[v] = 1;
	}
    }

    if (!is && !is2) ok[v] = 1;
    else if (is) {
	int m = n - sz[v];
	int r = max(seg.get(0, in[v]), seg.get(out[v], n));
	if (r != INT_MIN && m - r <= n / 2) ok[v] = 1;
	if (cur != INT_MIN && m - cur <= n / 2) ok[v] = 1;
    }
    
    if (sz[v] <= n / 2) seg.update(in[v], sz[v]);
}

int main() {
    scanf("%d", &n);

    rep(i, n - 1) {
	int a, b;
	scanf("%d %d", &a, &b);
	--a; --b;
	g[a].pb(b);
	g[b].pb(a);
    }

    seg.init();
    int k = 0;
    pre(0, -1, k);
    dfs(0, -1, INT_MIN);

    rep(i, n) printf("%d%c", ok[i], i == n - 1 ? '\n' : ' ');

    return 0;
}