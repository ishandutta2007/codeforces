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

#if 0
    /* #include <sys/time.h>
    int main() {
	    timeval tp;
	    gettimeofday(&tp, 0);
	    C = (int)tp.tv_usec; // (less than modulo)
    */

    typedef uint64_t ull;
    static int C;

    template<int M, class B>
    struct A {
        int x; B b; A(int x=0) : x(x), b(x) {}
        A(int x, B b) : x(x), b(b) {}
        A operator+(A o){int y = x+o.x; return{y - (y>=M)*M, b+o.b};}
        A operator-(A o){int y = x-o.x; return{y + (y< 0)*M, b-o.b};}
        A operator*(A o) { return {(int)(1LL*x*o.x % M), b*o.b}; }
        explicit operator ull() { return x ^ (ull) b << 21; }
    };
    typedef A<1000000007, A<1000000009, unsigned>> H;

    struct HashInterval {
        vector<H> ha, pw;
        HashInterval(string& str) : ha(sz(str)+1), pw(ha) {
            pw[0] = 1;
            rep(i,0,sz(str))
                ha[i+1] = ha[i] * C + str[i],
                pw[i+1] = pw[i] * C;
        }
        H hashInterval(int a, int b) { // hash [a, b)
            return ha[b] - ha[a] * pw[b - a];
        }
    };

    H hashString(string& s){H h{}; for(char c:s) h=h*C+c;return h;}
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

template<typename T, typename U> struct seg_tree_lazy {
    int S, H;
 
    T zero;
    std::vector<T> value;
 
    U noop;
    std::vector<bool> dirty;
    std::vector<U> prop;
 
    seg_tree_lazy<T, U>(int _S, T _zero = T(), U _noop = U());
    void set_leaves(std::vector<T> &leaves);
    void apply(int i, U &update);
    void rebuild(int i);
    void propagate(int i);
    void upd(int i, int j, U update);
    T query(int i, int j);
};

template<typename T, typename U>
seg_tree_lazy<T, U>::seg_tree_lazy(int _S, T _zero, U _noop) {
        zero = _zero, noop = _noop;
        for (S = 1, H = 1; S < _S; ) S *= 2, H++;
 
        value.resize(2*S, zero);
        dirty.resize(2*S, false);
        prop.resize(2*S, noop);
    }

template<typename T, typename U>
void seg_tree_lazy<T, U>::set_leaves(vector<T> &leaves) {
    copy(leaves.begin(), leaves.end(), value.begin() + S);

    for (int i = S - 1; i > 0; i--)
        value[i] = value[2 * i] + value[2 * i + 1];
}

template<typename T, typename U>
void seg_tree_lazy<T, U>::apply(int i, U &update) {
    value[i] = update(value[i]);
    if(i < S) {
        prop[i] = prop[i] + update;
        dirty[i] = true;
    }
}

template<typename T, typename U>
void seg_tree_lazy<T, U>::rebuild(int i) {
    for (int l = i/2; l; l /= 2) {
        T combined = value[2*l] + value[2*l+1];
        value[l] = prop[l](combined);
    }
}

template<typename T, typename U>
void seg_tree_lazy<T, U>::propagate(int i) {
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

template<typename T, typename U>
void seg_tree_lazy<T, U>::upd(int i, int j, U update) {
    i += S, j += S;
    propagate(i), propagate(j);

    for (int l = i, r = j; l <= r; l /= 2, r /= 2) {
        if((l&1) == 1) apply(l++, update);
        if((r&1) == 0) apply(r--, update);
    }

    rebuild(i), rebuild(j);
}

template<typename T, typename U>
T seg_tree_lazy<T, U>::query(int i, int j){
    i += S, j += S;
    propagate(i), propagate(j);

    T res_left = zero, res_right = zero;
    for(; i <= j; i /= 2, j /= 2){
        if((i&1) == 1) res_left = res_left + value[i++];
        if((j&1) == 0) res_right = value[j--] + res_right;
    }
    return res_left + res_right;
}

/*struct node {
    ll val = 0;

    node operator+(node ot) {
        ot.val = max(val, ot.val);
        return ot;
    }
};

struct update {
    ll val = 0;

    node operator()(node ot) {
        ot.val += val;
        return ot;
    }

    update operator+(update ot) {
        ot.val += val;
        return ot;
    }
};*/

#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int nrobs, nlights;
    cin >> nrobs >> nlights;

    vector<pii> robs(nrobs), lights(nlights);

    for (int i = 0; i < nrobs; i++) {
        cin >> robs[i].first >> robs[i].second;
    }
    for (int i = 0; i < nlights; i++) {
        cin >> lights[i].first >> lights[i].second;
    }

    vector< vector<int> > clear(1000010);
    vector< int > cnt(1000010);

    for (int i = 0; i < nrobs; i++) {
        for (int j = 0; j < nlights; j++) {
            int clearx = max(0, (lights[j].first+1 - robs[i].first));
            int cleary = max(0, lights[j].second+1 - robs[i].second);
            clear[clearx].push_back(cleary);
            cnt[cleary]++;
        }
    }

    int ans = 1000000000;
    int ym = 1000004;
    for (int xm = 0; xm <= 1000004; xm++) {
        for (auto cy : clear[xm]) {
            cnt[ cy ]--;
        }

        while (ym > 0 && !cnt[ym]) ym--;
        ans = min(ans, xm + ym);
    }

    cout << ans << endl;
    return 0;
}