#include <bits/stdc++.h>
using namespace std;
using namespace chrono; 

typedef long long ll;
typedef long double ld;
typedef double db; 
typedef string str; 

typedef pair<int,int> pi;
typedef pair<ll,ll> pl; 
typedef pair<db,db> pd; 

typedef vector<int> vi; 
typedef vector<ll> vl; 
typedef vector<db> vd; 
typedef vector<str> vs; 
typedef vector<pi> vpi;
typedef vector<pl> vpl; 
typedef vector<pd> vpd; 

#define mp make_pair 
#define f first
#define s second
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend() 
#define rsz resize
#define ins insert 
#define ft front() 
#define bk back()
#define pf push_front 
#define pb push_back
#define eb emplace_back 
#define lb lower_bound 
#define ub upper_bound 

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)

const int MOD = 1e9+7; // 998244353;
const int MX = 2e5+5; 
const ll INF = 1e18; 
const ld PI = acos((ld)-1);
const int xd[4] = {1,0,-1,0}, yd[4] = {0,1,0,-1}; 

template<class T> bool ckmin(T& a, const T& b) { 
    return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { 
    return a < b ? a = b, 1 : 0; } 
int pct(int x) { return __builtin_popcount(x); } 
int bit(int x) { return 31-__builtin_clz(x); } // floor(log2(x)) 
int cdiv(int a, int b) { return a/b+!(a<0||a%b == 0); } // division of a by b rounded up, assumes b > 0 

// INPUT
template<class A> void re(complex<A>& c);
template<class A, class B> void re(pair<A,B>& p);
template<class A> void re(vector<A>& v);
template<class A, size_t SZ> void re(array<A,SZ>& a);

template<class T> void re(T& x) { cin >> x; }
void re(db& d) { str t; re(t); d = stod(t); }
void re(ld& d) { str t; re(t); d = stold(t); }
template<class H, class... T> void re(H& h, T&... t) { re(h); re(t...); }

template<class A> void re(complex<A>& c) { A a,b; re(a,b); c = {a,b}; }
template<class A, class B> void re(pair<A,B>& p) { re(p.f,p.s); }
template<class A> void re(vector<A>& x) { trav(a,x) re(a); }
template<class A, size_t SZ> void re(array<A,SZ>& x) { trav(a,x) re(a); }

// TO_STRING
#define ts to_string
template<class A, class B> str ts(pair<A,B> p);
template<class A> str ts(complex<A> c) { return ts(mp(c.real(),c.imag())); }
str ts(bool b) { return b ? "true" : "false"; }
str ts(char c) { str s = ""; s += c; return s; }
str ts(str s) { return s; }
str ts(const char* s) { return (str)s; }
str ts(vector<bool> v) { 
    bool fst = 1; str res = "{";
    F0R(i,sz(v)) {
        if (!fst) res += ", ";
        fst = 0; res += ts(v[i]);
    }
    res += "}"; return res;
}
template<size_t SZ> str ts(bitset<SZ> b) {
    str res = ""; F0R(i,SZ) res += char('0'+b[i]);
    return res; }
template<class T> str ts(T v) {
    bool fst = 1; str res = "{";
    for (const auto& x: v) {
        if (!fst) res += ", ";
        fst = 0; res += ts(x);
    }
    res += "}"; return res;
}
template<class A, class B> str ts(pair<A,B> p) {
    return "("+ts(p.f)+", "+ts(p.s)+")"; }

// OUTPUT
template<class A> void pr(A x) { cout << ts(x); }
template<class H, class... T> void pr(const H& h, const T&... t) { 
    pr(h); pr(t...); }
void ps() { pr("\n"); } // print w/ spaces
template<class H, class... T> void ps(const H& h, const T&... t) { 
    pr(h); if (sizeof...(t)) pr(" "); ps(t...); }

// DEBUG
void DBG() { cerr << "]" << endl; }
template<class H, class... T> void DBG(H h, T... t) {
    cerr << to_string(h); if (sizeof...(t)) cerr << ", ";
    DBG(t...); }
#ifdef LOCAL // compile with -DLOCAL
#define dbg(...) cerr << "[" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define dbg(...) 42
#endif

// FILE I/O
void setIn(string s) { freopen(s.c_str(),"r",stdin); }
void setOut(string s) { freopen(s.c_str(),"w",stdout); }
void unsyncIO() { ios_base::sync_with_stdio(0); cin.tie(0); }
void setIO(string s = "") {
    unsyncIO();
    // cin.exceptions(cin.failbit); 
    // throws exception when do smth illegal
    // ex. try to read letter into int
    if (sz(s)) { setIn(s+".in"), setOut(s+".out"); } // for USACO
}

mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 

bool adj[20][20];

/**
 * Description: 2D matrix operations. Change \texttt{d} 
     * to array if possible.
 * Source: KACTL
 * Verification: https://dmoj.ca/problem/si17c1p5, SPOJ MIFF
 */

template<class T> struct Mat {
    int r,c; vector<vector<T>> d;
    Mat(int _r, int _c) : r(_r), c(_c) { 
        d.assign(r,vector<T>(c)); }
    Mat() : Mat(0,0) {} 
    Mat(const vector<vector<T>>&_d) : 
        r(sz(_d)), c(sz(_d[0])) { d = _d; }
    /// friend void pr(const Mat& m) { pr(m.d); }
    Mat& operator+=(const Mat& m) {
        /// assert(r == m.r && c == m.c);
        F0R(i,r) F0R(j,c) d[i][j] += m.d[i][j];
        return *this; }
    Mat& operator-=(const Mat& m) {
        /// assert(r == m.r && c == m.c);
        F0R(i,r) F0R(j,c) d[i][j] -= m.d[i][j];
        return *this; }
    Mat operator*(const Mat& m) {
        assert(c == m.r); Mat x(r,m.c);
        F0R(i,r) F0R(j,c){
            if(d[i][j] == 0) continue;
            F0R(k,m.c) x.d[i][k] += d[i][j]*m.d[j][k];
        }
        return x; }
    Mat operator+(const Mat& m) { return Mat(*this)+=m; }
    Mat operator-(const Mat& m) { return Mat(*this)-=m; }
    Mat& operator*=(const Mat& m) { return *this = (*this)*m; }
    friend Mat pow(Mat m, ll p) {
        assert(m.r == m.c && p >= 0);
        Mat res(m.r,m.c); F0R(i,m.r) res.d[i][i] = 1;
        for (; p; p /= 2, m *= m) if (p&1) res *= m;
        return res;
    }
};

ll runs[1<<19][19];
map<vi, ll> m; // size 385
ll aanses[1<<19][19]; 
ll powa[30][30];
ll eds[30][30];
int main() {
    setIO();
    for(int i = 0; i < 30; i++){
        ll a = ll(i);
        ll b = 1;
        for(int j = 0; j < 30; j++){
            powa[i][j] = b;
            b*=a;
        }
    }

    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        for(int j = 0; j < n; j++){
            if(s[j] == '1'){
                adj[i][j] = 1;
            }
        }
    }

    auto s1 = high_resolution_clock::now(); 

    for(int i = 1; i < (1<<n); i++){//2^n*n^3
        //int bitnum = __builtin_popcount((unsigned int)(i));
        vi nums;

        for(int j = 0; j < n; j++){
            if(((i>>j) & 1) == 0) continue;
            nums.pb(j);
        }

        if(sz(nums) == 0) continue;
        //ps(i, nums);
        cout.flush();
        vl nods(sz(nums), 1);

        for(int j = 0; j < sz(nums); j++){
            for(int k = 0; k < sz(nums); k++){ 
                eds[j][k] = ll(adj[nums[j]][nums[k]]);
            }
        }

        for(int j = 0; j <= n; j++){
            ll sum = 0;
            for(int k = 0; k < sz(nums); k++){
                sum+=nods[k];
            }
            runs[i][j] = sum;
            vl nods1(sz(nums), 0);
            F0R(i,sz(nums)) F0R(j,sz(nums)){
                nods1[i] += eds[i][j]*nods[j];
            }
            swap(nods, nods1);
        }
    }

    auto s2 = high_resolution_clock::now(); 
    /*for(int i = 0; i < 8; i++){
        for(int j = 0; j <= 3; j++){
            ps(i, j, runs[i][j]);
        }
    }*/

    for(int i = 0; i < (1<<(n-1)); i++){ //2^n*n
        //0 = a
        vi lens;
        int curlen = 0;
        int zeroes = 0;
        for(int j = 0; j < n-1; j++){
            int val = (i>>j) & 1;
            if(val == 1){
                curlen++;
            }
            else{
                zeroes++;
                if(curlen != 0) lens.pb(curlen);
                curlen = 0;
            }
        }
        if(curlen != 0) lens.pb(curlen);
        sort(all(lens));
        m[lens];
    }

    auto s3 = high_resolution_clock::now(); 


    for(auto &u: m){ //385*2^n*n
        vi st = u.f; 
        int znum = n-1; //number of 'a's in sequence
        for(auto x: st) znum-=x;
        for(int i = 0; i < (1<<n); i++){ // calculate answer for each subset + u val
            int bitnum = __builtin_popcount((unsigned int)(i));
            ll zed = ll(bitnum);
            zed = ll(n)-zed; //number of zeroes
            zed = zed % 2;
            if(zed == 0) zed = 1; //pos PIE
            else zed = -1; // neg PIE
            for(auto x: st){
                zed*=runs[i][x];
                //vi b = {1};
                //if(st == b) ps(runs[i][x]);
            }
            zed*=powa[ll(bitnum)][znum+1-sz(st)]; // 0^0 = 1
            u.s+=zed; 
            //vi b = {1};
            //if(st == b) ps(zed, bitnum, znum+1);
        }
    }
    //ps(m);

    auto s4 = high_resolution_clock::now(); 

    for(int i = 0; i < (1<<(n-1)); i++){ //2^n*log(385)*n
        //0 = a
        vi lens;
        int curlen = 0;
        int zeroes = 0;
        for(int j = 0; j < n-1; j++){
            int val = (i>>j) & 1;
            if(val == 1){
                curlen++;
            }
            else{
                zeroes++;
                if(curlen != 0) lens.pb(curlen);
                curlen = 0;
            }
        }
        if(curlen != 0) lens.pb(curlen);
        sort(all(lens));
        aanses[i][0] = m[lens]; //preliminary answers.
    }

    auto s5 = high_resolution_clock::now(); 

    for(int j = 1; j <= n-1; j++){ //2^n*n
        int ind = j-1;
        for(int i = 0; i < (1<<(n-1)); i++){
            if(((i>>ind)&1) == 1){
                aanses[i][j] = aanses[i][j-1];
            }
            else{
                int ot = i^(1<<ind);
                aanses[i][j] = aanses[i][j-1]-aanses[ot][j-1];
            }
        }
    }

    auto s6 = high_resolution_clock::now(); 

    auto d1 = duration_cast<milliseconds>(s2-s1);
    auto d2 = duration_cast<milliseconds>(s3-s2);
    auto d3 = duration_cast<milliseconds>(s4-s3);
    auto d4 = duration_cast<milliseconds>(s5-s4);
    auto d5 = duration_cast<milliseconds>(s6-s5);

    //cout << d1.count() << "\n";
    //cout << d2.count() << "\n";
    //cout << d3.count() << "\n";
    //cout << d4.count() << "\n";
    //cout << d5.count() << "\n";

    for(int i = 0; i < (1<<(n-1)); i++){
        //cout << aanses[i][1];
        cout << aanses[i][n-1] << " ";
    }

    // you should actually read the stuff at the bottom
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
*/