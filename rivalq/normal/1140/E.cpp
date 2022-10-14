#include<bits/stdc++.h>
using namespace std ;

#define ll long long 
#define pb push_back
#define mem0(a) memset(a,0,sizeof(a))
#define mem1(a) memset(a,-1,sizeof(a))
#define memf(a) memset(a,false,sizeof(a))
#define all(v) v.begin(),v.end()
#define sz(a) (ll)a.size()
#define F first
#define S second
#define INF 2000000000000000000
#define endl "\n"
#define _time_ 1.0 * clock() / CLOCKS_PER_SEC
#define popcount(x) __builtin_popcountll(x)
#define pll pair<ll,ll> 
#define ld long double

const int M=1000000007;
const int MM=998244353;
const long double PI = acos(-1);

ll power(ll b,ll e,ll m)
{
    if(e==0) return 1;
    if(e&1) return b*power(b*b%m,e/2,m)%m;
    return power(b*b%m,e/2,m);
}
ll power( ll b, ll e)
{
    if(e==0) return 1;
    if(e&1) return b*power(b*b,e/2);
    return power(b*b,e/2);
}
template<typename T, typename U> static inline void amin(T &x, U y){ if(y<x) x=y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x<y) x=y; }
template<typename T, typename U> ostream& operator<<(ostream &os, const pair<T, U> &p)
{ 
    return os<<'('<<p.F<< ","<<p.S<<')'; 
}
    
const int MOD=998244353;
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

const int N=200005;

int a[N];
int odd[N];
int even[N];
Mint dp[N];

int _runtimeTerror_()
{
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;++i)
        cin>>a[i];
    for(int i=1;i<=n;++i)
    {
        if(i&1)
            odd[(i+1)/2]=a[i];
        else
            even[i/2]=a[i];
    }
    int os=(n+1)/2;
    int es=n/2;
    for(int i=0;i<=n;++i)
        dp[i]=0;
    Mint prval=1;
    int pridx=-1;
    Mint idxval=0;
    Mint ans=1;
    dp[1]=(odd[1]==-1?k:1);
    if(odd[1]!=-1)
        idxval=1,pridx=odd[1],prval=0;
    for(int i=2;i<=os;++i)
    {
        if(odd[i]==-1)
        {
            if(pridx==-1)
                prval=prval*(k-1);
            else
            {
                Mint tt=idxval;
                idxval=prval*(k-1);
                prval=prval*(k-2)+tt;
            }
            if(pridx==-1)
                dp[i]=prval*k;
            else
                dp[i]=idxval+prval*(k-1);
        }
        else
        {
            if(pridx==-1)
            {
                idxval=prval*(k-1);
                pridx=int(odd[i]);
                prval=0;
            }
            else
            {
                if(pridx==int(odd[i]))
                {
                    idxval=prval*(k-1);
                }
                else
                {
                    idxval=prval*(k-2)+idxval;
                }
                pridx=int(odd[i]);
                prval=0;
            }
            dp[i]=idxval;
        }
    }
    ans*=dp[os];
    //cout<<dp[os]<<'\n';
    for(int i=0;i<=n;++i)
        dp[i]=0;
    prval=1;
    pridx=-1;
    idxval=0;
    dp[1]=(even[1]==-1?k:1);
    if(even[1]!=-1)
        idxval=1,pridx=even[1],prval=0;
    for(int i=2;i<=es;++i)
    {
        if(even[i]==-1)
        {
            if(pridx==-1)
                prval=prval*(k-1);
            else
            {
                Mint tt=idxval;
                idxval=prval*(k-1);
                prval=prval*(k-2)+tt;
            }
            if(pridx==-1)
                dp[i]=prval*k;
            else
                dp[i]=idxval+prval*(k-1);
        }
        else
        {
            if(pridx==-1)
            {
                idxval=prval*(k-1);
                pridx=int(even[i]);
                prval=0;
            }
            else
            {
                if(pridx==int(even[i]))
                {
                    idxval=prval*(k-1);
                }
                else
                {
                    idxval=prval*(k-2)+idxval;
                }
                pridx=int(even[i]);
                prval=0;
            }
            dp[i]=idxval;
        }
    }
    ans*=dp[es];
    //cout<<dp[es]<<'\n';
    cout<<ans;
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
    int TESTS=1;
    //cin>>TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}