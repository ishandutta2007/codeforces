#include <bits/stdc++.h>

#ifndef LOCAL
#define cerr dolor_sit_amet
#endif

#define mp make_pair
#define sz(x) ((int)((x).size()))
#define X first
#define Y second

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair < int , int > ipair;
typedef pair < ll , ll > lpair;
const int IINF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const double DINF = numeric_limits<double>::infinity();
const int MOD = 1000000007;
const double EPS = 1e-9;
const int DX[] = { 1,  0, -1,  0,  1, -1,  1, -1};
const int DY[] = { 0,  1,  0, -1,  1, -1, -1,  1};
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll sqr(ll x) { return x*x; } ll sqr(int x) { return (ll)x*x; }
double sqr(double x) { return x*x; } ld sqr(ld x) { return x*x; }
mt19937 mmtw(960172);
ll rnd(ll x, ll y) { static uniform_int_distribution<ll> d; return d(mmtw) % (y - x + 1) + x; }

// ========================================================================= //

const int N = 500179;
const int D = 19;

struct SegTree {
    vector < ll > tadd, tsum;
    int n;
    void init(int nn) {
        n = nn;
        tadd.resize(n*4);
        tsum.resize(n*4);
    }
    void add(int r) {
        add(r, 0, 0, n-1);
    }
    void add(int r, int c, int cl, int cr) {
        if (r < cl)
            return;
        if (r >= cr) {
            ++tadd[c];
            tsum[c] += cr-cl+1;
            return;
        }
        int mid = (cl+cr)/2;
        if (tadd[c]) {
            tadd[c*2+1] += tadd[c];
            tadd[c*2+2] += tadd[c];
            tsum[c*2+1] += tadd[c]*(mid-cl+1);
            tsum[c*2+2] += tadd[c]*(cr-mid);
            tadd[c] = 0;
        }
        add(r, c*2+1, cl, mid);
        add(r, c*2+2, mid+1, cr);
        tsum[c] = tsum[c*2+1] + tsum[c*2+2];
    }
    ll sum(int r) {
        return sum(r, 0, 0, n-1);
    }
    ll sum(int r, int c, int cl, int cr) {
        if (r < cl)
            return 0;
        if (r >= cr) {
            return tsum[c]; 
        }
        int mid = (cl+cr)/2;
        int ml = cr-mid;
        if (tadd[c]) {
            tadd[c*2+1] += tadd[c];
            tadd[c*2+2] += tadd[c];
            tsum[c*2+1] += tadd[c]*(mid-cl+1);
            tsum[c*2+2] += tadd[c]*(cr-mid);
            tadd[c] = 0;
        }
        return sum(r, c*2+1, cl, mid) + sum(r, c*2+2, mid+1, cr);
    }
};

struct Path {
    int start, end;
    int len;
    SegTree st;
    Path(int v) : start(v), end(v), len(1) {}
    void init() {
        st.init(len);
    }
};
vector < Path > paths;

int n;
vector < int > e[N];
int dep[N], dp[N];
int v2p[N];

int dfs1(int v, int cdep = 0, int p = -1) {
    int tsize = 1;
    dep[v] = cdep;
    dp[v] = p;
    int maxSize = -1, maxV = -1;
    for (int i = 0; i < sz(e[v]); ++i) {
        int nv = e[v][i];
        if (nv == p) {
            e[v][i] = e[v].back();
            e[v].pop_back();
            --i;
            continue;
        }
        int csize = dfs1(nv, cdep + 1, v);
        if (csize > maxSize) {
            maxSize = csize;
            maxV = i;
        }
        tsize += csize;
    }
    if (maxV != -1)
        swap(e[v][maxV], e[v][0]);
    return tsize;
}

void dfs2(int v, int cp) {
    if (cp == -1) {
        cp = sz(paths);
        paths.emplace_back(v);
    } else {
        ++paths[cp].len;
        paths[cp].end = v;
    }
    v2p[v] = cp;
    for (int nv : e[v]) {
        dfs2(nv, cp);
        cp = -1;
    }
}

ll w[N];

void inc(int v) {
    while (v != -1) {
        Path & p = paths[v2p[v]];
        int pos = dep[v] - dep[p.start];
        p.st.add(pos);
        v = dp[p.start];
    }
}
ll getSum(int v) {
    ll s = 0;
    while (v != -1) {
        Path & p = paths[v2p[v]];
        int pos = dep[v] - dep[p.start];
        s += p.st.sum(pos);
        v = dp[p.start];
    }
    return s;
}

void buildHL(int r) {
    dfs1(r);
    dfs2(r, -1);
    for (auto & p : paths)
        p.init();
}

int main() {
    ios::sync_with_stdio(false);

    scanf("%d", &n);
    int root = 0;
    for (int i = 0; i < n; ++i) {
        int pp;
        scanf("%d", &pp);
        --pp;
        if (pp < 0)
            root = i;
        else
            e[pp].push_back(i);
    }

    buildHL(root);
    static vector < int > deps[N];
    static ll ans[N];
    for (int i = 0; i < n; ++i)
        deps[dep[i]].push_back(i);

    for (int d = 0; d < n; ++d) {
        for (int v : deps[d])
            inc(v);
        for (int v : deps[d])
            ans[v] = getSum(v) - dep[v] - 1;
    }
    for (int i = 0; i < n; ++i)
        cout << ans[i] << " ";
    cout << "\n";

    return 0;
}