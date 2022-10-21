#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
using db = long double; // or double, if TL is tight
using str = string; // yay python! 

// pairs
using pi = pair<int,int>;
using pl = pair<ll,ll>;
using pd = pair<db,db>;
#define mp make_pair
#define f first
#define s second

#define tcT template<class T
#define tcTU tcT, class U
// ^ lol this makes everything look weird but I'll try it
tcT> using V = vector<T>; 
tcT, size_t SZ> using AR = array<T,SZ>; 
using vi = V<int>;
using vb = V<bool>;
using vl = V<ll>;
using vd = V<db>;
using vs = V<str>;
using vpi = V<pi>;
using vpl = V<pl>;
using vpd = V<pd>;

// vectors
// oops size(x), rbegin(x), rend(x) need C++17
#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend() 
#define sor(x) sort(all(x)) 
#define rsz resize
#define ins insert 
#define pb push_back
#define eb emplace_back
#define ft front()
#define bk back()

#define lb lower_bound
#define ub upper_bound
tcT> int lwb(V<T>& a, const T& b) { return int(lb(all(a),b)-bg(a)); }
tcT> int upb(V<T>& a, const T& b) { return int(ub(all(a),b)-bg(a)); }

// loops
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define rep(a) F0R(_,a)
#define each(a,x) for (auto& a: x)

const int MOD = 1e9+7; // 998244353;
const int MX = 2e5+5;
const ll BIG = 1e18; // not too close to LLONG_MAX
const db PI = acos((db)-1);
const int dx[4]{1,0,-1,0}, dy[4]{0,1,0,-1}; // for every grid problem!!
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 
template<class T> using pqg = priority_queue<T,vector<T>,greater<T>>;

// bitwise ops
// also see https://gcc.gnu.org/onlinedocs/gcc/Other-Builtins.html
constexpr int pct(int x) { return __builtin_popcount(x); } // # of bits set
constexpr int bits(int x) { // assert(x >= 0); // make C++11 compatible until USACO updates ...
    return x == 0 ? 0 : 31-__builtin_clz(x); } // floor(log2(x)) 
constexpr int p2(int x) { return 1<<x; }
constexpr int msk2(int x) { return p2(x)-1; }

ll cdiv(ll a, ll b) { return a/b+((a^b)>0&&a%b); } // divide a by b rounded up
ll fdiv(ll a, ll b) { return a/b-((a^b)<0&&a%b); } // divide a by b rounded down

tcT> bool ckmin(T& a, const T& b) {
    return b < a ? a = b, 1 : 0; } // set a = min(a,b)
tcT> bool ckmax(T& a, const T& b) {
    return a < b ? a = b, 1 : 0; } // set a = max(a,b)

tcTU> T fstTrue(T lo, T hi, U f) {
    ++hi; assert(lo <= hi); // assuming f is increasing
    while (lo < hi) { // find first index such that f is true 
        T mid = lo+(hi-lo)/2;
        f(mid) ? hi = mid : lo = mid+1; 
    } 
    return lo;
}
tcTU> T lstTrue(T lo, T hi, U f) {
    --lo; assert(lo <= hi); // assuming f is decreasing
    while (lo < hi) { // find first index such that f is true 
        T mid = lo+(hi-lo+1)/2;
        f(mid) ? lo = mid : hi = mid-1;
    } 
    return lo;
}
tcT> void remDup(vector<T>& v) { // sort and remove duplicates
    sort(all(v)); v.erase(unique(all(v)),end(v)); }
tcTU> void erase(T& t, const U& u) { // don't erase
    auto it = t.find(u); assert(it != end(t));
    t.erase(it); } // element that doesn't exist from (multi)set

#define tcTUU tcT, class ...U

inline namespace Helpers {
    //////////// is_iterable
    // https://stackoverflow.com/questions/13830158/check-if-a-variable-type-is-iterable
    // this gets used only when we can call begin() and end() on that type
    tcT, class = void> struct is_iterable : false_type {};
    tcT> struct is_iterable<T, void_t<decltype(begin(declval<T>())),
                                      decltype(end(declval<T>()))
                                     >
                           > : true_type {};
    tcT> constexpr bool is_iterable_v = is_iterable<T>::value;

    //////////// is_readable
    tcT, class = void> struct is_readable : false_type {};
    tcT> struct is_readable<T,
            typename std::enable_if_t<
                is_same_v<decltype(cin >> declval<T&>()), istream&>
            >
        > : true_type {};
    tcT> constexpr bool is_readable_v = is_readable<T>::value;

    //////////// is_printable
    // // https://nafe.es/posts/2020-02-29-is-printable/
    tcT, class = void> struct is_printable : false_type {};
    tcT> struct is_printable<T,
            typename std::enable_if_t<
                is_same_v<decltype(cout << declval<T>()), ostream&>
            >
        > : true_type {};
    tcT> constexpr bool is_printable_v = is_printable<T>::value;
}

