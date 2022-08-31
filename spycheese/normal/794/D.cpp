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
const ll MOD = 1000000007;
const double EPS = 1e-9;
const int DX[] = { 1,  0, -1,  0,  1, -1,  1, -1};
const int DY[] = { 0,  1,  0, -1,  1, -1, -1,  1};
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll sqr(ll x) { return x*x; } ll sqr(int x) { return (ll)x*x; }
double sqr(double x) { return x*x; } ld sqr(ld x) { return x*x; }

// ========================================================================= //

const int N = 300179;

int n, m;
vector < int > e[N];
set < ipair > es;
map < vector < int > , int > e2i;
int ic = 0;
int vi[N];
vector < int > e1[N];
int i2a[N];

int a1 = 1;
unordered_map < int, vector < int > > a2v;

void dfs(int v)
{
    if (i2a[v] != -1)
        return;
    i2a[v] = a1++;
    for (int nv : e1[v])
        dfs(nv);
}

int main()
{
    ios::sync_with_stdio(false);

    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        --x;
        --y;
        e[x].push_back(y);
        e[y].push_back(x);
        es.insert({min(x, y), max(x, y)});
    }
    for (int i = 0; i < n; ++i)
    {
        e[i].push_back(i);
        sort(e[i].begin(), e[i].end());
        auto it = e2i.find(e[i]);
        if (it == e2i.end())
            vi[i] = (e2i[e[i]] = ic++);
        else
            vi[i] = it->second;
    }

    for (int v = 0; v < n; ++v)
        for (int nv : e[v])
            if (vi[v] != vi[nv])
            {
                e1[vi[v]].push_back(vi[nv]);
                e1[vi[nv]].push_back(vi[v]);
            }
    memset(i2a, -1, sizeof(i2a));

    for (int i = 0; i < ic; ++i)
    {
        if (i2a[i] != -1)
            continue;
        set < int > e1s(e1[i].begin(), e1[i].end());
        if (sz(e1s) <= 1)
            dfs(i);
        a1 += 2;
    }
    for (int i = 0; i < ic; ++i)
        if (i2a[i] == -1)
        {
            cout << "NO\n";
            return 0;
        }

    for (int i = 0; i < n; ++i)
        a2v[i2a[vi[i]]].push_back(i);

    ll cm = 0;
    for (auto const & x : a2v)
    {
        cm += 1LL * sz(x.Y) * (sz(x.Y) - 1) / 2;
        if (a2v.count(x.X - 1))
            cm += 1LL * sz(x.Y) * sz(a2v[x.X - 1]);
    }
    if (cm != m)
    {
        cout << "NO\n";
        return 0;
    }
    for (auto const & x : a2v)
    {
        for (int v1 : x.Y)
            for (int v2 : x.Y)
                if (v1 != v2 && !es.count({min(v1, v2), max(v1, v2)}))
                {
                    cout << "NO\n";
                    return 0;
                }
        if (a2v.count(x.X - 1))
            for (int v1 : x.Y)
                for (int v2 : a2v[x.X - 1])
                    if (v1 != v2 && !es.count({min(v1, v2), max(v1, v2)}))
                    {
                        cout << "NO\n";
                        return 0;
                    }
    }

    cout << "YES\n";
    for (int i = 0; i < n; ++i)
        cout << i2a[vi[i]] << " ";
    cout << "\n";
    
    return 0;
}