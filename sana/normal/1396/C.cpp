#if 1
#ifdef LOCAL
#define _GLIBCXX_DEBUG 1
#define dbg(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define dbg(...) 0
#endif

#include <bits/stdc++.h>
using namespace std;

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
#endif

int n;
ll r1,r2,r3,d;
vi a;
ll dp[1100000][2];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    memset(dp,0x3f,sizeof(dp));

    cin >> n >> r1 >> r2 >> r3 >> d;
    r1 = min(r1, min(r2, r3));

    a = vi(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    dp[0][0] = 0;
    for (int l = 0; l < n; l++) {
        for (int prv = 0; prv < 2; prv++) {
            // dbg(l, prv, dp[l][prv]);
            ll kill_all = a[l] * 1ll * r1 + r3;
            ctmin(dp[l+1][0], dp[l][prv] + kill_all + d + (prv ? (2*d + r1) : 0));

            ll kill_one = min(r2, a[l] * 1ll * r1 + r1);
            // dbg(l+1, 1, kill_one);
            if (!prv) {
                ctmin(dp[l+1][1], dp[l][prv] + kill_one + d);
            }
            else {
                ctmin(dp[l+1][0], dp[l][prv] + kill_one + d + (2*d + 2*r1));
            }
        }
    }

    // dbg(dp[n][1]);
    ll ans = min(dp[n][0] - d, dp[n][1] + d + r1);
    // dbg(ans);
    ll back = a[n-1] * 1ll * r1 + r3;
    for (int i = n-2; i >= 0; i--) {
        back += min(r2, a[i] * 1ll * r1 + r1) + r1;
        back += 2*d;
        ctmin(ans, dp[i][0] + back);
    }

    cout << ans << endl;
    return 0;
}