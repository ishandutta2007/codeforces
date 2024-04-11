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

const int N = 100179;

int n, m;
int a[16];

int main() {
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        int z = 0;
        for (int j = 0; j < m; ++j) {
            int x;
            cin >> x;
            z <<= 1;
            z += x;
        }
        a[z]++;
    }

    if (a[0]) {
        cout << "YES\n";
        return 0;
    }

    for (int x = 0; x < 16; ++x) {
        if (!a[x])
            continue;
        for (int y = 0; y < 16; ++y) {
            if (!(a[y] - (y == x)))
                continue;
            bool ok = true;
            for (int i = 0; i < 4; ++i)
                if ((((x>>i)&1) + ((y>>i)&1)) > 1) {
                    ok = false;
                    break;
                }
            if (ok) {
                cout << "YES\n";
                return 0;
            }
        }
    }
    for (int x = 0; x < 16; ++x) {
        if (!a[x])
            continue;
        for (int y = 0; y < 16; ++y) {
            if (!(a[y] - (y == x)))
                continue;
            for (int z = 0; z < 16; ++z) {
                if (!(a[z] - (z == y) - (z == x)))
                    continue;
                bool ok = true;
                for (int i = 0; i < 4; ++i)
                    if ((((x>>i)&1) + ((y>>i)&1) + ((z>>i)&1)) > 1) {
                        ok = false;
                        break;
                    }
                if (ok) {
                    cout << "YES\n";
                    return 0;
                }
            }
        }
    }

    cout << "NO\n";

    return 0;
}