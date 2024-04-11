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

const int N = 100179;

int n;
struct Shirt
{
    int p, c1, c2;
};
vector < Shirt > ss;
set < int > k[4];

int main()
{
    ios::sync_with_stdio(false);

    scanf("%d", &n);
    ss.resize(n);
    for (int i = 0; i < n; ++i) scanf("%d", &ss[i].p);
    for (int i = 0; i < n; ++i) scanf("%d", &ss[i].c1);
    for (int i = 0; i < n; ++i) scanf("%d", &ss[i].c2);
    sort(ss.begin(), ss.end(), [](auto const & a, auto const & b) { return a.p < b.p; });
    for (int i = 0; i < n; ++i)
    {
        k[ss[i].c1].insert(i);
        k[ss[i].c2].insert(i);
    }
    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; ++i)
    {
        int c;
        scanf("%d", &c);
        if (k[c].empty())
            cout << "-1 ";
        else
        {
            int v = *k[c].begin();
            cout << ss[v].p << " ";
            k[ss[v].c1].erase(v);
            k[ss[v].c2].erase(v);
        }
    }
    cout << "\n";
    return 0;
}