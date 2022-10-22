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

using uint = unsigned int;
using ull = unsigned long long;
template <uint MD> struct ModInt {
    using M = ModInt;
    static constexpr uint get_mod() { return MD; }
    const static M G;
    uint v;
    ModInt(ll _v = 0) { set_v(uint(_v % MD + MD)); }
    M& set_v(uint _v) {
        v = (_v < MD) ? _v : _v - MD;
        return *this;
    }
    explicit operator bool() const { return v != 0; }
    M operator-() const { return M() - *this; }
    M operator+(const M& r) const { return M().set_v(v + r.v); }
    M operator-(const M& r) const { return M().set_v(v + MD - r.v); }
    M operator*(const M& r) const { return M().set_v(uint(ull(v) * r.v % MD)); }
    M operator/(const M& r) const { return *this * r.inv(); }
    M& operator+=(const M& r) { return *this = *this + r; }
    M& operator-=(const M& r) { return *this = *this - r; }
    M& operator*=(const M& r) { return *this = *this * r; }
    M& operator/=(const M& r) { return *this = *this / r; }
    bool operator==(const M& r) const { return v == r.v; }
    M pow(ll n) const {
        M x = *this, r = 1;
        while (n) {
            if (n & 1) r *= x;
            x *= x;
            n >>= 1;
        }
        return r;
    }
    M inv() const { return pow(MD - 2); }
    friend ostream& operator<<(ostream& os, const M& r) { return os << r.v; }
};
// using Mint = ModInt<998244353>;
// template<> const Mint Mint::G = Mint(3);
using Mint = ModInt<998244353>;

int cnt[17][13];
Mint poss[17][65536];
Mint ans[17][65536];
Mint fac[65540];
Mint ifac[65540];
Mint possin[17][17][2][16]; // [guy][moves][xorout][xorin]

void transform(Mint *from, Mint *to) 
{ 
    if(to - from == 1) 
        return; 
    Mint *mid = from + (to - from) / 2; 
    transform(from, mid); 
    transform(mid, to); 
    for(int i = 0; i < mid - from; i++) 
    {
        Mint a = *(from + i);
        Mint b = *(mid + i);
        *(from + i) = a + b;
        *(mid + i) = a - b;
    }
} 

Mint C(int n, int k) {
    return fac[n] * ifac[n-k] * ifac[k];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    fac[0] = 1;
    ifac[0] = 1;
    for (int i = 1; i <= 65536; i++) {
        fac[i] = fac[i-1]*i;
        ifac[i] = ifac[i-1] * Mint(i).inv();
    }
    
    int n, k, oc; cin >> n >> k >> oc;

    int c = max(oc, 4);
    int allx = 0;

    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        allx ^= a;

        int low = a & 15;
        int high = (a >> 4);
        int highbit = (high == 0 ? c-4 : __builtin_ctz(high));

        cnt[low][highbit]++;
    }

    ans[0][0] = 1;
    for (int j = 0; j <= 16; j++) {
        transform(ans[j], ans[j]+(1<<(c-1)));
    }

    // for (int i = 0; i < (1<<c); i++) {
    //     dbg(i, ans[0][i].v);
    // }

    Mint invc = Mint(1<<(c-1)).inv();
    for (int low = 0; low < 16; low++) {
        for (int highbit = 0; highbit <= c-4; highbit++) if (cnt[low][highbit]) {
            
            memset(possin,0,sizeof(possin));
            memset(poss,0,sizeof(poss));

            possin[0][0][0][0] = 1;

            for (int guy = 1; guy <= min(k, cnt[low][highbit]); guy++) {
                for (int moves = 1; moves <= k+1-guy; moves++) {
                    for (int prevm = guy-1; prevm+moves <= k; prevm++) {
                        for (int prevxi = 0; prevxi <= 1; prevxi++) {
                            for (int prevxl = 0; prevxl < 16; prevxl++) {
                                if (possin[guy-1][prevm][prevxi][prevxl].v) {
                                    int xi = moves > low;
                                    int xl = ( ( ((1<<20)+low) - moves) & 15) ^ low;
                                    // if (possin[guy-1][prevm][prevxi][prevxl].v) dbg(prevm,moves,C(prevm+moves,moves).v);
                                    possin[guy][prevm+moves][prevxi ^ xi][prevxl ^ xl] += possin[guy-1][prevm][prevxi][prevxl] * C(prevm+moves,moves);
                                }
                            }
                        }
                    }
                }
            }

            int xix = ((1<<(highbit+1)) - 1) << 4;
            for (int guy = 1; guy <= min(k, cnt[low][highbit]); guy++) {
                for (int moves = guy; moves <= k; moves++) {
                    for (int prevxi = 0; prevxi <= 1; prevxi++) {
                        if (prevxi == 1 && moves <= low) continue;
                        for (int prevxl = 0; prevxl < 16; prevxl++) {
                            poss[moves][(prevxl ^ (prevxi ? xix : 0)) >> 1] += possin[guy][moves][prevxi][prevxl] * C(cnt[low][highbit], guy);
                        }
                    }
                }
            }

            for (int moves = 1; moves <= k; moves++) {
                transform(poss[moves], poss[moves] + (1<<(c-1)));
            }

            for (int tot = k; tot >= 1; tot--) {
                for (int moves = 1; moves <= tot; moves++) {        
                   for (int i = 0; i < (1<<(c-1)); i++) {
                        ans[tot][i] += ans[tot-moves][i] * poss[moves][i] * C(tot,moves);
                    }
                }
            }
        }
    }

    Mint denom = 1;
    Mint invn = Mint(n).inv();
    for (int i = 0; i < k; i++) {
        denom *= invn;
    }

    transform(ans[k], ans[k]+(1<<(c-1)));

    for (int i = 0; i < (1<<oc); i++) {
        if ((i&1) == ((allx&1) ^ (k&1))) {
            cout << ans[k][(i>>1) ^ (allx>>1)] * denom * invc << " ";
        }
        else cout << 0 << " ";
    }
    cout << endl;

    return 0;
}