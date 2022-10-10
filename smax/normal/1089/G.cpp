#include <bits/stdc++.h>

using namespace std;

#define f0r(a, b) for (long long a = 0; a < b; a++)
#define f1r(a, b, c) for (long long a = b; a < c; a++)
#define f0rd(a, b) for (long long a = b; a >= 0; a--)
#define f1rd(a, b, c) for (long long a = b; a >= c; a--)
#define ms(arr, v) memset(arr, v, sizeof(arr))
#define mp(a, b) make_pair(a, b)
#define pb push_back
#define f first
#define s second

#define ao(a, n) {for (int ele = 0; ele < n; ele++) { if (ele) cout << " "; cout << a[ele]; } cout << '\n';}

typedef long long ll;
typedef double ld;
typedef long double lld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpi;
typedef vector<pll> vpl;

const ll inf = 1e12;
const ll mod = 1e9 + 7;

namespace modop {
  ll madd(ll a, ll b) {
    return (a + b) % mod;
  }
  ll msub(ll a, ll b) {
    return (((a - b) % mod) + mod) % mod;
  }
  ll mmul(ll a, ll b) {
    return ((a % mod) * (b % mod)) % mod;
  }
  ll mpow(ll base, ll exp) {
    ll res = 1;
    while (exp) {
      if (exp % 2 == 1){
        res = (res * base) % mod;
      }
      exp >>= 1;
      base = (base * base) % mod;
    }
    return res;
  }
  ll minv(ll base) {
    return mpow(base, mod - 2);
  }
  ll mdiv(ll a, ll b) {
    return mmul(a, minv(b));
  }
}

using namespace modop;

const int MOD = 1e9 + 7;
typedef decay<decltype(MOD)>::type T;
struct mi {
    T val;
    explicit operator T() const { return val; }
    mi() { val = 0; }
    mi(const long long& v) {
        val = (-MOD <= v && v <= MOD) ? v : v % MOD;
        if (val < 0) val += MOD; }
    friend ostream& operator<<(ostream& os, const mi& a) { return os << a.val; }
    friend bool operator==(const mi& a, const mi& b) { return a.val == b.val; }
    friend bool operator!=(const mi& a, const mi& b) { return !(a == b); }
    friend bool operator<(const mi& a, const mi& b) { return a.val < b.val; }
    mi operator-() const { return mi(-val); }
    mi& operator+=(const mi& m) {
        if ((val += m.val) >= MOD) val -= MOD;
        return *this; }
    mi& operator-=(const mi& m) {
        if ((val -= m.val) < 0) val += MOD;
        return *this; }
    mi& operator*=(const mi& m) { val = (long long) val * m.val % MOD;
        return *this; }
    friend mi pow(mi a, long long p) {
        mi ans = 1; assert(p >= 0);
        for (; p; p /= 2, a *= a) if (p & 1) ans *= a;
        return ans; }
    friend mi inv(const mi& a) { assert(a != 0); return pow(a, MOD - 2); }
    mi& operator/=(const mi& m) { return (*this) *= inv(m); }
    friend mi operator+(mi a, const mi& b) { return a += b; }
    friend mi operator-(mi a, const mi& b) { return a -= b; }
    friend mi operator*(mi a, const mi& b) { return a *= b; }
    friend mi operator/(mi a, const mi& b) { return a /= b; }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    ll t; cin >> t;

    while (t--) {
        ll n; cin >> n;
        ll a[7];

        ll cur = 0;

        f0r(i, 7) {
            cin >> a[i];
            if (a[i]) cur++;
        }

        ll ret = 0;

        if (n > cur) {
            if (n % cur == 0) {
                ret = (n - cur)/cur * 7;
                n = cur;
            } else {
                ret = (n)/cur * 7;
                n = n % cur;
            }
        }

        ll extra = inf;

        f0r(i, 7) {
            if (a[i] == 0) continue;

            //num of days
            ll tmp = 1;
            ll cr = 1;

            ll j = (i+1) % 7;

            while (cr < n) {
                tmp++;
                if (a[j]) cr++;

                j = (j+1) % 7;
            }

            extra = min(extra, tmp);
        }

        cout << extra + ret << endl;






    }

}