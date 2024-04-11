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

ll foo(ll x) {
    return x*(x-1) / 2;
}

int main() {
    ios::sync_with_stdio(false);

    int n, k;
    scanf("%d%d", &n, &k);
    int kk = (1 << k) - 1;
    map<int, int> cnt;
    int cur = 0;
    cnt[cur]++;
    for (int i = 0; i < n; ++i) {
        int a;
        scanf("%d", &a);
        cur ^= a;
        cnt[min(cur, cur ^ kk)]++;
    }

    ll ans = 0;
    for (auto pp : cnt) {
        ll x = pp.Y;
        if (x % 2 == 0)
            ans += foo(x / 2) * 2;
        else
            ans += foo(x / 2) + foo(x / 2 + 1);
    }
    cout << n*(n+1LL)/2LL -  ans << "\n";

    return 0;
}