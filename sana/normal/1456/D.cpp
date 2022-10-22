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

// a clone will collect at position i
// come from:
// 1) we collected i-1: we must come from i-1
// 2) a clone collected i-1 and we had already placed it: we come from i-2 to i

ll dist[5200][20];
bool can[5200][5200];
const ll INF = 1000000000000000000LL;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;

    vector<ll> t(n+1), x(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> t[i] >> x[i]; 
    }
    n++;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 10; j++) dist[i][j] = INF;
    }

    for (int i = 0; i < n; i++) {
        can[i][i] = 1;
        for (int j = i+1; j < n; j++) {
            can[i][j] = (can[i][j-1] && (t[j] - t[j-1] >= abs(x[j] - x[j-1])));
        }
    }

    dist[0][0] = 0;

    for (int i = 0; i < n-1; i++) {
        dbg(i, dist[i][0], dist[i][1]);
        if (dist[i][0] != INF) {
            for (int j = i+1; j < n; j++) {
                ll place_time = max(i == 0 ? 0 : t[i-1], dist[i][0] + abs(x[j] - x[i]));
                if (t[i] - place_time >= abs(x[i] - x[j]) && can[i][j-1]) {
                    dist[j][1] = 1;
                }
            }

            for (int j = i+2; j < n; j++) {
                ll departure_time = max(i == 0 ? 0 : t[i-1], dist[i][0]);
                ll place_time = max(t[i], departure_time + abs(x[j] - x[i]));
                if (t[i+1] - place_time >= abs(x[i+1] - x[j]) && can[i+1][j-1]) {
                    dist[j][1] = 1;
                }
            }

            ll i1time = max(i == 0 ? 0 : t[i-1], dist[i][0]) + abs(x[i+1] - x[i]);
            if (i1time <= t[i+1]) {
                dist[i+1][0] = min(dist[i+1][0], i1time);
            }
        }

        if (dist[i][1] != INF) {
            if (t[i+1] - t[i-1] >= abs(x[i+1] - x[i-1])) {
                dist[i+1][0] = min(dist[i+1][0], t[i-1] + abs(x[i+1] - x[i-1]));
            }

            for (int j = i+2; j < n; j++) {
                ll place_time = max(t[i], t[i-1] + abs(x[j] - x[i-1]));
                if (t[i+1] - place_time >= abs(x[i+1] - x[j]) && can[i+1][j-1]) {
                    dist[j][1] = 1;
                }
            }
        }
    }

    dbg(n-1, dist[n-1][0], dist[n-1][1]);
    bool ans = (dist[n-1][0] != INF) || (dist[n-1][1] != INF);
    cout << (ans ? "YES" : "NO") << endl;
    return 0;
}