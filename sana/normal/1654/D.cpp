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

const int mod = 998244353;
vi p;
vi val;
map<int,int> ans;
map<int,int> cur;
vector< vector< pair<int, pii> > > g;
int pri[210000];

int find(int x) {
    if (p[x]==-1) return x;
    return p[x]=find(p[x]);
}

void link(int a, int b) {
    a = find(a); b = find(b);
    if (a != b) p[a]=b;
}

void dfs(int v, int parent) {

    for (auto [b, p] : g[v]) {
        if (b == parent) continue;

        int x = p.first;
        int y = p.second;

        val[b] = (val[v] * 1ll * x) % mod;
        val[b] = (val[b] * 1ll * modInv(y, mod)) % mod;

        while (x > 1) {
            cur[pri[x]]++;
            x /= pri[x];
        }
        while (y > 1) {
            cur[pri[y]]--;
            if (cur[pri[y]] < 0) {
                ans[pri[y]] = max(ans[pri[y]], -cur[pri[y]]);
            }
            y /= pri[y];
        }

        dfs(b, v);

        x = p.first;
        y = p.second;

        while (x > 1) {
            cur[pri[x]]--;
            x /= pri[x];
        }
        while (y > 1) {
            cur[pri[y]]++;
            y /= pri[y];
        }
    }

}

void solve() {
    int n;
    cin >> n;

    p = vi(n,-1);
    val = vi(n);
    ans.clear();
    cur.clear();

    g = vector< vector< pair<int, pii> > >(n);

    for (int i = 0; i < n-1; i++) {
        int a, b, x, y;
        cin >> a >> b >> x >> y; a--; b--;

        if (x > y) {
            swap(x,y);
            swap(a,b);
        }

        // if (x == y) {
        //     link(a,b);
        // }
        // else {
        //     
        g[a].push_back({b, {y, x}});
        g[b].push_back({a, {x, y}});
    }

    // vi ind(n);

    // for (int i = 0; i < n; i++) {
    //     for (auto [b, p] : g[i]) ind[find(b)]++;
        
    //     if (p[i] != -1) {
    //         for (auto [b, p] : g[i]) {
    //             g[find(i)].push_back(pair<int, pii>{b, p});
    //         }
    //     }
    // }

    
    val[0] = 1;
    dfs(0, -1);

    int mult = 1;
    for (auto [a,b] : ans) {
        for (int i = 0; i < b; i++) mult = (mult * 1ll * a) % mod;
    }

    int tot = 0;
    for (int i = 0; i < n; i++) {
        dbg(i, mult, val[i], (mult*1ll*val[i])%mod);
        tot = (tot + val[find(i)] * 1ll * mult) % mod;
    }

    cout << tot << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    for (int i = 2; i <= 200000; i++) pri[i] = i;
    for (int i = 2; i <= 200000; i++) if (pri[i] == i) {
        for (int j = i+i; j <= 200000; j+=i) if (pri[j] == j) pri[j] = i;
    }

    int t;
    for (cin >> t; t; t--) solve();

    return 0;
}