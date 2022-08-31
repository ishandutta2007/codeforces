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

const int N = 200179;

int n;
vector < int > e[N];
struct Tree {
    int root;
    int curRoot;
    int par;
    vector < ipair > vs;
};
vector < Tree > trees;

struct Triple {
    int x, y, z;
};
vector < Triple > ans;

int c1 = -1, c2 = -1;

int dfs1(int v, int p = -1) {
    int s = 1;
    for (int nv : e[v])
        if (nv != p)
            s += dfs1(nv, v);
    if (c1 == -1 && s*2 >= n) {
        c1 = v;
        if (s * 2 == n)
            c2 = p;
        else
            c2 = -1;
    }
    return s;
}

void dfs2(int v, int p) {
    for (int nv : e[v])
        if (nv != p)
            dfs2(nv, v);
    trees.back().vs.push_back({v, p});
}

int main()
{
    ios::sync_with_stdio(false);

    scanf("%d", &n);
    for (int i = 0; i < n - 1; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        --x;
        --y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    if (n <= 3) {
        cout << "0\n";
        return 0;
    }

    dfs1(0);
    for (int nv : e[c1]) {
        if (nv == c2)
            continue;
        trees.emplace_back();
        trees.back().root = nv;
        trees.back().curRoot = nv;
        trees.back().par = c1;
        dfs2(nv, c1);
    }
    if (c2 != -1) {
        for (int nv : e[c2]) {
            if (nv == c1)
                continue;
            trees.emplace_back();
            trees.back().root = nv;
            trees.back().curRoot = nv;
            trees.back().par = c2;
            dfs2(nv, c2);
        }
    }

    for (Tree &tree : trees) {
        for (ipair pp : tree.vs) {
            int v = pp.X, p = pp.Y;
            if (v == tree.root)
                break;
            ans.push_back({tree.par, tree.curRoot, v});
            tree.curRoot = v;
            ans.push_back({v, p, tree.root});
        }
        ans.push_back({tree.par, tree.curRoot, tree.root});
    }

    cout << sz(ans) << "\n";
    for (Triple t : ans)
        cout << t.x+1 << " " << t.y+1 << " " << t.z+1 << "\n";

    return 0;
}