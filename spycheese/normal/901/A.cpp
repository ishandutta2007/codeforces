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

const int N = 200179;

int h;
int a[N];
int as[N];

int main() {
    ios::sync_with_stdio(false);

    cin >> h;
    for (int i = 0; i <= h; ++i)
        cin >> a[i];
    for (int i = 0; i <= h; ++i)
        as[i + 1] = as[i] + a[i];
    for (int i = 0; i < h; ++i)
        if (a[i] > 1 && a[i+1] > 1) {
            cout << "ambiguous\n";
            for (int j = 0; j <= h; ++j) {
                for (int k = 0; k < a[j]; ++k) {
                    cout << (j == 0 ? 0 : as[j-1] + 1) << " ";
                }
            }
            cout << "\n";
            for (int j = 0; j <= h; ++j) {
                for (int k = 0; k < a[j]; ++k) {
                    cout << (j == 0 ? 0 : as[j-1] + k % a[j-1] + 1) << " ";
                }
            }
            cout << "\n";
            return 0;
        }
    cout << "perfect\n";

    return 0;
}