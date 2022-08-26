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

ull d[11][70][11];
ull cnk[11][11];

ull solve(int b, ll n) {
    vector < int > digs;
    while (n) {
        digs.push_back(n % b);
        n /= b;
    }
    reverse(ALL(digs));

    ull ans = 0;
    for (int len = 2; len < sz(digs); len += 2)
        ans += d[b][len][0] - d[b][len-1][1];

    vector < int > cnt(b);
    int cnt1 = 0;
    for (int i = 0; i < sz(digs); ++i) {
        for (int dig = (i == 0 ? 1 : 0); dig < digs[i]; ++dig) {
            ans += d[b][sz(digs)-i-1][cnt[dig] % 2 == 1 ? cnt1-1 : cnt1+1];
        }
        if (cnt[digs[i]] % 2 == 1)
            --cnt1;
        else
            ++cnt1;
        ++cnt[digs[i]];
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);

    for (int n = 0; n <= 10; ++n) {
        cnk[n][0] = 1;
        for (int k = 1; k <= n; ++k)
            cnk[n][k] = cnk[n-1][k] + cnk[n-1][k-1];
    }
    
    for (int b = 2; b <= 10; ++b) {
        d[b][0][0] = 1;
        for (int len = 1; len < 70; ++len)
            for (int cnt1 = 0; cnt1 <= b; ++cnt1) {
                for (int dig = 0; dig < b; ++dig)
                    d[b][len][cnt1] += d[b][len-1][dig < cnt1 ? cnt1 - 1 : cnt1 + 1];
            }
    }

    int t;
    cin >> t;
    while (t--) {
        int b;
        ll l, r;
        cin >> b >> l >> r;
        cout << solve(b, r + 1) - solve(b, l) << "\n";
    }

    return 0;
}