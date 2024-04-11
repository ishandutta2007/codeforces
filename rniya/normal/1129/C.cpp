#include <bits/stdc++.h>
using namespace std;
#define LOCAL
#pragma region Macros
typedef long long ll;
#define ALL(x) (x).begin(),(x).end()
const long long MOD=1000000007;
// const long long MOD=998244353;
const int INF=1e9;
const long long IINF=1e18;
const int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
const char dir[4]={'D','R','U','L'};

template<typename T>
istream &operator>>(istream &is,vector<T> &v){
    for (T &x:v) is >> x;
    return is;
}
template<typename T>
ostream &operator<<(ostream &os,const vector<T> &v){
    for (int i=0;i<v.size();++i){
        os << v[i] << (i+1==v.size()?"": " ");
    }
    return os;
}
template<typename T,typename U>
ostream &operator<<(ostream &os,const pair<T,U> &p){
    os << '(' << p.first << ',' << p.second << ')';
    return os;
}
template<typename T,typename U>
ostream &operator<<(ostream &os,const map<T,U> &m){
    os << '{';
    for (auto itr=m.begin();itr!=m.end();++itr){
        os << '(' << itr->first << ',' << itr->second << ')';
        if (++itr!=m.end()) os << ',';
        --itr;
    }
    os << '}';
    return os;
}
template<typename T>
ostream &operator<<(ostream &os,const set<T> &s){
    os << '{';
    for (auto itr=s.begin();itr!=s.end();++itr){
        os << *itr;
        if (++itr!=s.end()) os << ',';
        --itr;
    }
    os << '}';
    return os;
}

void debug_out(){cerr << '\n';}
template<class Head,class... Tail>
void debug_out(Head&& head,Tail&&... tail){
    cerr << head;
    if (sizeof...(Tail)>0) cerr << ", ";
    debug_out(move(tail)...);
}
#ifdef LOCAL
#define debug(...) cerr << " ";\
cerr << #__VA_ARGS__ << " :[" << __LINE__ << ":" << __FUNCTION__ << "]" << '\n';\
cerr << " ";\
debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

template<typename T> T gcd(T x,T y){return y!=0?gcd(y,x%y):x;}
template<typename T> T lcm(T x,T y){return x/gcd(x,y)*y;}

template<class T1,class T2> inline bool chmin(T1 &a,T2 b){
    if (a>b){a=b; return true;} return false;
}
template<class T1,class T2> inline bool chmax(T1 &a,T2 b){
    if (a<b){a=b; return true;} return false;
}
#pragma endregion

template<uint32_t mod> class modint{
    using i64=int64_t;
    using u32=uint32_t;
    using u64=uint64_t;
public:
    u32 v;
    constexpr modint(const i64 x=0) noexcept :v(x<0?mod-1-(-(x+1)%mod):x%mod){}
    constexpr u32 &value() noexcept {return v;}
    constexpr const u32 &value() const noexcept {return v;}
    constexpr modint operator+(const modint &rhs) const noexcept {return modint(*this)+=rhs;}
    constexpr modint operator-(const modint &rhs) const noexcept {return modint(*this)-=rhs;}
    constexpr modint operator*(const modint &rhs) const noexcept {return modint(*this)*=rhs;}
    constexpr modint operator/(const modint &rhs) const noexcept {return modint(*this)/=rhs;}
    constexpr modint &operator+=(const modint &rhs) noexcept {
        v+=rhs.v;
        if (v>=mod) v-=mod;
        return *this;
    }
    constexpr modint &operator-=(const modint &rhs) noexcept {
        if (v<rhs.v) v+=mod;
        v-=rhs.v;
        return *this;
    }
    constexpr modint &operator*=(const modint &rhs) noexcept {
        v=(u64)v*rhs.v%mod;
        return *this;
    }
    constexpr modint &operator/=(const modint &rhs) noexcept {
        return *this*=rhs.pow(mod-2);
    }
    constexpr modint pow(u64 exp) const noexcept {
        modint self(*this),res(1);
        while (exp>0){
            if (exp&1) res*=self;
            self*=self; exp>>=1;
        }
        return res;
    }
    constexpr modint &operator++() noexcept {if (++v==mod) v=0; return *this;}
    constexpr modint &operator--() noexcept {if (v==0) v=mod; return --v,*this;}
    constexpr modint operator++(int) noexcept {modint t=*this; return ++*this,t;}
    constexpr modint operator--(int) noexcept {modint t=*this; return --*this,t;}
    template<class T> friend constexpr modint operator+(T x,modint y) noexcept {return modint(x)+y;}
    template<class T> friend constexpr modint operator-(T x,modint y) noexcept {return modint(x)-y;}
    template<class T> friend constexpr modint operator*(T x,modint y) noexcept {return modint(x)*y;}
    template<class T> friend constexpr modint operator/(T x,modint y) noexcept {return modint(x)/y;}
    constexpr bool operator==(const modint &rhs) const noexcept {return v==rhs.v;}
    constexpr bool operator!=(const modint &rhs) const noexcept {return v!=rhs.v;}
    constexpr bool operator!() const noexcept {return !v;}
    friend istream &operator>>(istream &s,modint &rhs) noexcept {
        i64 v; rhs=modint{(s>>v,v)}; return s;
    }
    friend ostream &operator<<(ostream &s,const modint &rhs) noexcept {
        return s<<rhs.v;
    }
};

