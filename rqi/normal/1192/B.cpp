#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/rope>
 
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
 
typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;
 
typedef pair<ll, ll> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
 
typedef vector<ll> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;
 
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;
 
#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define F0R(i, a) for (ll i = 0; i < (a); i++)
#define FORd(i,a,b) for (ll i = (b)-1; i >= (a); i--)
#define F0Rd(i,a) for (ll i = (a)-1; i >= 0; i--)
#define trav(a, x) for (auto& a : x)
 
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
 
#define sz(x) (ll)x.size()
#define all(x) begin(x), end(x)
#define rsz resize
 
const ll MOD = 998244353; // 998244353
const ll INF = 1e18;
const ll MX = 200005;
const ld PI = 4*atan((ld)1);
 
template<class T> void ckmin(T &a, T b) { a = min(a, b); }
template<class T> void ckmax(T &a, T b) { a = max(a, b); }
 
namespace input {
    template<class T> void re(complex<T>& x);
    template<class T1, class T2> void re(pair<T1,T2>& p);
    template<class T> void re(vector<T>& a);
    template<class T, size_t SZ> void re(array<T,SZ>& a);
 
    template<class T> void re(T& x) { cin >> x; }
    void re(double& x) { string t; re(t); x = stod(t); }
    void re(ld& x) { string t; re(t); x = stold(t); }
    template<class Arg, class... Args> void re(Arg& first, Args&... rest) { 
        re(first); re(rest...); 
    }
 
    template<class T> void re(complex<T>& x) { T a,b; re(a,b); x = cd(a,b); }
    template<class T1, class T2> void re(pair<T1,T2>& p) { re(p.f,p.s); }
    template<class T> void re(vector<T>& a) { F0R(i,sz(a)) re(a[i]); }
    template<class T, size_t SZ> void re(array<T,SZ>& a) { F0R(i,SZ) re(a[i]); }
}
 
using namespace input;
 
namespace output {
    template<class T1, class T2> void pr(const pair<T1,T2>& x);
    template<class T, size_t SZ> void pr(const array<T,SZ>& x);
    template<class T> void pr(const vector<T>& x);
    template<class T> void pr(const set<T>& x);
    template<class T1, class T2> void pr(const map<T1,T2>& x);
 
    template<class T> void pr(const T& x) { cout << x; }
    template<class Arg, class... Args> void pr(const Arg& first, const Args&... rest) { 
        pr(first); pr(rest...); 
    }
 
    template<class T1, class T2> void pr(const pair<T1,T2>& x) { 
        pr("{",x.f,", ",x.s,"}"); 
    }
    template<class T> void prContain(const T& x) {
        pr("{");
        bool fst = 1; for (const auto& a: x) pr(!fst?", ":"",a), fst = 0; // const needed for vector<bool>
        pr("}");
    }
    template<class T, size_t SZ> void pr(const array<T,SZ>& x) { prContain(x); }
    template<class T> void pr(const vector<T>& x) { prContain(x); }
    template<class T> void pr(const set<T>& x) { prContain(x); }
    template<class T1, class T2> void pr(const map<T1,T2>& x) { prContain(x); }
    
    void ps() { pr("\n"); }
    template<class Arg> void ps(const Arg& first) { 
        pr(first); ps(); // no space at end of line
    }
    template<class Arg, class... Args> void ps(const Arg& first, const Args&... rest) { 
        pr(first," "); ps(rest...); // prll w/ spaces
    }
}
 
using namespace output;
 
namespace io {
    void setIn(string s) { freopen(s.c_str(),"r",stdin); }
    void setOut(string s) { freopen(s.c_str(),"w",stdout); }
    void setIO(string s = "") {
        ios_base::sync_with_stdio(0); cin.tie(0); // fast I/O
        if (sz(s)) { setIn(s+".in"), setOut(s+".out"); } // for USACO
    }
}
 
using namespace io;
 
template<class T> T invGeneral(T a, T b) {
    a %= b; if (a == 0) return b == 1 ? 0 : -1;
    T x = invGeneral(b,a); 
    return x == -1 ? -1 : ((1-(ll)b*x)/a+b)%b;
}
 
