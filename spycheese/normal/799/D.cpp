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

int solve(vector < int > a, int s1, int s2)
{
    if (s1 == 1 && s2 == 1)
        return 0;
    vector < int > d(s1 + 1, -IINF), nd(s1 + 1);
    d[1] = 1;
    int ii = 0;
    for (int x : a)
    {
        fill(nd.begin(), nd.end(), -IINF);
        for (int i = s1; i >= 1; --i)
        {
            if (d[i] == -IINF)
                continue;
            int ni = (int)min<ll>(s1, 1LL*i*x);
            nd[ni] = max(nd[ni], d[i]);
            nd[i] = max(nd[i], (int)min<ll>(s2, 1LL*d[i]*x));
        }
        swap(d, nd);
        ++ii;
        if (d[s1] >= s2)
            return ii;
    }
    return IINF;
}

int solve(int rsx, int rsy, int sx, int sy, vector < int > const & a)
{
    return solve(a, (rsx - 1) / sx + 1, (rsy - 1) / sy + 1);
}

int main()
{
    ios::sync_with_stdio(false);

    int rsx, rsy, sx, sy, n;
    scanf("%d%d%d%d%d", &rsx, &rsy, &sx, &sy, &n);
    vector < int > a(n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    sort(a.begin(), a.end(), greater<int>());
    if (sz(a) > 34)
        a.resize(34);
    int ans = min(solve(rsx, rsy, sx, sy, a), solve(rsx, rsy, sy, sx, a));
    if (ans > n)
        ans = -1;
    cout << ans << "\n";

    return 0;
}