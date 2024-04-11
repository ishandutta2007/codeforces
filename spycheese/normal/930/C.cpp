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

vector<int> solve(vector<int> a) {
    int n = sz(a);
    vector<int> res(n+1);
    vector<int> d(n + 1, IINF);
    d[0] = -IINF;

    vector<ipair> aa;
    for (int i = 0; i < n; ++i)
        aa.push_back({a[i], i});
    sort(ALL(aa));
    for (int i = 0; i < n; ++i)
        a[i] = lower_bound(ALL(aa), ipair(a[i], i)) - aa.begin();
     
    res[0] = 0;
    for (int i = 0; i < n; i++) {
        int j = upper_bound(ALL(d), a[i]) - d.begin();
        res[i + 1] = res[i];
        if (d[j-1] < a[i] && a[i] < d[j]) {
            d[j] = a[i];
            res[i + 1] = max(res[i + 1], j);
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<int> a(m, 0), b(m, 0);
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        --x;
        a[x]++;
        if (y != m)
            a[y]--;
    }
    for (int i = 0; i < m; ++i) {
        if (i != 0)
            b[i] = b[i - 1];
        b[i] += a[i];
    }

    vector<int> d1 = solve(b);
    reverse(ALL(b));
    vector<int> d2 = solve(b);

    int ans = 1;
    for (int i = 0; i <= m; ++i)
        ans = max(ans, d1[i] + d2[m-i]);
    cout << ans << "\n";

    return 0;
}