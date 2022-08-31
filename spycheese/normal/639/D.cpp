#include <bits/stdc++.h>

#ifndef LOCAL
#define cerr dolor_sit_amet
#endif

#define mp make_pair
#define sz(x) ((int)((x).size()))

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

// ========================================================================= //

const int N = 200179;

int n, k;
ll b, c, x[N];
ll s[5][N];
int sc[5][N];

multiset < ll > ts;
ll tss = 0;

void tsInsert(ll a)
{
    ts.insert(a);
    tss += a;
    if (sz(ts) > k)
    {
        auto it = ts.end();
        --it;
        tss -= *it;
        ts.erase(it);
    }
}

int main()
{
    ios::sync_with_stdio(false);

    cin >> n >> k >> b >> c;
    b = min(b, c * 5);
    for (int i = 0; i < n; ++i)
    {
        cin >> x[i];
        x[i] += MOD;
    }
    sort(x, x + n);

    ll ans = LINF;
    for (int vr = 0; vr < 5; ++vr)
    {
        ts.clear();
        tss = 0;
        for (int i = 0; i < n; ++i)
        {
            int x5 = (x[i] % 5 + 5) % 5;
            ll v = (x5 <= vr ? x[i] + (vr - x5) : 5 + x[i] + (vr - x5));
            ll a = (v - x[i]) * c - v / 5 * b;
            tsInsert(a);
            if (sz(ts) == k)
                ans = min(ans, tss + k*((v/5)*b));
        }
    }
    cout << ans << "\n";

    return 0;
}