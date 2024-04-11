#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define subnb true
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
const int N = (int)1e5 + 50;

const int MOD = 998244353;
const int M = 42628545 + 50;

struct mi {
    typedef decay<decltype(MOD)>::type T;
    /// don't silently convert to T
    T v; explicit operator T() const { return v; }
    mi() { v = 0; }
    mi(ll _v) {
        v = (-MOD < _v && _v < MOD) ? _v : _v % MOD;
        if (v < 0) v += MOD;
    }
    friend bool operator==(const mi& a, const mi& b) {
        return a.v == b.v; }
    friend bool operator!=(const mi& a, const mi& b) {
        return !(a == b); }
    friend bool operator<(const mi& a, const mi& b) {
        return a.v < b.v; }
//    friend void re(mi& a) { ll x; re(x); a = mi(x); }
//    friend str ts(mi a) { return ts(a.v); }

    mi& operator+=(const mi& m) {
        if ((v += m.v) >= MOD) v -= MOD;
        return *this; }
    mi& operator-=(const mi& m) {
        if ((v -= m.v) < 0) v += MOD;
        return *this; }
    mi& operator*=(const mi& m) {
        v = (ll)v*m.v%MOD; return *this; }
    mi& operator/=(const mi& m) { return (*this) *= inv(m); }
    friend mi pow(mi a, ll p) {
        mi ans = 1; assert(p >= 0);
        for (; p; p /= 2, a *= a) if (p&1) ans *= a;
        return ans;
    }
    friend mi inv(const mi& a) { assert(a.v != 0);
        return pow(a,MOD-2); }

    mi operator-() const { return mi(-v); }
    mi& operator++() { return *this += 1; }
    mi& operator--() { return *this -= 1; }
    friend mi operator+(mi a, const mi& b) { return a += b; }
    friend mi operator-(mi a, const mi& b) { return a -= b; }
    friend mi operator*(mi a, const mi& b) { return a *= b; }
    friend mi operator/(mi a, const mi& b) { return a /= b; }
};


struct node {
    int mnl, mnr, val;
};

ll tcnt = 0;
int S[M], st[N];

void pre() {
    rep(n, 1, N) {
        st[n] = tcnt;
        for (int i = 1, j = 0; i <= n; i = j + 1)  {
            j = n/(n/i);
            S[tcnt++] = i;
            if(j != i && n % j == 0) {
                S[tcnt++] = j;
            }
        }
    }
}

int get_mnl(int n, int i) {
    return n / i;
}

int get_mnr(int n, int i) {
    return n / i + (n % i != 0);
}


int n, a[N];
int pt[N];
mi csum = 0, tsum = 0;
mi fres = 0;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);


    pre();
//    cout << tcnt << endl;
    int T;
    cin >> T;
    while(T--) {
        cin >> n;
        rep(i, 0, n) {
            cin >> a[i];
        }
        rep(i, 0, n) {
            pt[i] = st[a[i]];
        }
        csum = tsum = fres = 0;
        rep(i, 0, n) {
            int curmn = a[i];
            for (int j = i - 1; j >= 0; j--) {
                int c = 0;
                tsum -= 1LL * (S[pt[j]] - 1) * (j + 1);

                while(get_mnr(a[j], S[pt[j]]) > curmn) {
                    c = 1;
                    pt[j]++;
                }
                curmn = get_mnl(a[j], S[pt[j]]);
                tsum += 1LL * (S[pt[j]] - 1) * (j + 1);
                if(!c) break;
            }
            fres += tsum;
        }
        cout << int(fres) << '\n';
    }

}