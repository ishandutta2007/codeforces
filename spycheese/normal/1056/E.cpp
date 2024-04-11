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
const int P = 239;
const int MOD = 1000000009;
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

const int N = 1000179;

char s[N], t[N];
int ppow[N];
int h[N];

int getHash(int i, int len) {
    int ans = (h[i + len] - 1LL * ppow[len] * h[i]) % MOD;
    if (ans < 0)
        ans += MOD;
    return ans;
}

int main() {
    scanf("%s%s", s, t);
    int n = strlen(s);
    int m = strlen(t);

    ppow[0] = 1;
    for (int i = 1; i < N; ++i)
        ppow[i] = (1LL * ppow[i - 1] * P) % MOD;
    h[0] = 0;
    for (int i = 0; i < m; ++i)
        h[i + 1] = (1LL * P * h[i] + (int)t[i]) % MOD;

    if (s[0] == '1') {
        for (int i = 0; i < n; ++i)
            s[i] = "01"[s[i] == '0'];
    }
    
    int f1 = 0;
    while (s[f1] == '0')
        ++f1;
    int cnt0 = 0, cnt1 = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '0')
            ++cnt0;
        else
            ++cnt1;
    }

    int ans = 0;
    for (int s0 = 1; s0 * cnt0 < m; ++s0) {
        if ((m - s0 * cnt0) % cnt1)
            continue;
        int s1 = (m - s0 * cnt0) / cnt1;
        int h0 = getHash(0, s0);
        int h1 = getHash(f1 * s0, s1);
        if (s0 == s1 && h0 == h1)
            continue;
        int j = 0;
        bool ok = true;
        for (int i = 0; i < n; ++i)
            if (s[i] == '0') {
                if (getHash(j, s0) != h0) {
                    ok = false;
                    break;
                }
                j += s0;
            } else {
                if (getHash(j, s1) != h1) {
                    ok = false;
                    break;
                }
                j += s1;
            }
        if (ok)
            ++ans;
    }

    cout << ans << "\n";

    return 0;
}