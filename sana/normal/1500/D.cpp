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

int c[1600][1600];
vector<pii> col_sets[1600];
vector<pii> row_sets[1600];
vector< pii > diag_sets[2][1600];

int ta[1600][1600];
int ans[1600];
int sn[3250000];
int q;

void insert(vector<pii>& v, int c, int p) {
    for (int k = 0; k < sz(v); k++) {
        if (v[k].first == c) {
            v[k].second = p;
            return;
        }
    }

    v.push_back({c, p});
    if (sz(v) > q+2) {
        int mn = 0;
        for (int i = 0; i < sz(v); i++) {
            if (v[i].second < v[mn].second) mn = i;
        } 

        if (mn != sz(v)-1) swap(v[mn], v[sz(v)-1]);
        v.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n >> q;

    for (int i =0; i < n; i++)  {
        for (int j = 0; j < n; j++) cin >> c[i][j];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            
            insert(row_sets[i], c[i][j], j);
            insert(col_sets[j], c[i][j], i);

            vector< pii > tot;
            for (auto [a, b] : row_sets[i]) {
                tot.push_back({j - b + 1, a});
            }

            for (auto [a, b] : col_sets[j]) {
                tot.push_back({i - b + 1, a});
            }

            if (i>0 && j>0) {
                for (auto [a, b]: diag_sets[0][j-1]) {
                    tot.push_back({a+1, b});
                }
            }

            sort(all(tot));
            dbg(i, j, tot);

            vector<pii>& filt = diag_sets[1][j];
            filt.clear();

            for (auto [a, b]: tot) {
                if (sn[b]) continue;
                sn[b] = 1;
                filt.push_back({a, b});
            }

            for (auto [a,b]: filt) sn[b] = 0;

            int lim = min(i+1, j+1);
            if (i>0&&j>0) lim = min(lim, ta[i-1][j-1]+1);
            
            dbg(i, j, filt);
            if (sz(filt) > q) {
                lim = min(lim, filt[q].first-1);
            }
            while (sz(filt) > q+2) filt.pop_back();

            dbg(i, j, filt);
            if (lim == 2) dbg("HIIII");
            ans[lim]++;
            ta[i][j] = lim;
        }   

        swap(diag_sets[0], diag_sets[1]);
    }

    for (int t = n; t >= 0; t--) ans[t] += ans[t+1];
    for (int t = 1; t <= n; t++) cout << ans[t] << '\n';

    return 0;
}