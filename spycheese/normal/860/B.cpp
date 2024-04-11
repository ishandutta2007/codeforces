#include <bits/stdc++.h>

#ifndef LOCAL
#define cerr dolor_sit_amet
#endif

#define mp make_pair
#define sz(x) ((int)((x).size()))
#define X first
#define Y second

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

const int N = 70777;

int n;
char c[N][15];
unordered_map < int, int > w[10];

int main() {
    ios::sync_with_stdio(false);

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%s", c[i]);
        for (int len = 1; len <= 9; ++len) {
            unordered_set<int> h;
            for (int k = 0; k + len <= 9; ++k) {
                int x = 0;
                for (int j = 0; j < len; ++j)
                    x = x*10 + (c[i][k+j]-'0');
                h.insert(x);
            }
            for (int x : h)
                ++w[len][x];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int len = 1; len <= 9; ++len) {
            for (int k = 0; k + len <= 9; ++k) {
                int x = 0;
                for (int j = 0; j < len; ++j)
                    x = x*10 + (c[i][k+j]-'0');
                if (w[len][x] == 1) {
                    for (int j = 0; j < len; ++j)
                        cout << c[i][j+k];
                    cout << "\n";
                    goto ook;
                }
            }
        }
        ook:;
    }

    return 0;
}