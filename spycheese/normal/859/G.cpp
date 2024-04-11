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

const int N = 100179;

bool solve(int n, vector<int>const&ps, vector<ll> a) {
    vector < int > cs(sz(ps));
    for (int i = 0; i < n; ++i) {
        int ci = i;
        for (int j = sz(ps)-1; j >= 0; --j) {
            cs[j] = ci % ps[j];
            ci /= ps[j];
        }
        int f = -1;
        for (int j = 0; j < sz(ps); ++j)
            if (cs[j] == 0) {
                f = j;
                break;
            }
        if (f == -1)
            continue;
        int p = ps[f];
        int x = 0;
        for (int j = 0; j < sz(ps); ++j)
            x += (n/ps[j]) * cs[j];
        x %= n;
        int w = a[x];
        int np = n / p;
        for (int j = 0; j < p; ++j) {
            a[x] -= w;
            x += np;
            if (x >= n)
                x -= n;
        }
    }

    for (int i = 0; i < n; ++i)
        if (a[i]) {
            return 0;
        }
    return 1;
}

int main()
{
    ios::sync_with_stdio(false);
    int n;
    string s;
    cin >> n >> s;
    vector < int > ps;
    for (int i = 2; i <= n; ++i) {
        if (n % i == 0) {
            bool ok = true;
            for (int j : ps)
                if (i % j == 0) {
                    ok = false;
                    break;
                }
            if (ok) {
                ps.push_back(i);
            }
        }
    }

    vector < ll > a;
    for (int i = 0; i < n; ++i)
        a.push_back(s[i] - '0');

    int n1 = 1;
    for (int p : ps)
        n1 *= p;

    for (int i = 0; i < n / n1; ++i) {
        vector < ll > a1;
        for (int j = i; j < n; j += n / n1)
            a1.push_back(a[j]);
        if (!solve(n1, ps, a1)) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    
    return 0;
}