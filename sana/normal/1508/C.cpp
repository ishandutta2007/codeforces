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

//#define rep(i, a, b) for(int i = a; i < (b); ++i)
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

#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)

int n,m;
vector<int> par2;

int find2(int a) {
    if (par2[a]==a) return a;
    return par2[a]=find2(par2[a]);
}
 
void link2(int a, int b) {
    //printf("link %d %d\n",a,b);
    int x = find2(a), y = find2(b);
    par2[y]=x;
}
 
vector<int> par;
int find(int a) {
    if (par[a]==a) return a;
    return par[a]=find(par[a]);
}
 
void link(int a, int b) {
    //printf("link %d %d\n",a,b);
    int x = find(a), y = find(b);
    par[y]=x;
}


 
void solve()
{
    cin >> n >> m;
 
    vector<set<int>> g(n);
    par.resize(n); rep(i,n) par[i] = i;
    par2.resize(n); rep(i,n) par2[i] = i;
 
    vector< pair< ll, pii > > edges;

    long long allX = 0;

    rep(i,n) g[i].insert(n);
    rep(i,m) {
        int a, b, c; cin >> a >> b >> c; a--; b--;
        g[a].insert(b);
        g[b].insert(a);
        edges.emplace_back(c, pii{a,b});

        allX ^= c;
    }
 
    for (int i = 0; i < n; i++) if (par[i] == i) {
        queue<int> visit;
        
        int la = 0;
        for (int x : g[i]) {
            for (int y = la; y < x; y++) if (y != i) {
                link(i,y);
                visit.push(y);
            }
            la = x+1;
        }
 
        while (!visit.empty()) {
            int c = visit.front();
            visit.pop();
 
            vector<int> seen;
            for (int x : g[i]) {
                if (!g[c].count(x)) {
                    seen.push_back(x);
                }
            }
 
            for (int x : seen) {
                g[i].erase(x);
                link(i,x);
                visit.push(x);
            }
        }
    }

    long long ans = 0;
    int used = 0;

    sort(all(edges));
    for (int i = 0; i < m; i++) {
        if (find(edges[i].second.first) != find(edges[i].second.second)) {
            link(edges[i].second.first, edges[i].second.second);
            link2(edges[i].second.first, edges[i].second.second);
            ans += edges[i].first;
            used++;
        }
    }

    long long available = n*1ll*(n-1)/2 - m;
    if (available + used == n-1) {
        for (int i = 0; i < m; i++) {
            if (find2(edges[i].second.first) != find2(edges[i].second.second)) {
                allX = min(allX, edges[i].first);
            }
        }
        ans += allX;
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    solve();
    return 0;
}