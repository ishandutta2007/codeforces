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

template<typename T, typename U> struct seg_tree_lazy {
    int S, H;
 
    T zero;
    vector<T> value;
 
    U noop;
    vector<bool> dirty;
    vector<U> prop;
 
    seg_tree_lazy<T, U>(int _S, T _zero = T(), U _noop = U()) {
        zero = _zero, noop = _noop;
        for (S = 1, H = 1; S < _S; ) S *= 2, H++;
 
        value.resize(2*S, zero);
        dirty.resize(2*S, false);
        prop.resize(2*S, noop);
    }
 
    void set_leaves(vector<T> &leaves) {
        copy(leaves.begin(), leaves.end(), value.begin() + S);
 
        for (int i = S - 1; i > 0; i--)
            value[i] = value[2 * i] + value[2 * i + 1];
    }
 
    void apply(int i, U &update) {
        value[i] = update(value[i]);
        if(i < S) {
            prop[i] = prop[i] + update;
            dirty[i] = true;
        }
    }
 
    void rebuild(int i) {
        for (int l = i/2; l; l /= 2) {
            T combined = value[2*l] + value[2*l+1];
            value[l] = prop[l](combined);
        }
    }
 
    void propagate(int i) {
        for (int h = H; h > 0; h--) {
            int l = i >> h;
 
            if (dirty[l]) {
                apply(2*l, prop[l]);
                apply(2*l+1, prop[l]);
 
                prop[l] = noop;
                dirty[l] = false;
            }
        }
    }
 
    void upd(int i, int j, U update) {
        i += S, j += S;
        propagate(i), propagate(j);
 
        for (int l = i, r = j; l <= r; l /= 2, r /= 2) {
            if((l&1) == 1) apply(l++, update);
            if((r&1) == 0) apply(r--, update);
        }
 
        rebuild(i), rebuild(j);
    }
 
    T query(int i, int j){
        i += S, j += S;
        propagate(i), propagate(j);
 
        T res_left = zero, res_right = zero;
        for(; i <= j; i /= 2, j /= 2){
            if((i&1) == 1) res_left = res_left + value[i++];
            if((j&1) == 0) res_right = value[j--] + res_right;
        }
        return res_left + res_right;
    }
};

struct node {
    int maxA; 
    int maxC;
    int ans;

    node() : maxA(-1000000000), maxC(-1000000000), ans(-1000000000) {}
    node(int mac, int mcc, int ans) : maxA(mac), maxC(mcc), ans(ans) {}

    node operator+(const node& b) {
        return node(max(maxA, b.maxA), max(maxC, b.maxC), max(maxA + b.maxC, max(ans, b.ans)));
    }
};

struct update {
    int addA;
    int addC;

    update() : addA(0), addC(0) {}
    update(int a, int c) : addA(a), addC(c) {}

    node operator()(node a) {
        a.maxA += addA;
        a.maxC += addC;
        a.ans += addA + addC;
        return a;
    }

    update operator+(update ot) {
        return update(addA + ot.addA, addC + ot.addC);
    } 
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, q;
    cin >> n >> q;
    string s; cin >> s;

    seg_tree_lazy<node, update> st(n+1);
    
    vector<node> leaves(n+1);
    vi totA(n+1), totC(n+1);

    int bcnt = 0;
    for (int i = 0; i < n; i++) if (s[i] == 'b') bcnt++;

    for (int i = 0; i < n; i++) {
        totA[i+1] += totA[i];
        if (s[i] == 'a') totA[i+1]--;
        else if (s[i] == 'b') totA[i+1]++;
    }

    for (int i = n-1; i >= 0; i--) {
        totC[i] += totC[i+1];
        if (s[i] == 'c') totC[i]--;
        else if (s[i] == 'b') totC[i]++;
    }

    for (int i = 0; i <= n; i++) {
        leaves[i].maxA = totA[i];
        leaves[i].maxC = totC[i];
        leaves[i].ans = totA[i] + totC[i];
    }
    st.set_leaves(leaves);

    
    for (; q; q--) {
        int pos; char typ;
        cin >> pos >> typ; pos--;

        if (s[pos] == 'b') {
            bcnt--;
            st.upd(pos+1, n, update{-1, 0});
            st.upd(0, pos, update{0, -1});
        }
        if (typ == 'b') {
            bcnt++;
            st.upd(pos+1, n, update{1, 0});
            st.upd(0, pos, update{0, 1});
        }

        if (s[pos] == 'a') {
            st.upd(pos+1, n, update{1, 0});
        }
        if (typ == 'a') {
            st.upd(pos+1, n, update{-1, 0});
        }

        if (s[pos] == 'c') {
            st.upd(0, pos, update{0, 1});
        }
        if (typ == 'c') {
            st.upd(0, pos, update{0, -1});
        }

        s[pos] = typ;
        cout << bcnt - st.query(0, n).ans << '\n';
    }

    return 0;
}