template<class T> struct modular {
    T val; 
    explicit operator T() const { return val; }
    modular() { val = 0; }
    modular(const ll& v) { 
        val = (-MOD <= v && v <= MOD) ? v : v % MOD;
        if (val < 0) val += MOD;
    }
    
    friend ostream& operator<<(ostream& os, const modular& a) { return os << a.val; }
    friend bool operator==(const modular& a, const modular& b) { return a.val == b.val; }
    friend bool operator!=(const modular& a, const modular& b) { return !(a == b); }
    friend bool operator<(const modular& a, const modular& b) { return a.val < b.val; }
 
    modular operator-() const { return modular(-val); }
    modular& operator+=(const modular& m) { if ((val += m.val) >= MOD) val -= MOD; return *this; }
    modular& operator-=(const modular& m) { if ((val -= m.val) < 0) val += MOD; return *this; }
    modular& operator*=(const modular& m) { val = (ll)val*m.val%MOD; return *this; }
    friend modular pow(modular a, ll p) {
        modular ans = 1; for (; p; p /= 2, a *= a) if (p&1) ans *= a;
        return ans;
    }
    friend modular inv(const modular& a) { 
        auto i = invGeneral(a.val,MOD); assert(i != -1);
        return i;
    } // equivalent to return exp(b,MOD-2) if MOD is prime
    modular& operator/=(const modular& m) { return (*this) *= inv(m); }
    
    friend modular operator+(modular a, const modular& b) { return a += b; }
    friend modular operator-(modular a, const modular& b) { return a -= b; }
    friend modular operator*(modular a, const modular& b) { return a *= b; }
    
    friend modular operator/(modular a, const modular& b) { return a /= b; }
};
 
typedef modular<ll> mi;
typedef pair<mi,mi> pmi;
typedef vector<mi> vmi;
typedef vector<pmi> vpmi;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

/**
 * Description: 1D range update, range query
 * Source: USACO Counting Haybales
 * Verification: SPOJ Horrible
 */

template<class T, ll SZ> struct LazySegTree {
    T sum[2*SZ], mx[2*SZ], mn[2*SZ], lazy[2*SZ], ansval[2*SZ], ab[2*SZ], cb[2*SZ]; // set SZ to a power of 2
    
    LazySegTree() {
        memset (sum,0,sizeof sum);
        memset (mx,0,sizeof mx);
        memset (lazy,0,sizeof lazy);
        memset (ansval, 0, sizeof ansval);
        memset (ab, 0, sizeof ab);
        memset (cb, 0, sizeof cb);
    }
    
    void push(ll ind, ll L, ll R) { 
        sum[ind] += (R-L+1)*lazy[ind];
        mx[ind] += lazy[ind];
        mn[ind] += lazy[ind];
        ab[ind] -= lazy[ind];
        cb[ind]-=lazy[ind];
        if (L != R) lazy[2*ind] += lazy[ind], lazy[2*ind+1] += lazy[ind];
        lazy[ind] = 0;
    }
    void pull(ll ind) {
        sum[ind] = sum[2*ind]+sum[2*ind+1];
        mx[ind] = max(mx[2*ind],mx[2*ind+1]);
        mn[ind] = min(mn[2*ind], mn[2*ind+1]);
        ab[ind] = max(ab[2*ind], ab[2*ind+1]);
        ab[ind] = max(ab[ind], mx[2*ind]-2*mn[2*ind+1]);
        cb[ind] = max(cb[2*ind], cb[2*ind+1]);
        cb[ind] = max(cb[ind], mx[2*ind+1]-2*mn[2*ind]);
        ansval[ind] = max(ansval[2*ind], ansval[2*ind+1]);
        ansval[ind] = max(ansval[ind], ab[2*ind]+mx[2*ind+1]);
        ansval[ind] = max(ansval[ind], cb[2*ind+1]+mx[2*ind]);
    }
    
    void build() {
        FORd(i,1,SZ) pull(i);
    }
    
    // Good up to here
    
    array<T, 5> qansval(ll lo, ll hi, ll ind = 1, ll L = 0, ll R = SZ-1){
        push(ind, L, R);
        T anses[5]; // ansval, ab, cb, mx, mn
        if (lo > R || L > hi) return {0, 0, 0, 0, INF};
        if (lo <= L && R <= hi) return {ansval[ind], ab[ind], cb[ind], mx[ind], mn[ind]};
        ll M = (L+R)/2;
        T ransval, rab, rcb, rmx, rmn;
        array<T, 5> lanses = qansval(lo, hi, 2*ind, L, M);
        array<T, 5> ranses = qansval(lo, hi, 2*ind+1, M+1, R);
        rmx = max(lanses[3], ranses[3]);
        
        rmn = min(lanses[4], ranses[4]);
        
        rab = max(lanses[1], ranses[1]);
        rab = max(rab, lanses[3]-2*ranses[4]);
        
        rcb = max(lanses[2], ranses[2]);
        rcb = max(rcb, ranses[3]-2*lanses[4]);
        
        ransval = max(lanses[0], ranses[0]);
        ransval = max(ransval, lanses[1]+ranses[3]);
        ransval = max(ransval, ranses[2]+lanses[3]);
        return {ransval, rab, rcb, rmx, rmn};
    }
    T qsum(ll lo, ll hi, ll ind = 1, ll L = 0, ll R = SZ-1) {
        push(ind,L,R);
        if (lo > R || L > hi) return 0;
        if (lo <= L && R <= hi) return sum[ind];
        
        ll M = (L+R)/2;
        return qsum(lo,hi,2*ind,L,M) + qsum(lo,hi,2*ind+1,M+1,R);
    }

    T qmax(ll lo, ll hi, ll ind = 1, ll L = 0, ll R = SZ-1) {
        push(ind,L,R);
        if (lo > R || L > hi) return 0;
        if (lo <= L && R <= hi) return mx[ind];
        
        ll M = (L+R)/2;
        return max(qmax(lo,hi,2*ind,L,M), qmax(lo,hi,2*ind+1,M+1,R));
    }
    
    void upd(ll lo, ll hi, ll inc, ll ind = 1, ll L = 0, ll R = SZ-1) {
        push(ind,L,R);
        if (hi < L || R < lo) return;
        if (lo <= L && R <= hi) {
            lazy[ind] = inc;
            push(ind,L,R);
            return;
        }
        
        ll M = (L+R)/2;
        upd(lo,hi,inc,2*ind,L,M); upd(lo,hi,inc,2*ind+1,M+1,R);
        pull(ind);
    }
};