inline namespace Input {
    tcT> constexpr bool needs_input_v = !is_readable_v<T> && is_iterable_v<T>;
    tcTUU> void re(T& t, U&... u);
    tcTU> void re(pair<T,U>& p); // pairs

    // re: read
    tcT> typename enable_if<is_readable_v<T>,void>::type re(T& x) { cin >> x; } // default
    tcT> void re(complex<T>& c) { T a,b; re(a,b); c = {a,b}; } // complex
    tcT> typename enable_if<needs_input_v<T>,void>::type re(T& i); // ex. vectors, arrays
    tcTU> void re(pair<T,U>& p) { re(p.f,p.s); }
    tcT> typename enable_if<needs_input_v<T>,void>::type re(T& i) {
        each(x,i) re(x); }
    tcTUU> void re(T& t, U&... u) { re(t); re(u...); } // read multiple

    // rv: resize and read vectors
    void rv(size_t) {}
    tcTUU> void rv(size_t N, V<T>& t, U&... u);
    template<class...U> void rv(size_t, size_t N2, U&... u);
    tcTUU> void rv(size_t N, V<T>& t, U&... u) {
        t.rsz(N); re(t);
        rv(N,u...); }
    template<class...U> void rv(size_t, size_t N2, U&... u) {
        rv(N2,u...); }

    // dumb shortcuts to read in ints
    void decrement() {} // subtract one from each
    tcTUU> void decrement(T& t, U&... u) { --t; decrement(u...); }
    #define ints(...) int __VA_ARGS__; re(__VA_ARGS__);
    #define int1(...) ints(__VA_ARGS__); decrement(__VA_ARGS__);
}

inline namespace ToString {
    tcT> constexpr bool needs_output_v = !is_printable_v<T> && is_iterable_v<T>;

    // ts: string representation to print
    tcT> typename enable_if<is_printable_v<T>,str>::type ts(T v) {
        stringstream ss; ss << fixed << setprecision(15) << v;
        return ss.str(); } // default
    tcT> str bit_vec(T t) { // bit vector to string
        str res = "{"; F0R(i,sz(t)) res += ts(t[i]);
        res += "}"; return res; }
    str ts(V<bool> v) { return bit_vec(v); }
    template<size_t SZ> str ts(bitset<SZ> b) { return bit_vec(b); } // bit vector
    tcTU> str ts(pair<T,U> p); // pairs
    tcT> typename enable_if<needs_output_v<T>,str>::type ts(T v); // vectors, arrays
    tcTU> str ts(pair<T,U> p) { return "("+ts(p.f)+", "+ts(p.s)+")"; }
    tcT> typename enable_if<is_iterable_v<T>,str>::type ts_sep(T v, str sep) {
        // convert container to string w/ separator sep
        bool fst = 1; str res = "";
        for (const auto& x: v) {
            if (!fst) res += sep;
            fst = 0; res += ts(x);
        }
        return res;
    }
    tcT> typename enable_if<needs_output_v<T>,str>::type ts(T v) {
        return "{"+ts_sep(v,", ")+"}"; }

    // for nested DS
    template<int, class T> typename enable_if<!needs_output_v<T>,vs>::type 
      ts_lev(const T& v) { return {ts(v)}; }
    template<int lev, class T> typename enable_if<needs_output_v<T>,vs>::type 
      ts_lev(const T& v) {
        if (lev == 0 || !sz(v)) return {ts(v)};
        vs res;
        for (const auto& t: v) {
            if (sz(res)) res.bk += ",";
            vs tmp = ts_lev<lev-1>(t);
            res.ins(end(res),all(tmp));
        }
        F0R(i,sz(res)) {
            str bef = " "; if (i == 0) bef = "{";
            res[i] = bef+res[i];
        }
        res.bk += "}";
        return res;
    }
}

