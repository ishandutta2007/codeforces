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

int sz;

struct segtree_max {
    vector<int> dat;

    void init(int n_) {
	sz = 1;
	while(sz < n_) sz *= 2;
	dat.resize(sz * 2);
	rep(i, sz * 2) dat[i] = -1;
    }

    void update(int pos, int x) {
	pos += sz - 1;
	dat[pos] = x;

	while (pos) {
	    pos = (pos - 1) / 2;
	    dat[pos] = max(dat[pos * 2 + 1], dat[pos * 2 + 2]);
	}
    }

    int get(int a, int b, int k = 0, int l = 0, int r = sz) {
	if (b <= l || r <= a) return -1;
	if (a <= l && r <= b) return dat[k];
	return max(get(a, b, k * 2 + 1, l, (l + r) / 2), get(a, b, k * 2 + 2, (l + r) / 2, r));
    }
} seg;

typedef long double R;
typedef pair<pii, R> Data;

bool cmp(const Data &a, const Data &b)
{
    if (a.fi.fi == b.fi.fi) return a.fi.se > b.fi.se;
    return a.fi.fi < b.fi.fi;
}

int n, q;
int a[100010];
Data qr[5010];
bool vis[5010];
R dp[5010][5010];
int mx[5010];

void dfs(int v)
{
    vector<int> ch;
    vis[v] = 1;

    for (int i = v + 1; i < q; ++i) {
	if (!vis[i] && qr[v].fi.fi <= qr[i].fi.fi && qr[v].fi.se >= qr[i].fi.se) {
	    dfs(i);
	    ch.pb(i);
	}
    }

    for (int j = 0; j <= q; ++j) dp[v][j] = 1.0;

    for (int j = 0; j <= q; ++j) {
	for (int to : ch) {
	    int dif = mx[v] - mx[to] + j;

	    if (dif <= q) {
		dp[v][j] *= dp[to][dif];
	    }
	}
    }

    for (int j = q; j >= 0; --j) {
	dp[v][j] *= 1.0 - qr[v].se;
	if (j) dp[v][j] += dp[v][j-1] * qr[v].se;
    }    
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> q;
    seg.init(n);

    rep(i, n) {
	cin >> a[i];
	seg.update(i, a[i]);
    }

    rep(i, q) {
	int l, r; R p;
	cin >> l >> r >> p;
	--l; --r;
	qr[i] = mp(mp(l, r), p);
    }

    qr[q++] = mp(mp(0, n-1), 0);

    sort(qr, qr + q, cmp);

    rep(i, q) mx[i] = seg.get(qr[i].fi.fi, qr[i].fi.se + 1);    

    dfs(0);

    R ret = mx[0];

    for (int i = 1; i <= q; ++i) 
	ret += (R)i  * (dp[0][i] - dp[0][i-1]);

    cout << fixed << setprecision(7) << ret << endl;
    return 0;
}