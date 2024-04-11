#include<bits/stdc++.h>
using namespace std ;

#define ll              long long 
#define pb              push_back
#define all(v)          v.begin(),v.end()
#define sz(a)           (ll)a.size()
#define F               first
#define S               second
#define INF             2000000000000000000
#define popcount(x)     __builtin_popcountll(x)
#define pll             pair<ll,ll>
#define pii             pair<int,int>
#define ld              long double

const int M = 1000000007;
const int MM = 998244353;

template<typename T, typename U> static inline void amin(T &x, U y){ if(y<x) x=y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x<y) x=y; }

#ifdef LOCAL
#define debug(...) debug_out(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) 2401
#endif

    
const int MOD=1000000007;
struct Mint {
    int val;
 
    Mint(long long v = 0) {
        if (v < 0)
            v = v % MOD + MOD;
        if (v >= MOD)
            v %= MOD;
        val = v;
    }
 
    static int mod_inv(int a, int m = MOD) {
        int g = m, r = a, x = 0, y = 1;
        while (r != 0) {
            int q = g / r;
            g %= r; swap(g, r);
            x -= q * y; swap(x, y);
        } 
        return x < 0 ? x + m : x;
    } 
    explicit operator int() const {
        return val;
    }
    Mint& operator+=(const Mint &other) {
        val += other.val;
        if (val >= MOD) val -= MOD;
        return *this;
    }
    Mint& operator-=(const Mint &other) {
        val -= other.val;
        if (val < 0) val += MOD;
        return *this;
    }
    static unsigned fast_mod(uint64_t x, unsigned m = MOD) {
           #if !defined(_WIN32) || defined(_WIN64)
                return x % m;
           #endif
           unsigned x_high = x >> 32, x_low = (unsigned) x;
           unsigned quot, rem;
           asm("divl %4\n"
            : "=a" (quot), "=d" (rem)
            : "d" (x_high), "a" (x_low), "r" (m));
           return rem;
    }
    Mint& operator*=(const Mint &other) {
        val = fast_mod((uint64_t) val * other.val);
        return *this;
    }
    Mint& operator/=(const Mint &other) {
        return *this *= other.inv();
    }
    friend Mint operator+(const Mint &a, const Mint &b) { return Mint(a) += b; }
    friend Mint operator-(const Mint &a, const Mint &b) { return Mint(a) -= b; }
    friend Mint operator*(const Mint &a, const Mint &b) { return Mint(a) *= b; }
    friend Mint operator/(const Mint &a, const Mint &b) { return Mint(a) /= b; }
    Mint& operator++() {
        val = val == MOD - 1 ? 0 : val + 1;
        return *this;
    }
    Mint& operator--() {
        val = val == 0 ? MOD - 1 : val - 1;
        return *this;
    }
    Mint operator++(int32_t) { Mint before = *this; ++*this; return before; }
    Mint operator--(int32_t) { Mint before = *this; --*this; return before; }
    Mint operator-() const {
        return val == 0 ? 0 : MOD - val;
    }
    bool operator==(const Mint &other) const { return val == other.val; }
    bool operator!=(const Mint &other) const { return val != other.val; }
    Mint inv() const {
        return mod_inv(val);
    }
    Mint power(long long p) const {
        assert(p >= 0);
        Mint a = *this, result = 1;
        while (p > 0) {
            if (p & 1)
                result *= a;
 
            a *= a;
            p >>= 1;
        }
        return result;
    }
    friend ostream& operator << (ostream &stream, const Mint &m) {
        return stream << m.val;
    }
    friend istream& operator >> (istream &stream, Mint &m) {
        return stream>>m.val;   
    }
};


const int N = 200005,up = 3;
struct node
{
    Mint sum[up];
    int cnt;
    node() {
        for(int i=0;i<up;++i) {
            sum[i] = 0;
        }
        cnt = 0;
    }
}fake;
struct SEGTREE
{
    ll a[N];
    SEGTREE(){ }
    node tree[4*N];
    ll lazy[4*N];
    inline node combine(node a,node b)
    {
        node ret;
        ret.cnt = a.cnt + b.cnt;
        for(int i=0;i<up;++i) {
            ret.sum[i] = a.sum[i] + b.sum[i];
        }
        return ret;
    }
    inline node make_node(ll val,ll x)
    {
        node ret;
        ret.cnt = x;
        Mint cur = val;
        for(int i=0;i<up;++i) {
            ret.sum[i] = val;
            val *= val;
        }
        return ret;
    }
    void buildTree(ll v,ll st,ll en)
    {
        if(st==en)
        {
            tree[v]=make_node(a[st],0);
            return ;
        }
        ll mid=(st+en)>>1;
        buildTree(v<<1,st,mid);
        buildTree(v<<1 | 1,mid+1,en);
        tree[v]=combine(tree[v<<1],tree[v<<1 | 1]);
    }
    void update(ll v,ll st,ll en,ll in,ll val, ll x)
    {
        ll mid=(st+en)>>1;
        if(st==en)
        {
            tree[v]=make_node(val, x);
            a[st]=val;
            return ;
        }
        if(in<=mid)
            update(v<<1,st,mid,in,val,x);
        else
            update(v<<1 | 1,mid+1,en,in,val,x);
        tree[v]=combine(tree[v<<1],tree[v<<1 | 1]);
    }
    node query(ll v,ll st,ll en,ll l,ll r)
    {
        if(en<l || st>r)
            return fake;
        if(st>=l && en<=r)
            return tree[v];
        ll mid=(st+en)>>1;
        return combine(query(v<<1,st,mid,l,r),query(v<<1 | 1,mid+1,en,l,r));
    }
}seg;


int _runtimeTerror_()
{
    int n, Q;
    cin >> n >> Q;
    vector<int> a(n+1);
    for(int i=1;i<=n;++i) {
        cin >> a[i];
    }
    vector<vector<array<int,3>>> g(n+1);
    for(int i=1;i<=Q;++i) {
        int l, r, d;
        cin >> l >> r >> d;
        g[r].push_back({l, d, i});
    }
    vector<string> ans(Q+1,"No");

    for(int i=1;i<=n;++i) {
        seg.a[i] = 0;
    }
    seg.buildTree(1,1,n);
    map<int,int> last;
    for(int i=1;i<=n;++i) {
        if(last.count(a[i])) {
            seg.update(1,1,n,last[a[i]],0,0);
        }
        seg.update(1,1,n,i,a[i],1);
        for(auto &[l,d,q]:g[i]) {
            auto val = seg.query(1,1,n,l,i);
            Mint f = val.sum[0];
            f *= 2;
            f /= val.cnt;
            f -= (val.cnt - 1) * Mint(d);
            f /= 2; 
            ll cnt = val.cnt;
            // debug(f.val,cnt);
            Mint sq = f * f * cnt + Mint(cnt) * (cnt - 1) * (2 * cnt - 1) / 6 * d * d + 2 * f * d * cnt * (cnt - 1) / 2;
            if(sq == val.sum[1]) {
                ans[q] = "Yes";
            }
            // debug(sq.val);
        }   
        last[a[i]] = i;    
    }
    for(int i=1;i<=Q;++i) {
        cout << ans[i] << "\n";
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifdef runSieve
        sieve();
    #endif
    #ifdef NCR
        initialize();
    #endif
    int TESTS = 1;
    //cin >> TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}