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

vi h;

typedef vector<vector<int>> vvi;
struct Centroid {
    vvi g, centrG, dist, downdist; //
    vector< set<pii> > rdist;
    vector<int> sub, cpar;
    vector<bool> done;
    Centroid(vvi &g_) : g(g_), rdist(sz(g)), centrG(sz(g)), dist(centrG), downdist(centrG), sub(g.size()), cpar(sub), done(g.size()) { init(0); }
    void process(int x, int up_e, int mup, int down_e, int p = -1) {
        mup = max(up_e, mup);
        dist[x].push_back(up_e >= mup ? up_e : -1000000000);
        downdist[x].push_back(p == -1 ? down_e : min(down_e, downdist[p].back()));
        for (auto i : g[x]) {
            if (i != p && !done[i]) {
                if (h[x] > h[i]) process(i, -1000000000, mup, down_e + 1, x);
                else if (h[x] < h[i]) process(i, up_e + 1, mup, -1000000000, x);
                else process(i, up_e - 1, mup, down_e - 1, x);
            }
        }
    }
    int init(int x) {
        int c = getCentr(x, dfs(x));
        done[c] = true;
        process(c, 0, 0, 0);
        for (auto i : g[c]) {
            if (!done[i]) {
                centrG[c].push_back(init(i));
                cpar[centrG[c].back()] = c;
            }
        }
        return c;
    }
    int dfs(int x, int p = -1) {
        sub[x] = 1;
        for (auto i : g[x]) {
            if (!done[i] && i != p) {
                sub[x] += dfs(i, x);
            }
        }
        return sub[x];
    }
    int getCentr(int x, int totSz, int p = -1) {
        for (auto i : g[x]) {
            if (i != p && !done[i] && sub[i] > totSz / 2)
                return getCentr(i, totSz, x);
        }
        return x;
    }
    int lca(int a, int b) {
        if (sz(dist[a]) < sz(dist[b]))
            swap(a, b);
        while (sz(dist[a]) > sz(dist[b]))
            a = cpar[a];
        while (a != b)
            a = cpar[a], b = cpar[b];
        return a;
    }
    int query(int v) {
        int ans = h[v];
        int c = v;
        for (int i = sz(dist[v]) - 1; i >= 0; i--) {
            int cur_e = dist[v][i];
            if (cur_e >= 0) {
                auto it = rdist[c].lower_bound({-cur_e, -2000000000});
                if (it != rdist[c].end()) ans = min(ans, -it->second);
            }
            c = cpar[c];
        }
        return ans;
    }
    void update(int v) {
        int c = v;
        for (int i = dist[v].size() - 1; i >= 0; i--) {
            auto it = rdist[c].lower_bound({downdist[v][i], -2000000000});
            if (it == rdist[c].end() || it->second < -h[v]) {
                it = rdist[c].insert({downdist[v][i], -h[v]}).first;
                while (it != rdist[c].begin()) {
                    auto it2 = prev(it);
                    if (it2->second <= -h[v]) rdist[c].erase(it2);
                    else break; 
                }
            }
            c = cpar[c];
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;

    h = vi(n, 1000000000);
    vector<vi> g(n);

    vi base;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x) base.push_back(i);
    }

    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b; a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    queue<int> q;
    for (int x : base) {
        h[x] = 0;
        q.push(x);
    }
    
    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int x : g[cur]) {
            if (h[x] > h[cur]+1) {
                h[x] = h[cur]+1;
                q.push(x);
            }
        }
    }

    Centroid cent(g);
    for (int i = 0; i < n; i++) {
        bool ok = false;
        for (int x : g[i]) if (h[x] == h[i]) ok = true;
        if (ok) cent.update(i);
    }

    for (int i = 0; i < n; i++) cout << 2*h[i] - cent.query(i) << ' '; 
    cout << endl;

    return 0;
}