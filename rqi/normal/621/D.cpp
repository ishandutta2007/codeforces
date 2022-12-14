#include <bits/stdc++.h>
using namespace std;
 
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
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 
 
template<class T> bool ckmin(T& a, const T& b) { 
    return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { 
    return a < b ? a = b, 1 : 0; } 
int pct(int x) { return __builtin_popcount(x); } 
int bits(int x) { return 31-__builtin_clz(x); } // floor(log2(x)) 
int cdiv(int a, int b) { return a/b+!(a<0||a%b == 0); } // division of a by b rounded up, assumes b > 0 
int fstTrue(function<bool(int)> f, int lo, int hi) {
    hi ++; assert(lo <= hi); // assuming f is increasing
    while (lo < hi) { // find first index such that f is true 
        int mid = (lo+hi)/2; 
        f(mid) ? hi = mid : lo = mid+1; 
    } 
    return lo;
}
 
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
str ts(char c) { return str(1,c); }
str ts(bool b) { return b ? "true" : "false"; }
str ts(const char* s) { return (str)s; }
str ts(str s) { return s; }
template<class A> str ts(complex<A> c) { 
    stringstream ss; ss << c; return ss.str(); }
str ts(vector<bool> v) { 
    str res = "{"; F0R(i,sz(v)) res += char('0'+v[i]);
    res += "}"; return res; }
template<size_t SZ> str ts(bitset<SZ> b) {
    str res = ""; F0R(i,SZ) res += char('0'+b[i]);
    return res; }
template<class A, class B> str ts(pair<A,B> p);
template<class T> str ts(T v) { // containers with begin(), end()
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
    cerr << ts(h); if (sizeof...(t)) cerr << ", ";
    DBG(t...); }
#ifdef LOCAL // compile with -DLOCAL
#define dbg(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define dbg(...) 0
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
 
const ld eps = 0.000000001;
bool useless[15];
string output[15];
ld ans[15];
 
int main() {
    setIO();
    ld x, y, z;
    cin >> x >> y >> z;
    useless[4] = useless[8] = useless[12] = 1;
    output[1] = "x^y^z";
    output[2] = "x^z^y";
    output[3] = "(x^y)^z";
    output[5] = "y^x^z";
    output[6] = "y^z^x";
    output[7] = "(y^x)^z";
    output[9] = "z^x^y";
    output[10] = "z^y^x";
    output[11] = "(z^x)^y";
 
    if(x > 1.01 && y > 1.01 && z > 1.01){
        ans[1] = log(log(x))+z*log(y);
        ans[2] = log(log(x))+y*log(z);
        ans[3] = log(log(x))+log(y)+log(z);
        ans[5] = log(log(y))+z*log(x);
        ans[6] = log(log(y))+x*log(z);
        ans[7] = log(log(y))+log(x)+log(z);
        ans[9] = log(log(z))+y*log(x);
        ans[10] = log(log(z))+x*log(y);
        ans[11] = log(log(z))+log(x)+log(y);
 
        ld val = -INF;
        int ind = -1;
        for(int i = 1; i <= 12; i++){
            if(useless[i] == 1) continue;
            if(ans[i] > val+eps){
                ind = i;
                val = ans[i];
            }
        }
 
        ps(output[ind]);
        return 0;
    }
    else if(x < 1.01 && y < 1.01 && z < 1.01){
        if(abs(x-1.00) < eps){
            ps(output[1]);
            return 0;
        }
        if(abs(y-1.00) < eps){
            ps(output[5]);
            return 0;
        }
        if(abs(z-1.00) < eps){
            ps(output[9]);
            return 0;
        }
        ans[1] = log(-log(x))+z*log(y);
        ans[2] = log(-log(x))+y*log(z);
        ans[3] = log(-log(x))+log(y)+log(z);
        ans[5] = log(-log(y))+z*log(x);
        ans[6] = log(-log(y))+x*log(z);
        ans[7] = log(-log(y))+log(x)+log(z);
        ans[9] = log(-log(z))+y*log(x);
        ans[10] = log(-log(z))+x*log(y);
        ans[11] = log(-log(z))+log(x)+log(y);
        ld val = INF;
        int ind = -1;
        for(int i = 1; i <= 12; i++){
            if(useless[i] == 1) continue;
            if(ans[i] < val-eps){
                ind = i;
                val = ans[i];
            }
        }
 
        ps(output[ind]);
    }
    else{
        if(x < 1.01){
            useless[1] = useless[2] = useless[3] = 1;
        }
        else{
            ans[1] = log(log(x))+z*log(y);
            ans[2] = log(log(x))+y*log(z);
            ans[3] = log(log(x))+log(y)+log(z);
        }
        if(y < 1.01){
            useless[5] = useless[6] = useless[7] = 1;
        }
        else{
            ans[5] = log(log(y))+z*log(x);
            ans[6] = log(log(y))+x*log(z);
            ans[7] = log(log(y))+log(x)+log(z);
        }
        if(z < 1.01){
            useless[9] = useless[10] = useless[11] = 1;
        }
        else{
            ans[9] = log(log(z))+y*log(x);
            ans[10] = log(log(z))+x*log(y);
            ans[11] = log(log(z))+log(x)+log(y);
        }
 
        ld val = -INF;
        int ind = -1;
        for(int i = 1; i <= 12; i++){
            if(useless[i] == 1) continue;
            if(ans[i] > val+eps){
                ind = i;
                val = ans[i];
            }
        }
        ps(output[ind]);
        return 0;
    }
    // you should actually read the stuff at the bottom
}
 
/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
*/