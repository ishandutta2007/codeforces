#include <bits/stdc++.h>
#ifndef LOCAL
#   define cerr tick
#   define stderr tock
#endif
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define X first
#define Y second

using namespace std;

typedef long long ll;
typedef pair<int, int> ipair;
typedef long double ld;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;
mt19937 rnd(8130);

const int N = 500111;
const int D = 19;

struct SegTree {
    int n;
    vector<ll> t;
    void init(vector<pair<int, ll>> const& a) {
        if (a.empty())
            return;
        n = sz(a);
        t.resize(n * 4);
        build(a, 0, 0, n - 1);
    }
    void build(vector<pair<int, ll>> const& a, int c, int cl, int cr) {
        if (cl == cr)
            t[c] = a[cl].Y;
        else {
            build(a, c*2+1, cl, (cl+cr)/2);
            build(a, c*2+2, (cl+cr)/2 + 1, cr);
            t[c] = min(t[c*2+1], t[c*2+2]);
        }
    }
    ll getMin(int l, int r, int c, int cl, int cr) {
        if (l > cr || cl > r)
            return LINF;
        if (l <= cl && cr <= r)
            return t[c];
        return min(getMin(l, r, c*2+1, cl, (cl+cr)/2), getMin(l, r, c*2+2, (cl+cr)/2+1, cr));
    }
    ll getMin(int l, int r) { return getMin(l, r, 0, 0, n - 1); }
};

int n;
vector<ipair> e[N];
int dp[D][N], dep[N];

bool done[N];
int cParent[N], cLevel[N];
SegTree cST[N];
vector<pair<int, ll>> dists;
vector<int> cLeafs[N];
int ccsize;
int center;
ll ldist[D][N];
int curL;

int dfsC(int v, int p = -1) {
    int s = 1;
    for (ipair nv : e[v])
        if (p != nv.X && !done[nv.X])
            s += dfsC(nv.X, v);
    if (center == -1 && s * 2 > ccsize)
        center = v;
    return s;
}

void dfs3(int v, int p, ll cdist) {
    if (sz(e[v]) == 1)
        dists.push_back({v, cdist});
    ++ccsize;
    ldist[curL][v] = cdist;
    for (ipair nv : e[v])
        if (nv.X != p && !done[nv.X])
            dfs3(nv.X, v, cdist + nv.Y);
}

void build(int vv, int pv = -1, int level = 0) {
    center = -1;
    dfsC(vv);
    vv = center;
    cParent[vv] = pv;
    cLevel[vv] = level;
    curL = level;
    ldist[level][vv] = 0;
    vector<int> zzz;
    dists.clear();
    for (ipair nvp : e[vv]) {
        int nv = nvp.X;
        if (done[nv])
            continue;
        ccsize = 0;
        dfs3(nv, vv, nvp.Y);
        zzz.push_back(ccsize);
    }
    if (sz(e[vv]) == 1)
        dists.push_back({vv, 0});
    sort(all(dists));
    cST[vv].init(dists);
    for (auto const& p : dists)
        cLeafs[vv].push_back(p.X);
    done[vv] = 1;
    int ci = 0;
    for (ipair nvp : e[vv]) {
        int nv = nvp.X;
        if (done[nv])
            continue;
        ccsize = zzz[ci++];
        build(nv, vv, level + 1);
    }
}

void solve() {
    int n, qq;
    scanf("%d%d", &n, &qq);
    for (int i = 1; i < n; ++i) {
        int j, w;
        scanf("%d%d", &j, &w);
        --j;
        e[j].push_back({i, w});
        e[i].push_back({j, w});
    }

    memset(done, 0, sizeof(bool) * n);
    ccsize = n;
    build(0, -1);

    for (int i = 0; i < qq; ++i) {
        int v, l, r;
        scanf("%d%d%d", &v, &l, &r);
        --v;
        --l;
        int vc = v;
        int lev = cLevel[v];
        ll ans = LINF;
        while (vc != -1) {
            int cl = lower_bound(all(cLeafs[vc]), l) - cLeafs[vc].begin();
            int cr = lower_bound(all(cLeafs[vc]), r) - cLeafs[vc].begin();
            if (cl != cr) {
                ans = min(ans, ldist[lev][v] + cST[vc].getMin(cl, cr - 1));
            }
            vc = cParent[vc];
            --lev;
        }
        cout << ans << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);

    int tc = 1;
    for (int i = 0; i < tc; ++i)
        solve();
}