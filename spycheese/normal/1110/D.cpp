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

const int N = 1000179;

int n, m;
int a[N];
int d[N][5][3];

int main() {
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        ++a[x + 10];
    }

    for (int i = 5; i < N; ++i)
        for (int a0 = 0; a0 < 5; ++a0)
            for (int a1 = 0; a1 < 3; ++a1) {
                if (a[i] - a0 < 0 || a[i-1] - a1 < 0)
                    continue;
                d[i][a0][a1] = 0;
                for (int t = 0; t <= min({a[i] - a0, 2, a[i-1] - a1, a[i-2]}); ++t) {
                    d[i][a0][a1] = max(d[i][a0][a1], d[i-1][a1 + t][t] + t + (a[i] - a0 - t) / 3);
                }
            }

    cout << d[N-1][0][0] << "\n";

    return 0;
}