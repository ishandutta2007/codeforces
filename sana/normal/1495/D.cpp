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

vector<vi> g;
vector<vi> d;
vector<vi> ans;

const int mod = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n,m;
    cin >> n >> m;

    g = vector<vi>(n);
    for (int i = 0; i < m; i++) {
        int u,v; cin >> u >> v; u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    d = vector<vi>(n, vi(n, 100000));
    for (int v = 0; v < n; v++) {
        d[v][v] = 0;
        vi q = {v};

        for (int idx = 0; idx < n; idx++) {
            int cur = q[idx];

            for (int x : g[cur]) {
                if (d[v][x] > d[v][cur] + 1) {
                    d[v][x] = d[v][cur] + 1;
                    q.push_back(x);
                }
            }
        }
    }

    ans = vector<vi>(n, vi(n));
    vector<pii> dirty;

    for (int i = 0; i < n; i++) {
        // vi allv(n);
        // for (int x = 0; x < n; x++) allv[x] = x;
        // sort(all(allv), [&](int a, int b) {
        //     return (d[i][a] < d[i][b]);
        // });

        
        for (int j = i; j < n; j++) {
            ans[i][j] = 1;

            int cnt = 0;

            for (int k = 0; k < n; k++) if (k != i) {
                int cur = k;

                int tot = d[i][cur] + d[j][cur];
                if ( (tot < d[i][j]) || (tot % 2 != d[i][j] % 2)) {
                    ans[i][j] = 0;
                    break;
                }

                int tgtj;
                if (tot == d[i][j]) {
                    tgtj = d[j][cur] + 1;
                    cnt++;
                }
                else tgtj = d[j][cur] - 1;
                
                int poss = 0;
                for (int x : g[cur]) {
                    if (d[i][x] == d[i][cur] - 1 && d[j][x] == tgtj) {
                        poss++;
                    }
                }

                if (i == 0 && j == 1) dbg(i,j,cur,poss);
                ans[i][j] = (ans[i][j] * 1ll * poss) % mod;
            }

            dbg(i, j, cnt, ans[i][j]);
            if (cnt > d[i][j]) ans[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << (i <= j ? ans[i][j] : ans[j][i]) << " ";
        }
        cout << '\n';
    }

    return 0;
}