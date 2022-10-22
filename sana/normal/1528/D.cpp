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

vector< vector<pii> > g;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;

    g = vector< vector<pii> > (n);

    for (int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        g[u].push_back({v, c});
    }

    for (int i = 0; i < n; i++) {
        sort(all(g[i]));
        vector<pii> ngi;

        for (auto [v, c] : g[i]) {
            if (ngi.empty() || ngi.back().second + (v - ngi.back().first) >= c) ngi.push_back({v,c});
        }

        g[i].clear();
        for (auto [v, c] : ngi) {
            if ( (v - ngi.back().first + n) + ngi.back().second >= c) g[i].push_back({v, c});
        }
        dbg(i, g[i]);
    }

    vector< vector<long long> > dist(n, vector<long long>(n, 1000000000000000000LL));
    for (int src = 0; src < n; src++) {
        dist[src][src] = 0;
        
        priority_queue<pair<long long,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> q;
        q.push({0, src});
        //for (int j = 0; j < n; j++) q.push({dist[src][j], j});

        while (!q.empty()) {
            pair<ll, int> p = q.top();
            q.pop();

            ll distpq = p.first; int curv = p.second;
            if (dist[src][curv] < distpq) continue;

            int shift = dist[src][curv] % n;

            int fr = (int)g[curv].size() - 1;
            int nxt = 0;
            long long dt = g[curv].back().second + (n - g[curv].back().first) - 1;

            for (int jj = shift; jj < n+shift; jj++) {
                int j = jj;
                if (j >= n) j -= n;

                if (nxt < g[curv].size() && (g[curv][nxt].first + shift) % n == j) {
                    fr = nxt++;
                    dt = g[curv][fr].second;
                }
                else dt++;

                ll nd = dist[src][curv] + dt;
                if (nd < dist[src][j]) {
                    dist[src][j] = nd;
                    q.push({dist[src][j], j});
                }
            }
        }

        for (int j = 0; j < n; j++) cout << dist[src][j] << " ";
        cout << '\n';
    }

    return 0;
}