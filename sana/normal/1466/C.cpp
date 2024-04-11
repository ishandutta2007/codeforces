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

int d[110000][7][7];
vi a;
int n;

int rec(int x, int pppp, int pppp2) {
    if (x == n) return 0;

    int &ret = d[x][pppp][pppp2];

    int pv = (pppp == 6 ? a[x-1] : pppp);
    int pv2 = (pppp2 == 6 ? a[x-2] : pppp2);

    if (ret == -1) {
        ret = 1000000000;

        if (a[x] != pv && a[x] != pv2) ret = min(ret, rec(x+1, 6, pppp));
        
        for (int i = 0; i < 6; i++) {
            if (i != pv && i != pv2) ret = min(ret, rec(x+1, i, pppp) + 1);
        }
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    for (cin >> t; t; t--) {
        string s;
        cin >> s;

        n = sz(s);
        if (n == 1) {
            cout << 0 << '\n';
            continue;
        }

        a = vi(n);
        for (int i = 0; i < n; i++) {
            a[i] = s[i]-'a';
            for (int j = 0; j < 7; j++) {
                for (int k = 0; k < 7; k++) d[i][j][k] = -1;
            }
        }
        
        for (int i = 0; i < 6; i++) {
            if (i != a[0] && i != a[1]) {
                cout << rec(0, i, i) << '\n';
                break;
            }
        }
    }

    return 0;
}