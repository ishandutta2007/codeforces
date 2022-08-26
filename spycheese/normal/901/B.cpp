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

const int N = 155;

vector<int> a[N];

int main() {
    ios::sync_with_stdio(false);

    a[0] = {1};
    a[1] = {0, 1};
    for (int i = 2; i < N; ++i) {
        a[i] = a[i - 1];
        a[i].insert(a[i].begin(), 0);
        bool okp = true, okn = true;
        for (int j = 0; j < sz(a[i]) - 2; ++j) {
            if (abs(a[i][j] + a[i-2][j]) > 1)
                okp = false;
            if (abs(-a[i][j] + a[i-2][j]) > 1)
                okn = false;
        }
        assert(okp || okn);
        if (!okp)
            for (int &x : a[i])
                x = -x;
        for (int j = 0; j < sz(a[i]) - 2; ++j)
            a[i][j] += a[i-2][j];
        if (a[i].back() == -1)
            for (int &x : a[i])
                x = -x;
    }

    int n;
    cin >> n;
    cout << n << "\n";
    for (int i = 0; i <= n; ++i)
        cout << a[n][i] << " ";
    cout << "\n";
    cout << n - 1 << "\n";
    for (int i = 0; i <= n - 1; ++i)
        cout << a[n - 1][i] << " ";
    cout << "\n";

    return 0;
}