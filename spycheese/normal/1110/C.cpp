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

const int N = 100179;

vector<ipair> ans = {
    {3, 1},
    {7, 1},
    {15, 5},
    {31, 1},
    {63, 21},
    {127, 1},
    {255, 85},
    {511, 73},
    {1023, 341},
    {2047, 89},
    {4095, 1365},
    {8191, 1},
    {16383, 5461},
    {32767, 4681},
    {65535, 21845},
    {131071, 1},
    {262143, 87381},
    {524287, 1},
    {1048575, 349525},
    {2097151, 299593},
    {4194303, 1398101},
    {8388607, 178481},
    {16777215, 5592405},
    {33554431, 1082401}
};

int main() {
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int x;
        cin >> x;
        bool was = 0;
        for (ipair p : ans)
            if (p.X == x) {
                cout << p.Y << "\n";
                was = 1;
                break;
            }
        if (!was) {
            int y = 1;
            while (y < x)
                y = y*2 + 1;
            cout << y << "\n";
        }
    }

    return 0;
}