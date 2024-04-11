#if 1
#ifdef LOCAL
#define _GLIBCXX_DEBUG 1
#define dbg(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define dbg(...) 0
#endif

#include <bits/stdc++.h>
using namespace std;

#if 0
    #include <bits/extc++.h>
    using namespace __gnu_pbds;

    template<class T>
    using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,
        tree_order_statistics_node_update>;
#endif

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)

typedef string str;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

template<typename T, typename U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<typename T, typename U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }

mt19937 rng((unsigned)chrono::steady_clock::now().time_since_epoch().count());

#define ts to_string
str ts(char c) { return str(1,c); }
str ts(bool b) { return b ? "true" : "false"; }
str ts(const char* s) { return (str)s; }
str ts(str s) { return s; }
template<class A> str ts(complex<A> c) { stringstream ss; ss << c; return ss.str(); }
str ts(vector<bool> v) { str res = "{"; F0R(i,sz(v)) res += char('0'+v[i]);	res += "}"; return res; }
template<size_t SZ> str ts(bitset<SZ> b) { str res = ""; F0R(i,SZ) res += char('0'+b[i]); return res; }
template<class A, class B> str ts(pair<A,B> p);
template<class T> str ts(T v) { bool fst = 1; str res = "{"; for (const auto& x: v) {if (!fst) res += ", ";	fst = 0; res += ts(x);}	res += "}"; return res;}
template<class A, class B> str ts(pair<A,B> p) {return "("+ts(p.first)+", "+ts(p.second)+")"; }
 
template<class A> void pr(A x) { cout << ts(x); }
template<class H, class... T> void pr(const H& h, const T&... t) { pr(h); pr(t...); }
void ps() { pr("\n"); }
template<class H, class... T> void ps(const H& h, const T&... t) { pr(h); if (sizeof...(t)) pr(" "); ps(t...); }
 
void DBG() { cerr << "]" << endl; }
template<class H, class... T> void DBG(H h, T... t) {cerr << ts(h); if (sizeof...(t)) cerr << ", ";	DBG(t...); }

int myrand(int l, int r) { return uniform_int_distribution(l, r)(rng); }

#endif

int cnt[420][2][2];
int pd[420][420];
int fac[420];
int ifac[420];
int mod;

template <typename T>
T gcd(T a, T b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}

template <typename T>
T extGcd(T a, T b, T& x, T& y) {
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	else {
		int g = extGcd(b, a % b, y, x);
		y -= a / b * x;
		return g;
	}
}

template <typename T>
T modInv(T a, T m) {
	T x, y;
	extGcd(a, m, x, y);
	return (x % m + m) % m;
}

int C(int n, int k) {
    int den = (ifac[k] * 1ll * ifac[n-k]) % mod;
    return (fac[n] * 1ll * den) % mod;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int totn;
    cin >> totn >> mod;

    fac[0] = 1;
    for (int i = 1; i <= 410; i++) fac[i] = (fac[i-1] * 1ll * i) % mod;
    ifac[410] = modInv(fac[410], mod);
    for (int i = 409; i >= 0; i--) ifac[i] = (ifac[i+1] * 1ll * (i+1)) % mod;

    for (int l = 0; l < 2; l++) {
        for (int r = 0; r < 2; r++) {
            cnt[0][l][r] = 1;
            cnt[1][l][r] = 1;
        }
    }
    cnt[1][1][1] = 0;

    for (int n = 2; n <= totn; n++) {
        for (int l = 0; l < 2; l++) {
            for (int r = 0; r < 2; r++) {
                for (int pick = 0; pick < n; pick++) {
                    int th = (cnt[pick][l][1] * 1ll * cnt[n-pick-1][1][r]) % mod;
                    th = (th * 1ll * C(n-1, pick)) % mod;

                    cnt[n][l][r] = (cnt[n][l][r] + th) % mod;
                    // if (n == 2) dbg(n,l,r,pick,cnt[n][l][r]);
                }
            }
        }
    }

    for (int needskip = 0; needskip <= totn; needskip++) pd[0][needskip] = 1;
    
    for (int n = 0; n < totn; n++) {
        for (int needskip = 1; needskip <= totn; needskip++) {
            // dbg(n, needskip, pd[n][needskip]);
            int rem = (totn+1) - n - needskip;
            for (int k = 1; k <= rem; k++) {

                int th = (pd[n][needskip] * 1ll * cnt[k][0][0]) % mod;
                th = (th * 1ll * C(rem, k)) % mod;
                
                pd[n+k+1][needskip-1] = (pd[n+k+1][needskip-1] + th) % mod;
            }
        }
    }

    // dbg(cnt[3][0][0]);
    cout << pd[totn+1][0] << endl;
    return 0;
}