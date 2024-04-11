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

template<typename T> T& updMin(T& a, T const& b) { if (b < a) a = b; return a; }
template<typename T> T& updMax(T& a, T const& b) { if (a < b) a = b; return a; }

// ========================================================================= //

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    int s1 = 0, s2 = 0, p = 0;
    int i1 = 0, i2 = n - 1;
    int cnt = 0;
    while (true) {
        if (i1 > i2) break;
        {
            ++cnt;
            int c = 0;
            while (i1 <= i2 && c <= p) c += a[i1++];
            s1 += c;
            p = c;
        }
        if (i1 > i2) break;
        {
            ++cnt;
            int c = 0;
            while (i1 <= i2 && c <= p) c += a[i2--];
            s2 += c;
            p = c;
        }
    }
    cout << cnt << " " << s1 << " " << s2 << "\n";
}

int main() {
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) solve();

    return 0;
}