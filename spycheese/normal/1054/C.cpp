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

const int N = 1011;

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    static int al[N], ar[N];
    for (int i = 0; i < n; ++i)
        cin >> al[i];
    for (int i = 0; i < n; ++i)
        cin >> ar[i];

    static ipair aa[N];
    for (int i = 0; i < n; ++i)
        aa[i] = {al[i] + ar[i], i};
    sort(aa, aa + n, greater<ipair>());
    static int val[N];
    int cur = 0;
    for (int i = 0; i < n; ++i) {
        if (i == 0 || aa[i].X != aa[i-1].X)
            ++cur;
        val[aa[i].Y] = cur;
    }

    for (int i = 0; i < n; ++i) {
        int cl = 0, cr = 0;
        for (int j = 0; j < i; ++j)
            if (val[j] > val[i])
                ++cl;
        for (int j = i + 1; j < n; ++j)
            if (val[j] > val[i])
                ++cr;
        if (al[i] != cl || ar[i] != cr) {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";
    for (int i = 0; i < n; ++i)
        cout << val[i] << " ";
    cout << "\n";

    return 0;
}