vector<pair<ll ,ll>> edges[100005];
ll par[100005];
ll indcount = 0;
ll matchind[200009];
pi firstlast[100005];
ll firstdepths[100005];
LazySegTree<ll, 2622144> treedeps;
vector<pair<pair<ll ,ll>, ll>> edges1;
void assignpar(ll a){
    for(auto u: edges[a]){
    	//cout << a << " " << u.f << "\n";
        if(par[a] == u.f) continue;
        par[u.f] = a;
        assignpar(u.f);
    }
}

void setindex(ll a){
    matchind[indcount] = a;
    firstlast[a].s = indcount;
    if(firstlast[a].f == 0) firstlast[a].f = indcount;
    indcount++;
    for(auto u: edges[a]){
        if(par[a] == u.f) continue;
        setindex(u.f);
        matchind[indcount] = a;
        firstlast[a].s = indcount;
        if(firstlast[a].f == 0) firstlast[a].f = indcount;
        indcount++;
    }
}
void setdepth(ll a){
    for(auto u: edges[a]){
        if(par[a] == u.f) continue;
        firstdepths[u.f] = firstdepths[a] + u.s;
        setdepth(u.f);
    }
}

int main() {
    setIO();
    ll n, q;
    ll w;
    cin >> n >> q >> w;
    for(ll i = 0; i < n-1; i++){
        ll a, b;
        ll c;
        cin >> a >> b >> c;
        edges[a].pb(mp(b, c));
        edges[b].pb(mp(a, c));
        edges1.pb(mp(mp(a, b), c));
    }
    assignpar(1);
    setindex(1);
    setdepth(1);
    firstlast[1].f = 0;
    for(ll i = 0; i <= (n-1)*2; i++){
        treedeps.upd(i, i, firstdepths[matchind[i]]);
    }
    ll last = 0;
    
    /*for(ll i = 1; i <= 10; i++){
    	//cout << par[i] << "\n";
    }*/
    
    for(ll i =0; i < q; i++){
    	ll d;
    	ll e;
    	cin >> d >> e;
    	ll dp = (d+(last % (n-1))) % (n-1);
    	ll ep = (e+(last % w)) % w;
    	ll pind;
    	if(par[edges1[dp].f.f] == edges1[dp].f.s) pind = edges1[dp].f.f;
    	else pind = edges1[dp].f.s;
    	treedeps.upd(firstlast[pind].f, firstlast[pind].s, ep-edges1[dp].s);
    	edges1[dp].s = ep;
    	
    	last = (treedeps.qansval(0, (n-1)*2))[0];
    	cout << last << "\n";
    }
    /*
    Plan: 
    1. Calculate depth of every node - DONE
    2. Make lazy segment tree that handles addition to a subtree (update) and query = a-2*b+c - DONE
    3.1 build the initial tree
    3. Query across entire tree and update accordingly
    */
    
}

/* stuff you should look for
    * ll overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/