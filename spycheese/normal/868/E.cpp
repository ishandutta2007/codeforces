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

const int N = 52;

int n;
int start;
int pcnt[N];
vector < ipair > e[N];

int d[N][N][N][N];

void dfs1(int v, int p = -1) {
    for (ipair nv : e[v])
        if (nv.X != p) {
            dfs1(nv.X, v);
            pcnt[v] += pcnt[nv.X];
        }
}

int dfs2(int v, int p, int cm, int tm) {
    int &cdd = d[v][p+1][cm][tm];
    if (cdd != -1)
        return cdd;

    if (cm == 0) {
        return cdd = 0;
    }

    if (tm == 0) {
        return cdd = IINF;
    }

    if (p != -1 && sz(e[v]) == 1) {
        return cdd = dfs2(v, -1, cm - tm, cm - tm);
    }

    vector < vector < int > > d1;
    for (ipair nv : e[v]) {
        if (nv.X == p) {
            continue;
        }
        d1.emplace_back(tm + 1, 0);
        d1.back()[0] = -IINF;
        for (int i = 1; i <= tm; ++i)
            d1.back()[tm-i+1] = nv.Y + dfs2(nv.X, v, cm, i);
    }

    /*cerr << "!!!!!!!!!!!!!!!!!\n";
    cerr << tm << "\n";
    for (auto xx : d1) {
        for (int x : xx)
            cerr << " " << x;
        cerr << "\n";
    }*/

    priority_queue < ipair > z;
    vector < int > tops(sz(d1), IINF);
    for (int i = 0; i < sz(d1); ++i) {
        z.push({d1[i].back(), i});
    }
    for (int i = 0; i < tm; ++i) {
        int x = z.top().Y;
        tops[x] = z.top().X;
        z.pop();
        d1[x].pop_back();
        z.push({d1[x].back(), x});
    }
    int aa = IINF;
    for (int xx : tops)
        aa = min(aa, xx);
    //cerr << aa << "\n\n";
    return cdd = aa;
}

int main() {
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i < n; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        --x;
        --y;
        e[x].push_back({y, z});
        e[y].push_back({x, z});
    }

    cin >> start;
    --start;
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int x;
        cin >> x;
        --x;
        ++pcnt[x];
    }

    dfs1(start);

    memset(d, -1, sizeof(d));

    int ans = IINF;
    for (ipair nv : e[start])
        ans = min(ans, nv.Y + dfs2(nv.X, start, m, pcnt[nv.X]));
    cout << ans << "\n";

    return 0;
}