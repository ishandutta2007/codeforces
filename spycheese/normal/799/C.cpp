#include <bits/stdc++.h>

#ifndef LOCAL
#define cerr dolor_sit_amet
#endif

#define mp make_pair
#define sz(x) ((int)((x).size()))
#define price first
#define beauty second

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

int w1, w2;
vector < ipair > f1, f2;

int solve(vector < ipair > f, int w)
{
    sort(f.begin(), f.end());
    vector < int > mb = {-IINF};
    for (ipair c : f)
        mb.push_back(max(mb.back(), c.beauty));

    int ans = -IINF;
    for (int i = 1; i < sz(f); ++i)
    {
        int pr = f[i].price;
        int j = upper_bound(f.begin(), f.end(), ipair(w - pr, IINF)) - f.begin();
        j = min(j, i);
        ans = max(ans, f[i].beauty + mb[j]);
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);

    int n;
    scanf("%d%d%d", &n, &w1, &w2);
    for (int i = 0; i < n; ++i)
    {
        int b, p;
        char ss[5];
        scanf("%d%d%s", &b, &p, ss);
        (ss[0] == 'C' ? f1 : f2).emplace_back(p, b);
    }

    int ans1 = -IINF, ans2 = -IINF;
    for (ipair x : f1)
        if (x.price <= w1)
            ans1 = max(ans1, x.beauty);
    for (ipair x : f2)
        if (x.price <= w2)
            ans2 = max(ans2, x.beauty);
    int ans = ans1 + ans2;

    ans = max(ans, solve(f1, w1));
    ans = max(ans, solve(f2, w2));
    cout << max(ans, 0) << "\n";

    return 0;
}