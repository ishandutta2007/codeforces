#include <bits/stdc++.h>

#ifndef LOCAL
#define cerr dolor_sit_amet
#endif

#define mp make_pair
#define sz(x) ((int)((x).size()))
#define X first
#define Y second
#define all(x) (x).begin(), (x).end()

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
const double PI = acos(-1.0);
const int DX[] = { 1,  0, -1,  0,  1, -1,  1, -1};
const int DY[] = { 0,  1,  0, -1,  1, -1, -1,  1};
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll sqr(ll x) { return x*x; } ll sqr(int x) { return (ll)x*x; }
double sqr(double x) { return x*x; } ld sqr(ld x) { return x*x; }
mt19937 mmtw(960172);
ll rnd(ll x, ll y) { static uniform_int_distribution<ll> d; return d(mmtw) % (y - x + 1) + x; }

// ========================================================================= //

const int N = 100179;

int n1;
int mm;
set<int> e[N];
bool deld[N];
int nr;
int w[N];
ll ans;

void del(int v) {
    assert(!deld[v] && sz(e[v]) == 1);
    int nv = *e[v].begin();
    e[v].clear();
    ans += 1LL * w[v] * (n1 - w[v]);
    w[nv] += w[v];
    w[v] = 0;
    deld[v] = 1;
    --nr;
    e[nv].erase(v);
    if (sz(e[nv]) == 1)
        del(nv);
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n1 >> mm;
    for (int i = 0; i < n1; ++i)
        w[i] = 1;
    for (int i = 0; i < mm; ++i) {
        int x, y;
        cin >> x >> y;
        --x;
        --y;
        e[x].insert(y);
        e[y].insert(x);
    }
    nr = n1;

    for (int i = 0; i < n1; ++i)
        if (!deld[i] && sz(e[i]) == 1)
            del(i);

    if (nr <= 1) {
        cout << ans << "\n";
        return 0;
    }

    vector<int> us;
    vector<int> uw;
    static int u2i[N];
    memset(u2i, -1, sizeof(u2i));
    int n = 0;
    for (int i = 0; i < n1; ++i)
        if (!deld[i] && sz(e[i]) >= 3) {
            us.push_back(i);
            u2i[i] = n++;
            uw.push_back(w[i]);
        }
    if (us.empty())
        for (int i = 0; i < n1; ++i)
            if (!deld[i]) {
                us.push_back(i);
                u2i[i] = n++;
                uw.push_back(w[i]);
                break;
            }

    struct Edge {
        int x, y;
        vector<int> ws;
        vector<ll> s1, s2;
        vector<ll> s;
        void init() {
            s1.resize(sz(ws) + 1, 0);
            s2.resize(sz(ws) + 1, 0);
            s.resize(sz(ws) + 1, 0);
            for (int i = 0; i < sz(ws); ++i)
                s[i + 1] = s[i] + ws[i];
            for (int i = 0; i < sz(ws); ++i)
                s1[i + 1] = s1[i] + 1LL * i * ws[i];
            for (int i = 0; i < sz(ws); ++i)
                s2[i + 1] = s2[i] + 1LL * (sz(ws) - 1 - i) * ws[i];
        }
    };
    vector<Edge> es;

    for (int u : us)
        while (!e[u].empty()) {
            es.emplace_back();
            Edge &ce = es.back();
            ce.x = u2i[u];
            int v = *e[u].begin();
            e[u].erase(v);
            e[v].erase(u);
            while (u2i[v] == -1) {
                ce.ws.push_back(w[v]);
                assert(sz(e[v]) == 1);
                int nv = *e[v].begin();
                e[v].erase(nv);
                e[nv].erase(v);
                v = nv;
            }
            ce.y = u2i[v];
            ce.init();
        }

    vector<vector<int>> d(n, vector<int>(n, IINF));
    for (int i = 0; i < n; ++i)
        d[i][i] = 0;
    for (Edge const& ce : es) {
        d[ce.x][ce.y] = min(d[ce.x][ce.y], sz(ce.ws) + 1);
        d[ce.y][ce.x] = min(d[ce.y][ce.x], sz(ce.ws) + 1);
    }
    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            ans += 1LL * uw[i] * uw[j] * d[i][j];

    for (int v = 0; v < n; ++v)
        for (Edge const& ce : es) {
            for (int i = 0; i < sz(ce.ws); ++i)
                ans += 1LL * uw[v] * ce.ws[i] * min(i + 1 + d[ce.x][v], d[ce.y][v] + (sz(ce.ws) - i));
            ll cans = 0;
            for (int i = 0; i < sz(ce.ws); ++i)
                cans += 1LL * uw[v] * ce.ws[i] * min(i + 1 + d[ce.x][v], d[ce.y][v] + (sz(ce.ws) - i));
        }

    for (Edge const& ce : es) {
        int d0 = d[ce.x][ce.y] + 2;
        int m = sz(ce.ws);
        for (int i = 0; i < m; ++i) {
            // j - i >= i + d0 + (m - 1 - j)
            // 2j >= 2i + d0 + m - 1
            int j = (2*i + d0 + sz(ce.ws)) / 2;
            j = min(j, sz(ce.ws));
            ans += (ce.s1[j] - ce.s1[i] - (ce.s[j] - ce.s[i]) * i) * ce.ws[i];
            ans += (ce.s2[m] - ce.s2[j] + (d0 + i) * (ce.s[m] - ce.s[j])) * ce.ws[i];
        }
    }

    for (int i1 = 0; i1 < sz(es); ++i1) {
        Edge const& e1 = es[i1];
        for (int i2 = i1 + 1; i2 < sz(es); ++i2) {
            Edge const& e2 = es[i2];
            int d00 = d[e1.x][e2.x] + 2;
            int d01 = d[e1.x][e2.y] + 2;
            int d10 = d[e1.y][e2.x] + 2;
            int d11 = d[e1.y][e2.y] + 2;
            int m1 = sz(e1.ws);
            int m2 = sz(e2.ws);
            for (int i = 0; i < m1; ++i) {
                int d0 = min(i + d00, m1 - 1 - i + d10);
                int d1 = min(i + d01, m1 - 1 - i + d11);
                // d0 + j >= d1 + (m2 - 1 - j)
                // 2j >= d1 - d0 + m2 - 1
                int j = (d1 - d0 + m2) / 2;
                j = max(j, 0);
                j = min(j, m2);
                ans += (1LL * (e2.s[j]) * d0 + e2.s1[j]) * e1.ws[i];
                ans += (1LL * (e2.s[m2]-e2.s[j]) * d1 + (e2.s2[m2] - e2.s2[j])) * e1.ws[i];
            }
        }
    }

    cout << ans << "\n";
    return 0;
}