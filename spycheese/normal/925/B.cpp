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

pair<vector<int>, vector<int>> solve(vector<ipair> const& a, int x1, int x2) {
    int n = sz(a);
    int c1 = 1;
    while (c1 <= n && x1 > 1LL * c1 * a[c1-1].X)
        ++c1;
    if (c1 >= n)
        return {{}, {}};
    int c2 = 1;
    while (c1 + c2 <= n && x2 > 1LL * c2 * a[c1 + c2 - 1].X)
        ++c2;
    if (c1 + c2 >= n + 1)
        return {{}, {}};
    vector<int> k1, k2;
    for (int i = 0; i < c1; ++i)
        k1.push_back(a[i].Y);
    for (int i = 0; i < c2; ++i)
        k2.push_back(a[c1 + i].Y);
    sort(all(k1));
    sort(all(k2));
    return {k1, k2};
}

int main() {
    int n, x1, x2;
    scanf("%d%d%d", &n, &x1, &x2);
    vector<ipair> a(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i].X);
        a[i].Y = i;
    }

    sort(all(a), greater<ipair>());

    auto s = solve(a, x1, x2);
    if (!s.X.empty()) {
        cout << "Yes\n";
        cout << sz(s.X) << " " << sz(s.Y) << "\n";
        for (int x : s.X)
            cout << x + 1 << " ";
        cout << "\n";
        for (int x : s.Y)
            cout << x + 1 << " ";
        cout << "\n";
        return 0;
    }
    s = solve(a, x2, x1);
    if (!s.X.empty()) {
        cout << "Yes\n";
        swap(s.X, s.Y);
        cout << sz(s.X) << " " << sz(s.Y) << "\n";
        for (int x : s.X)
            cout << x + 1 << " ";
        cout << "\n";
        for (int x : s.Y)
            cout << x + 1 << " ";
        cout << "\n";
        return 0;
    }

    cout << "No\n";

    return 0;
}