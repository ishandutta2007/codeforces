#include <bits/stdc++.h>

#ifndef LOCAL
#define cerr dolor_sit_amet
#endif

#define mp make_pair
#define sz(x) ((int)((x).size()))
#define X first
#define Y second
#define ALL(x) (x).begin(), (x).end()

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

const int N = 1 << 19;

int n, m;
vector<int> e[N];
vector<vector<int>> loops;

int vis[N], tt = 1;
int pred[N];

void dfs(int v, int p = -1) {
    vis[v] = tt++;
    pred[v] = p;
    for (int nv : e[v]) {
        if (nv == p)
            continue;
        if (vis[nv]) {
            if (vis[v] > vis[nv]) {
                loops.push_back({v});
                int x = v;
                do {
                    loops.back().push_back(x = pred[x]);
                } while (x != nv);
            }
        } else
            dfs(nv, v);
    }
}

vector<int> vinl[N];
vector<int> lcnt;
int lfull;
int w[N];
ll ans[N];

struct Event {
    int x;
    int y1, y2;
    int val;
    int ind;
};
vector<Event> es;

struct SegTree {
    ll ts[N*2-1], ta[N*2-1];
    ll sum(int l, int r, int c = 0, int cl = 0, int cr = N - 1) {
        if (l > cr || cl > r)
            return 0;
        if (l <= cl && cr <= r) {
            return ts[c];
        }
        int c1 = c*2+1, c2 = c*2+2;
        int mid = (cl+cr)/2;
        ts[c1] += ta[c] * (mid-cl+1);
        ta[c1] += ta[c];
        ts[c2] += ta[c] * (mid-cl+1);
        ta[c2] += ta[c];
        ta[c] = 0;
        return sum(l, r, c1, cl, mid) + sum(l, r, c2, mid+1, cr);
    }
    void inc(int l, int r, int c = 0, int cl = 0, int cr = N - 1) {
        if (l > cr || cl > r)
            return;
        if (l <= cl && cr <= r) {
            ts[c] += cr-cl+1;
            ++ta[c];
            return;
        }
        int c1 = c*2+1, c2 = c*2+2;
        int mid = (cl+cr)/2;
        ts[c1] += ta[c] * (mid-cl+1);
        ta[c1] += ta[c];
        ts[c2] += ta[c] * (mid-cl+1);
        ta[c2] += ta[c];
        ta[c] = 0;
        inc(l, r, c1, cl, mid);
        inc(l, r, c2, mid+1, cr);
        ts[c] = ts[c1] + ts[c2];
    }
} st;

int main() {
    ios::sync_with_stdio(false);

    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        --x;
        --y;
        e[x].push_back(y);
        e[y].push_back(x);
    }

    for (int i = 0; i < n; ++i)
        if (!vis[i])
            dfs(i);

    lcnt.resize(sz(loops));
    for (int i = 0; i < sz(loops); ++i) {
        lcnt[i] = sz(loops[i]);
        for (int v : loops[i])
            vinl[v].push_back(i);
    }

    int r = 0;
    for (int i = 0; i < n; ++i) {
        while (r < n && lfull == 0) {
            for (int j : vinl[r]) {
                if (--lcnt[j] == 0)
                    ++lfull;
            }
            ++r;
        }
        assert(r > i);
        if (lfull)
            w[i] = r - 1 - i;
        else
            w[i] = r - i;
        for (int j : vinl[i]) {
            if (++lcnt[j] == 1)
                --lfull;
        }
        es.push_back({i, i, i + w[i] - 1, 1, -1});
         }

    int qn;
    scanf("%d", &qn);
    for (int i = 0; i < qn; ++i) {
        int l, r;
        scanf("%d%d", &l, &r);
        --l;
        --r;
        es.push_back({l-1, l, r, -1, i});
        es.push_back({r, l, r, 1, i});
    }

    sort(ALL(es), [](Event const& a, Event const& b) {
        if (a.x != b.x)
            return a.x < b.x;
        return a.ind < b.ind;
    });

    for (Event const& e : es) {
        if (e.ind != -1) {
            ans[e.ind] += e.val * (st.sum(e.y1, e.y2));
        } else {
            st.inc(e.y1, e.y2);
        }
    }

    for (int i = 0; i < qn; ++i)
        cout << ans[i] << "\n";
    return 0;
}