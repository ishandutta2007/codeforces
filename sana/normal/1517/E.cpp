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

const int mod = 998244353;

void solve() {
    int n; cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<ll> prefix_sums(n+1);
    partial_sum(all(a), prefix_sums.begin()+1);

    vector<ll> alternate_sums(n);
    for (int i = 0; i < n; i++) {
        alternate_sums[i] = (i-2>=0?alternate_sums[i-2]:0) + a[i];
    }

    long long ans = 0;
    for (int hasPleft = 0; hasPleft <= 1; hasPleft++) {
        for (int hasCright = 0; hasCright <= 1; hasCright++) {
            for (int Clen = 0; Clen <= n; Clen++) {
                if (hasPleft && Clen <= 1) continue;
                if (hasPleft+hasCright+Clen > n) continue;

                long long inisumP = 0, inisumC = 0;
                if (hasPleft) inisumP += a[0];

                int C_start = hasPleft;
                int C_up_to = Clen + hasPleft;
                inisumC += prefix_sums[C_up_to] - prefix_sums[C_start];

                int left = n - C_up_to - hasCright;
                int st = 0, ed = left/2;
                while (st < ed) {
                    int md = (st+ed+1)/2;

                    int mid_len = md*2;

                    int P_start = C_up_to;
                    int P_up_to = C_up_to + mid_len - 2;

                    int C_start = C_up_to + 1;
                    int C_up_to2 = C_up_to + mid_len - 1;

                    long long sumP = inisumP, sumC = inisumC;
                    sumP += (P_up_to>=0 ? alternate_sums[P_up_to] : 0) - (P_start-2>=0 ? alternate_sums[P_start-2] : 0);
                    sumC += (C_up_to2>=0 ? alternate_sums[C_up_to2] : 0) - (C_start-2>=0 ? alternate_sums[C_start-2] : 0);
                
                    P_start = C_up_to2 + 1;
                    P_up_to = n - hasCright;
                    sumP += prefix_sums[P_up_to] - prefix_sums[P_start];
                    if (hasCright) sumC += a[n-1];


                    if (sumC < sumP) {
                        st = md;
                    }
                    else {
                        ed = md-1;
                    }
                } 

                int mid_len = st * 2;
                if (hasCright) mid_len = min(mid_len, (left - 2)/2 * 2);
                if (hasCright) while (left-mid_len < 2) mid_len--;
                
                if (mid_len < 0) continue;

                int P_start = C_up_to;
                int P_up_to = C_up_to + mid_len - 2;
                C_start = C_up_to + 1;
                int C_up_to2 = C_up_to + mid_len - 1;
                long long sumP = inisumP, sumC = inisumC;
                sumP += (P_up_to>=0 ? alternate_sums[P_up_to] : 0) - (P_start-2>=0 ? alternate_sums[P_start-2] : 0);
                sumC += (C_up_to2>=0 ? alternate_sums[C_up_to2] : 0) - (C_start-2>=0 ? alternate_sums[C_start-2] : 0);
                P_start = C_up_to2 + 1;
                P_up_to = n - hasCright;
                sumP += prefix_sums[P_up_to] - prefix_sums[P_start];
                if (hasCright) sumC += a[n-1];
                if (sumC < sumP) {

                    dbg(hasPleft, Clen, hasCright, mid_len);
                    ans = (ans + (mid_len/2 + 1)) % mod;
                }
            }
        }
    }

    for (int Cri = 2; Cri <= n-2; Cri++) {
        long long sumC = prefix_sums[n] - prefix_sums[n-Cri];
        long long sumP = prefix_sums[n] - sumC;
        if (sumC < sumP) ans = (ans+1) % mod;
    }

    cout << (ans % mod) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    for (cin >> t; t; t--) solve();

    return 0;
}