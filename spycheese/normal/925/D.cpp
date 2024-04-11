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

const int N = 300179;

int n, m;
vector<int> e[N];
vector<int> ans;

void updAns(vector<int> const& a) {
    if (ans.empty() || sz(ans) > sz(a))
        ans = a;
}

void bfs() {
    static int p[N];
    memset(p, -1, sizeof(p));
    p[n - 1] = n - 1;
    vector<int> q = {n - 1};
    for (int i = 0; i < sz(q); ++i) {
        int v = q[i];
        for (int nv : e[v])
            if (p[nv] == -1) {
                p[nv] = v;
                q.push_back(nv);
            }
    }
    if (p[0] != -1) {
        vector<int> a;
        a.push_back(0);
        int v = 0;
        while (v != n - 1) {
            v = p[v];
            a.push_back(v);
        }
        updAns(a);
    }
}

bool vis[N];
vector<int> vs;
bool e0[N];

void dfs(int v) {
    if (vis[v] || !e0[v])
        return;
    vis[v] = 1;
    vs.push_back(v);
    for (int nv : e[v])
        dfs(nv);
}

int main() {
    ios::sync_with_stdio(false);
    scanf("%d%d", &n, &m);
    set<ipair> es;
    for (int i = 0; i < m; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        --x;
        --y;
        e[x].push_back(y);
        e[y].push_back(x);
        es.insert({min(x, y), max(x, y)});
    }

    bfs();

    for (int v : e[0])
        e0[v] = 1;
    bool was = 0;
    for (int v1 : e[0])
        for (int v2 : e[v1]) {
            if (v2 == 0)
                continue;
            if (!e0[v2]) {
                updAns({0, v1, v2, 0, n - 1});
                was = 1;
            }
        }

    if (!was && !e0[n - 1]) {
        for (int v = 1; v < n - 1; ++v) {
            if (!e0[v])
                continue;
            if (vis[v])
                continue;
            vs.clear();
            dfs(v);
            int v1 = -1, v2 = -1;
            sort(all(vs));
            for (int i = 0; i < sz(vs); ++i)
                for (int j = i + 1; j < sz(vs); ++j)
                    if (!es.count({vs[i], vs[j]})) {
                        v1 = vs[i];
                        v2 = vs[j];
                        goto bb;
                    }
            continue;
            bb:

            static int p[N];
            memset(p, -1, sizeof(p));
            p[v1] = v1;
            vector<int> q = {v1};
            for (int i = 0; i < sz(q); ++i) {
                int v = q[i];
                for (int nv : e[v])
                    if (p[nv] == -1 && e0[nv]) {
                        p[nv] = v;
                        q.push_back(nv);
                    }
            }
            assert(p[v2] != -1);
            assert(p[v2] != v1);
            updAns({0, p[p[v2]], p[v2], v2, p[p[v2]], n - 1});
            break;
        }
    }

    if (ans.empty())
        cout << "-1\n";
    else {
        cout << sz(ans) - 1 << "\n";
        for (int x : ans)
            cout << x + 1 << " ";
        cout << "\n";
    }

    return 0;
}