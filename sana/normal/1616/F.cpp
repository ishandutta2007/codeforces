#if 1
#ifdef LOCAL
#define _GLIBCXX_DEBUG 1
#define dbg(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define dbg(...) 0

#include <string>
#include <bits/functexcept.h>
#include <iosfwd>
#include <bits/cxxabi_forced.h>
#include <bits/functional_hash.h>

#pragma push_macro("__SIZEOF_LONG__")
#pragma push_macro("__cplusplus")
#define __SIZEOF_LONG__ __SIZEOF_LONG_LONG__
#define unsigned unsigned long
#define __cplusplus 201102L

#define __builtin_popcountl __builtin_popcountll
#define __builtin_ctzl __builtin_ctzll

#include <bitset>

#pragma pop_macro("__cplusplus")
#pragma pop_macro("__SIZEOF_LONG__")
#undef unsigned
#undef __builtin_popcountl
#undef __builtin_ctzl
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

void solve() {
    vector< pair< array<bitset<256>, 2>, int> > e;

    int n, m; cin >> n >> m;

    vi weight(m);
    vector< vi > g(n, vi(n, -1));

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c; a--; b--; if (c == 3) c = 0;

        weight[i] = c;
        g[a][b] = g[b][a] = i;
    }

    bool ok = true;

    for (int a = 0; a < n; a++) {
        for (int b = a+1; b < n; b++) {
            for (int c = b+1; c < n; c++) {
                if (g[a][b] != -1 && g[b][c] != -1 && g[a][c] != -1) {
                    int fin_weight = 0;

                    if ( weight[g[a][b]] != -1 ) fin_weight -= weight[g[a][b]];
                    if ( weight[g[b][c]] != -1 ) fin_weight -= weight[g[b][c]];
                    if ( weight[g[a][c]] != -1 ) fin_weight -= weight[g[a][c]];

                    fin_weight %= 3;

                    array< bitset<256>, 2 > eq;
                    eq[0].reset(); eq[1].reset();
                    if (weight[g[a][b]] == -1) eq[0][g[a][b]] = 1;
                    if (weight[g[b][c]] == -1) eq[0][g[b][c]] = 1;
                    if (weight[g[a][c]] == -1) eq[0][g[a][c]] = 1;
                    
                    e.emplace_back(eq, fin_weight);
                }
            }
        }
    }

    int used = 0;
    for (int i = 0; i < m; i++) {
        for (int j = used; j < sz(e); j++) {
            if (e[j].first[0][i] || e[j].first[1][i]) {
                bitset<256> fi = e[j].first[0];
                bitset<256> se = e[j].first[1];
                bitset<256> zero = ~(e[j].first[0] | e[j].first[1]);
                int www = e[j].second;

                if (se[i]) {
                    swap(fi, se);
                    www = -www;
                }

                swap(e[j], e[used]);
                for (int k = used+1; k < sz(e); k++){
                    if (! (e[k].first[0][i] || e[k].first[1][i]) ) continue;
                    
                    bool sw = false;
                    if (e[k].first[0][i]) {
                        swap(fi, se);
                        www = -www;
                        sw = true;
                    }

                    bitset<256> tz = ~(e[k].first[0] | e[k].first[1]);
                    bitset<256> one = (e[k].first[1] & se) | (e[k].first[0] & zero) | (fi & tz);
                    bitset<256> two = (e[k].first[0] & fi) | (e[k].first[1] & zero) | (se & tz);

                    e[k].first[0] = one;
                    e[k].first[1] = two;
                    e[k].second = (e[k].second + www) % 3;

                    if (sw) {
                        swap(fi, se);
                        www = -www;
                    }
                }

                used++;
                break;
            }
        }
    }

    for (int i = sz(e)-1; i >= used; i--) {
        if (e[i].second != 0) ok = false;
    }

    for (int i = used-1; i >= 0; i--) {
        int mn = -1;
        int cursum = e[i].second;

        for (int j = 0; j < m; j++) {
            if (e[i].first[0][j] || e[i].first[1][j]) {
                if (mn == -1) mn = j;
                else {
                    if (weight[j] == -1) weight[j] = 0;

                    cursum = (cursum + weight[j]) % 3;
                    if (e[i].first[0][j]) cursum = (cursum + weight[j]) % 3;
                }
            }
        }

        if (e[i].first[0][mn]) weight[mn] = cursum % 3;
        else weight[mn] = (-cursum) % 3;
        while (weight[mn] < 0) weight[mn] += 3;
    }

    if (!ok) {
        cout << -1 << '\n';
        return;
    }

    for (int i = 0; i < m; i++) {
        if (weight[i] == -1) weight[i] = 0; 
        cout << (weight[i] == 0 ? 3 : weight[i]) << ' ';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    for (cin >> t; t; t--) solve();

    return 0;
}