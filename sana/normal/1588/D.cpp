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

char iconv(int c) {
    if (c < 26) return c+'a';
    return (c-26)+'A';
}

int conv(char c) {
    if (c >= 'a' && c <= 'z') return c-'a';
    return (c-'A') + 26;
}

int n; 
int dp[52][1050];
int locs[52][12][2];

int go(int z, int bm) {
    int &ret = dp[z][bm];

    if (ret == -1) {
        ret = 0;
        for (int nz = 0; nz < 52; nz++) {
            bool ok = true;

            int nbm = 0;
            for (int i = 0; i < n; i++) {
                int nloc = locs[z][i][!!(bm & (1<<i))];

                if (locs[nz][i][0] > nloc) {}
                else if (locs[nz][i][1] > nloc) { nbm |= (1<<i);}
                else ok = false;
            }

            if (ok) ret = max(ret, 1 + go(nz, nbm));
        }
    }

    return ret;
}

void solve() {
    cin >> n;
    vector<string> inp(n);
    for (int i = 0; i < n; i++) cin >> inp[i];

    memset(locs,-1,sizeof(locs));
    memset(dp,-1,sizeof(dp));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < inp[i].size(); j++) {
            int x = conv(inp[i][j]);
            if (locs[x][i][0] == -1) locs[x][i][0] = j;
            else locs[x][i][1] = j;
        }
    }
    
    int ans = 0;
    for (int z = 0; z < 52; z++) {
        bool ok = true;
        for (int i = 0; i < n; i++) if (locs[z][i][0] == -1) ok = false;

        if (ok) ans = max(ans, 1 + go(z, 0));
    }

    int oans = ans;
    string ret;

    if (ans != 0) ans--;
    for (int z = 0; z < 52; z++) if (dp[z][0] == ans) {
        ret += iconv(z);
        int bm = 0;

        while ( (--ans) >= 0) {
            // dbg(oans, ans, ret);
            for (int nz = 0; nz < 52; nz++) {
                bool ok = true;

                int nbm = 0;
                for (int i = 0; i < n; i++) {
                    int nloc = locs[z][i][!!(bm & (1<<i))];

                    if (locs[nz][i][0] > nloc) {}
                    else if (locs[nz][i][1] > nloc) { nbm |= (1<<i);}
                    else ok = false;
                }

                if (ok && dp[nz][nbm] == ans) {
                    ret += iconv(nz);
                    z = nz;
                    bm = nbm;
                    break;
                }
            }
        }
        
        break;
    }

    cout << oans << '\n';
    cout << ret << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    for (cin >> t; t; t--) solve();

    return 0;
}