class RollingHash{
    using u64=uint64_t;
    using u128=__uint128_t;
    static const uint64_t mod=(1ULL<<61)-1;
    const u64 base;
    vector<u64> hash,power;
    static inline u64 add(u64 a,u64 b){
        if ((a+=b)>=mod) a-=mod;
        return a;
    }
    static inline u64 mul(u64 a,u64 b){
        u128 c=(u128)a*b;
        return add(c>>61,c&mod);
    }
public:
    static inline u64 generate_base(){
        mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());
        uniform_int_distribution<u64> rand(2,RollingHash::mod-1);
        return rand(mt);
    }
    template<typename T>
    RollingHash(const T &s,u64 base):base(base){
        int n=s.size();
        hash.assign(n+1,0);
        power.assign(n+1,0);
        power[0]=1;
        for (int i=0;i<n;++i){
            hash[i+1]=add(mul(hash[i],base),s[i]);
            power[i+1]=mul(power[i],base);
        }
    }
    u64 query(int l,int r) const {
        return add(hash[r],mod-mul(hash[l],power[r-l]));
    }
    int lcp(int a,int b) const {
        int len=min(hash.size()-a,hash.size()-b);
        int lb=0,ub=len;
        while (ub-lb>1){
            int mid=(lb+ub)>>1;
            (query(a,a+mid)==query(b,b+mid)?lb:ub)=mid;
        }
        return lb;
    }
};

using mint=modint<MOD>;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int m; cin >> m;
    vector<int> ok(30,1);
    ok[3]=ok[5]=ok[14]=ok[15]=0;

    string S="";
    for (int i=0;i<m;++i){
        char c; cin >> c;
        S+=c;
    }
    RollingHash RH(S,RollingHash::generate_base());

    mint ans=0;
    vector<mint> dp(m+1);
    vector<unordered_set<uint64_t>> cnt(m);
    for (int i=0;i<m;++i){
        dp[i+1]=1;
        for (int j=i;j>=0;--j){
            dp[j]=0;
            if (j+1<=i+1) dp[j]+=dp[j+1];
            if (j+2<=i+1) dp[j]+=dp[j+2];
            if (j+3<=i+1) dp[j]+=dp[j+3];
            if (j+4<=i+1){
                int cur=0;
                for (int k=j;k<j+4;++k) (cur<<=1)+=(S[k]-'0');
                if (ok[cur]) dp[j]+=dp[j+4];
            }
            auto p=RH.query(j,i+1);
            if (!cnt[i-j].count(p)){
                ans+=dp[j];
                cnt[i-j].emplace(p);
            }
        }
        cout << ans << '\n';
    }
}