inline namespace Output {
    template<class T> void pr_sep(ostream& os, str, const T& t) { os << ts(t); }
    template<class T, class... U> void pr_sep(ostream& os, str sep, const T& t, const U&... u) {
        pr_sep(os,sep,t); os << sep; pr_sep(os,sep,u...); }
    // print w/ no spaces
    template<class ...T> void pr(const T&... t) { pr_sep(cout,"",t...); } 
    // print w/ spaces, end with newline
    void ps() { cout << "\n"; }
    template<class ...T> void ps(const T&... t) { pr_sep(cout," ",t...); ps(); } 
    // debug to cerr
    template<class ...T> void dbg_out(const T&... t) {
        pr_sep(cerr," | ",t...); cerr << endl; }
    void loc_info(int line, str names) {
        cerr << "Line(" << line << ") -> [" << names << "]: "; }
    template<int lev, class T> void dbgl_out(const T& t) {
        cerr << "\n\n" << ts_sep(ts_lev<lev>(t),"\n") << "\n" << endl; }
    #ifdef LOCAL
        #define dbg(...) loc_info(__LINE__,#__VA_ARGS__), dbg_out(__VA_ARGS__)
        #define dbgl(lev,x) loc_info(__LINE__,#x), dbgl_out<lev>(x)
    #else // don't actually submit with this
        #define dbg(...) 0
        #define dbgl(lev,x) 0
    #endif

    const clock_t beg = clock();
    #define dbg_time() dbg((db)(clock()-beg)/CLOCKS_PER_SEC)
}

inline namespace FileIO {
    void setIn(str s)  { freopen(s.c_str(),"r",stdin); }
    void setOut(str s) { freopen(s.c_str(),"w",stdout); }
    void setIO(str s = "") {
        cin.tie(0)->sync_with_stdio(0); // unsync C / C++ I/O streams
        // cin.exceptions(cin.failbit);
        // throws exception when do smth illegal
        // ex. try to read letter into int
        if (sz(s)) setIn(s+".in"), setOut(s+".out"); // for old USACO
    }
}

/**
 * Description: Operations with fractions
 * Source: https://martin-thoma.com/fractions-in-cpp/
 * Verification: TopCoder MinimizeAbsoluteDifferenceDiv1
 */

struct frac {
    ll n,d;
    frac(ll _n, ll _d) {
        n = _n, d = _d;
        ll g = gcd(n,d); n /= g, d /= g;
        if (d < 0) n *= -1, d *= -1;
    }
    frac(ll _n) : frac(_n,1) {}
    frac() : frac(0) {}
    friend frac abs(frac F) { return frac(abs(F.n),F.d); }
    friend str ts(const frac& a) { return ts(a.n)+"/"+ts(a.d); }
 
    friend bool operator<(const frac& l, const frac& r) { return l.n*r.d < r.n*l.d; }
    friend bool operator==(const frac& l, const frac& r) { return l.n == r.n && l.d == r.d; }
    friend bool operator!=(const frac& l, const frac& r) { return !(l == r); }
 
    frac operator-() const { return frac(-n,d); }
    friend frac operator+(const frac& l, const frac& r) { return frac(l.n*r.d+r.n*l.d,l.d*r.d); }
    friend frac operator-(const frac& l, const frac& r) { return frac(l.n*r.d-r.n*l.d,l.d*r.d); }
    friend frac operator*(const frac& l, const frac& r) { return frac(l.n*r.n,l.d*r.d); }
    friend frac operator*(const frac& l, int r) { return l*frac(r,1); }
    friend frac operator*(int r, const frac& l) { return l*r; }
    friend frac operator/(const frac& l, const frac& r) { return l*frac(r.d,r.n); }
    friend frac operator/(const frac& l, const int& r) { return l/frac(r,1); }
    friend frac operator/(const int& l, const frac& r) { return frac(l,1)/r; }
 
    friend frac& operator+=(frac& l, const frac& r) { return l = l+r; }
    friend frac& operator-=(frac& l, const frac& r) { return l = l-r; }
    template<class T> friend frac& operator*=(frac& l, const T& r) { return l = l*r; }
    template<class T> friend frac& operator/=(frac& l, const T& r) { return l = l/r; }
};



/**
 * Description: A set (not multiset!) with support for finding the $n$'th
 * element, and finding the index of an element. Change \texttt{null\_type} for map.
 * Time: O(\log N)
 * Source: KACTL
   * https://codeforces.com/blog/entry/11080
 * Verification: many
 */

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
tcT> using Tree = tree<T, null_type, less<T>, 
    rb_tree_tag, tree_order_statistics_node_update>; 
#define ook order_of_key
#define fbo find_by_order

void treeExample() {
    Tree<int> t, t2; t.insert(8);
    auto it = t.insert(10).f; assert(it == t.lb(9));
    assert(t.ook(10) == 1 && t.ook(11) == 2 && *t.fbo(0) == 8);
    t.join(t2); // assuming T < T2 or T > T2, merge t2 into t
}

/**
int atMost(Tree<pi>& T, int r) { 
    return T.ook({r,MOD}); }
int getSum(Tree<pi>& T, int l, int r) { 
    return atMost(T,r)-atMost(T,l-1); }
*/

