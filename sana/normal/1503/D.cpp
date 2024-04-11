#if 1
#ifndef ONLINE_JUDGE
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;

    vi flipped(n);
    vi seq(n);
    vi loc(n);
    vi pm(n);

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;

        if ( (a <= n && b <= n) || (a >= n+1 && b >= n+1) ) {
            cout << -1 << endl;
            return 0;
        }

        int idx = min(a,b)-1;
        int val = max(a,b)-1-n;
        seq[idx] = val;
        loc[val] = idx;

        if (b < a) flipped[idx] = 1;
    }

    pm[0] = seq[0];
    for (int i = 1; i < n; i++) {
        pm[i] = min(pm[i-1], seq[i]);
    }

    vi fin, fin_flip;
    vi seq_a, seq_b;

    int u_t = 0;
    int ans = 0;

    for (int v = n-1; v >= 0; v--) {
        if (loc[v] >= u_t) {
            seq_a.push_back(loc[v]);
            for (int x = u_t; x < loc[v]; x++) {
                seq_b.push_back(x);
            }
            u_t = loc[v]+1;
        }

        if (u_t == n-v) {
            int fa = 0, fb = 0;
            for (int x : seq_a) fa += flipped[x];
            for (int x : seq_b) fb += flipped[x];

            if ((sz(seq_a)-fa) + fb >= (sz(seq_b)-fb) + fa) {
                fin.insert(fin.end(), all(seq_a));
                fin_flip.insert(fin_flip.end(), all(seq_b));
                ans += fa + (sz(seq_b)-fb);
            }
            else {
                fin.insert(fin.end(), all(seq_b));
                fin_flip.insert(fin_flip.end(), all(seq_a));
                ans += fb + (sz(seq_a)-fa);
            }
            seq_a.clear(); seq_b.clear();
        }
    }

    for (int i = 1; i < sz(fin); i++) if (seq[fin[i-1]] < seq[fin[i]] ) {
        cout << -1 << endl;
        return 0;
    }
    for (int i = 1; i < sz(fin_flip); i++) if (seq[fin_flip[i-1]] < seq[fin_flip[i]] ) {
        cout << -1 << endl;
        return 0;
    }

    cout << ans << endl;
    return 0;
}