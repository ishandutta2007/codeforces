#if 1
#ifdef LOCAL
#define _GLIBCXX_DEBUG
#define dbg(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define dbg(...) 0
#endif

#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)

typedef string str;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

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
template<class A, class B> str ts(pair<A,B> p) {return "("+ts(p.f)+", "+ts(p.s)+")"; }
 
template<class A> void pr(A x) { cout << ts(x); }
template<class H, class... T> void pr(const H& h, const T&... t) { pr(h); pr(t...); }
void ps() { pr("\n"); }
template<class H, class... T> void ps(const H& h, const T&... t) { pr(h); if (sizeof...(t)) pr(" "); ps(t...); }
 
void DBG() { cerr << "]" << endl; }
template<class H, class... T> void DBG(H h, T... t) {cerr << ts(h); if (sizeof...(t)) cerr << ", ";	DBG(t...); }
#endif

void solve() {
    int n,x,y; cin >> n >> x >> y;

    int unused = -1;
    vi a(n); for (int i = 0; i < n; i++) cin >> a[i];

    vector< vector<int> > occs(n+2);
    for (int i = 0; i < n; i++) occs[a[i]].push_back(i);

    for (int i = 1; i <= n+1; i++) if (occs[i].empty()) unused = i;

    set< pii > cols;
    for (int i = 1; i <= n+1; i++) cols.insert({-sz(occs[i]), i});

    vi ans(n);

    for (int i = 0; i < x; i++) {
        int curc = cols.begin()->second;
        cols.erase(cols.begin());

        ans[occs[curc].back()] = curc;
        occs[curc].pop_back();

        cols.insert({-sz(occs[curc]), curc});
    }

    y -= x;
    while (y > 0 && y != 3) {
        auto it = cols.begin();
        auto it2 = next(it);

        // dbg(y, ans);
        int col = it->second, col2 = it2->second;
        if (occs[col2].empty()) { cout << "NO\n"; return; }
        ans[occs[col2].back()] = col;
        if (y > 1) ans[occs[col].back()] = col2;
        occs[col].pop_back();
        occs[col2].pop_back();

        cols.erase(it); cols.erase(it2);
        cols.insert({-sz(occs[col]), col});
        cols.insert({-sz(occs[col2]), col2});
        y -= 2;
    }

    // dbg(ans);

    if (y == 3) {
        auto it = cols.begin();
        auto it2 = next(it);

        int col = it->second, col2 = it2->second;
        if (sz(occs[col2]) >= 2) {
            ans[occs[col2].back()] = col;
            ans[occs[col].back()] = col2;
            occs[col2].pop_back();
            ans[occs[col2].back()] = col;
        }
        else if (n >= 2) {
            auto it3 = next(it2); int col3 = it3->second;
            if (occs[col3].empty()) { cout << "NO\n"; return; }

            ans[occs[col].back()] = col2;
            ans[occs[col2].back()] = col3;
            ans[occs[col3].back()] = col;   
        }
        else { cout << "NO\n"; return; }
    }

    for (int i = 0; i < n; i++) if (ans[i] == 0) ans[i] = unused;

    cout << "YES" << '\n';
    for (int x : ans) cout << x << " ";
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    for (cin >> t; t; t--) {
        solve();
    }

    return 0;
}