/**
 * Author: Lukas Polacek
 * Date: 2009-10-30
 * License: CC0
 * Source: folklore/TopCoder
 * Description: Computes partial sums a[0] + a[1] + ... + a[pos - 1], and updates single elements a[i],
 * taking the difference between the old and new value.
 * Time: Both operations are $O(\log N)$.
 * Status: Stress-tested
 */

tcT> struct BIT {
    int N; V<T> data;
    void init(int _N) { N = _N; data.rsz(N); }
    void add(int p, T x) { for (++p;p<=N;p+=p&-p) data[p-1] += x; }
    T sum(int l, int r) { return sum(r+1)-sum(l); }
    T sum(int r) { T s = 0; for(;r;r-=r&-r)s+=data[r-1]; return s; }
    int lower_bound(T sum) {
        if (sum <= 0) return -1;
        int pos = 0;
        for (int pw = 1<<25; pw; pw >>= 1) {
            int npos = pos+pw;
            if (npos <= N && data[npos-1] < sum)
                pos = npos, sum -= data[pos-1];
        }
        return pos;
    }
};

Tree<pair<frac, int>> t;

const int mx = 100005;

struct Eff{ //EFF BEGIN
//REMEMBER TO INITIALIZE STUFF

int n, m;
ll a[mx];
vl b[mx];
ll b_sum[mx];

void INITIALIZE(){
    #warning INITIALIZE
    for(int i = 0; i < m; i++){
        b[i].clear();
        b_sum[i] = 0;
    }
}

void solveTestCase(){
    cin >> n >> m;

    INITIALIZE();

    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a+1, a+1+n);
    vl teachers;
    for(int i = n-m+1; i <= n; i++){
        teachers.pb(a[i]);
    }
    assert(sz(teachers) == m);

    for(int i = 0; i < m; i++){
        int k;
        cin >> k;
        for(int j = 0; j < k; j++){
            ll v; cin >> v;
            b[i].pb(v);
        }
    }
    for(int i = 0; i < m; i++){
        for(auto u: b[i]){
            b_sum[i]+=u;
        }
    }

    V<pair<frac, int>> students;

    for(int i = 0; i < m; i++){
        students.pb(mp(frac(b_sum[i], sz(b[i])), i));
    }
    sort(all(students));

    vi r_students = vi(m, 0);

    for(int i = 0; i < m; i++){
        r_students[students[i].s] = i;
    }


    map<int, BIT<int>> shift;

    for(int s = -1; s <= 1; s++){
        shift[s].init(m+5);
        for(int i = 0; i < m; i++){
            int teacher_ind = i+s;
            if(teacher_ind < 0 || teacher_ind >= m){
                shift[s].add(i, 1);
            }
            else if(teachers[teacher_ind] < students[i].f){
                shift[s].add(i, 1);
            }
        }
    }

    // Tree<pair<frac, int>> ranks;

    // for(int i = 0; i < m; i++){
    //     ranks.insert(students[i]);
    // }

    string ans;
    for(int i = 0; i < m; i++){
        for(auto u: b[i]){
            pair<frac, int> cur_student = mp(frac(b_sum[i], sz(b[i])), i);
            pair<frac, int> new_student = mp(frac(b_sum[i]-u, sz(b[i])-1), -1);
            int old_ind = r_students[i];
            int new_ind = lower_bound(all(students), new_student)-students.begin();
            if(cur_student < new_student){
                new_ind--;
            }

            bool works = 1;
            if(new_ind <= old_ind){
                if(shift[0].sum(0, new_ind-1) > 0){
                    works = 0;
                }
                else if(teachers[new_ind] < new_student.f){
                    works = 0;
                }
                else if(shift[1].sum(new_ind, old_ind-1) > 0){
                    works = 0;
                }
                else if(shift[0].sum(old_ind+1, m-1) > 0){
                    works = 0;
                }
            }
            else{
                if(shift[0].sum(0, old_ind-1) > 0){
                    works = 0;
                }
                else if(teachers[new_ind] < new_student.f){
                    works = 0;
                }
                else if(shift[-1].sum(old_ind+1, new_ind) > 0){
                    works = 0;
                }
                else if(shift[0].sum(new_ind+1, m-1) > 0){
                    works = 0;
                }
            }
            ans.pb(char('0'+works));
        }
    }
    cout << ans << "\n";

}

void solve(){
    int T = 1;
    cin >> T;
    for(int t = 1; t <= T; t++){
        solveTestCase();
    }
}

}; //EFF END

int main() {
    setIO();
    Eff e; e.solve();
    // you should actually read the stuff at the bottom
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
*/