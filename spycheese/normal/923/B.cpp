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

int main() {
    int n;
    scanf("%d", &n);
    vector<ll> v(n), t(n), ts(n+1);
    for (int i = 0; i < n; ++i) {
        scanf("%lld", &v[i]);
    }
    ts[0] = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%lld", &t[i]);
        ts[i + 1] = ts[i] + t[i];
    }

    vector<ll> ans(n, 0);
    vector<int> acnt(n+1, 0);
    for (int i = 0; i < n; ++i) {
        int j = lower_bound(ALL(ts), ts[i] + v[i]) - ts.begin();
        if (j == sz(ts)) {
            acnt[i]++;
        } else if (ts[j] == ts[i] + v[i]) {
            acnt[i]++;
            acnt[j]--;
        } else {
            acnt[i]++;
            acnt[j-1]--;
            ans[j-1] += v[i] - (ts[j-1] - ts[i]);
        }
    }

    for (int i = 1; i <= n; ++i)
        acnt[i] += acnt[i - 1];
    for (int i = 0; i < n; ++i)
        cout << ans[i] + acnt[i] * t[i] << " ";
    cout << "\n";

    return 0;
}