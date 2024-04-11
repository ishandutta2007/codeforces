#include <bits/stdc++.h>
using namespace std;
// const long long MOD=1000000007;
const long long MOD=998244353;
#define LOCAL
#pragma region Macros
typedef long long ll;
typedef __int128_t i128;
typedef unsigned int uint;
typedef unsigned long long ull;
#define ALL(x) (x).begin(),(x).end()
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
template<typename T,typename U,typename V>
ostream&operator<<(ostream &os,const tuple<T,U,V> &t){
    os << '(' << get<0>(t) << ',' << get<1>(t) << ',' << get<2>(t) << ')';
    return os;
}
template<typename T,typename U,typename V,typename W>
ostream&operator<<(ostream &os,const tuple<T,U,V,W> &t){
    os << '(' << get<0>(t) << ',' << get<1>(t) << ',' << get<2>(t) << ',' << get<3>(t) << ')';
    return os;
}
template<typename T,typename U>
ostream &operator<<(ostream &os,const map<T,U> &m){
    os << '{';
    for (auto itr=m.begin();itr!=m.end();){
        os << '(' << itr->first << ',' << itr->second << ')';
        if (++itr!=m.end()) os << ',';
    }
    os << '}';
    return os;
}
template<typename T,typename U>
ostream &operator<<(ostream &os,const unordered_map<T,U> &m){
    os << '{';
    for (auto itr=m.begin();itr!=m.end();){
        os << '(' << itr->first << ',' << itr->second << ')';
        if (++itr!=m.end()) os << ',';
    }
    os << '}';
    return os;
}
template<typename T>
ostream &operator<<(ostream &os,const set<T> &s){
    os << '{';
    for (auto itr=s.begin();itr!=s.end();){
        os << *itr;
        if (++itr!=s.end()) os << ',';
    }
    os << '}';
    return os;
}
template<typename T>
ostream &operator<<(ostream &os,const multiset<T> &s){
    os << '{';
    for (auto itr=s.begin();itr!=s.end();){
        os << *itr;
        if (++itr!=s.end()) os << ',';
    }
    os << '}';
    return os;
}
template<typename T>
ostream &operator<<(ostream &os,const unordered_set<T> &s){
    os << '{';
    for (auto itr=s.begin();itr!=s.end();){
        os << *itr;
        if (++itr!=s.end()) os << ',';
    }
    os << '}';
    return os;
}
template<typename T>
ostream &operator<<(ostream &os,const deque<T> &v){
    for (int i=0;i<v.size();++i){
        os << v[i] << (i+1==v.size()?"": " ");
    }
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
    constexpr modint operator-() const noexcept {return modint(mod-v);}
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

template<int mod>
struct NumberTheoreticTransform{
    using Mint=modint<mod>;
    vector<Mint> roots;
    vector<int> rev;
    int base,max_base;
    Mint root;
    NumberTheoreticTransform():base(1),rev{0,1},roots{Mint(0),Mint(1)}{
        int tmp=mod-1;
        for (max_base=0;tmp%2==0;++max_base) tmp>>=1;
        root=2;
        while (root.pow((mod-1)>>1)==1) ++root;
        root=root.pow((mod-1)>>max_base);
    }
    void ensure_base(int nbase){
        if (nbase<=base) return;
        rev.resize(1<<nbase);
        for (int i=0;i<(1<<nbase);++i){
            rev[i]=(rev[i>>1]>>1)|((i&1)<<(nbase-1));
        }
        roots.resize(1<<nbase);
        for (;base<nbase;++base){
            Mint z=root.pow(1<<(max_base-1-base));
            for (int i=1<<(base-1);i<(1<<base);++i){
                roots[i<<1]=roots[i];
                roots[i<<1|1]=roots[i]*z;
            }
        }
    }
    void ntt(vector<Mint> &a){
        const int n=a.size();
        int zeros=__builtin_ctz(n);
        ensure_base(zeros);
        int shift=base-zeros;
        for (int i=0;i<n;++i){
            if (i<(rev[i]>>shift)){
                swap(a[i],a[rev[i]>>shift]);
            }
        }
        for (int k=1;k<n;k<<=1){
            for (int i=0;i<n;i+=(k<<1)){
                for (int j=0;j<k;++j){
                    Mint z=a[i+j+k]*roots[j+k];
                    a[i+j+k]=a[i+j]-z;
                    a[i+j]=a[i+j]+z;
                }
            }
        }
    }
    vector<Mint> multiply(vector<Mint> a,vector<Mint> b){
        int need=a.size()+b.size()-1;
        int nbase=1;
        while ((1<<nbase)<need) ++nbase;
        ensure_base(nbase);
        int sz=1<<nbase;
        a.resize(sz,Mint(0)); b.resize(sz,Mint(0));
        ntt(a); ntt(b);
        Mint inv_sz=1/Mint(sz);
        for (int i=0;i<sz;++i) a[i]*=b[i]*inv_sz;
        reverse(a.begin()+1,a.end());
        ntt(a);
        a.resize(need);
        return a;
    }
    vector<int> multiply(vector<int> a,vector<int> b){
        vector<Mint> A(a.size()),B(b.size());
        for (int i=0;i<a.size();++i) A[i]=Mint(a[i]);
        for (int i=0;i<b.size();++i) B[i]=Mint(b[i]);
        vector<Mint> C=multiply(A,B);
        vector<int> res(C.size());
        for (int i=0;i<C.size();++i) res[i]=C[i].v;
        return res;
    }
};

template<class M>
struct Combination{
    vector<M> _fac,_inv,_finv;
    Combination(int n):_fac(n+1),_inv(n+1),_finv(n+1){
        _fac[0]=_finv[n]=_inv[0]=1;
        for (int i=1;i<=n;++i) _fac[i]=_fac[i-1]*i;
        _finv[n]/=_fac[n];
        for (int i=n-1;i>=0;--i) _finv[i]=_finv[i+1]*(i+1);
        for (int i=1;i<=n;++i) _inv[i]=_finv[i]*_fac[i-1];
    }
    M fac(int k) const {return _fac[k];}
    M finv(int k) const {return _finv[k];}
    M inv(int k) const {return _inv[k];}
    M P(int n,int r) const {
        if (n<0||r<0||n<r) return 0;
        return _fac[n]*_finv[n-r];
    }
    M C(int n,int r) const {
        if (n<0||r<0||n<r) return 0;
        return _fac[n]*_finv[r]*_finv[n-r];
    }
};

using mint=modint<MOD>;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    Combination<mint> COM(200010);
    int n; cin >> n;

    vector<mint> dp(1,1);
    NumberTheoreticTransform<MOD> NTT;
    auto update=[&](int a,int b){
        int cur=dp.size(),lim=b-cur+1;
        vector<mint> binoms(cur+a-lim);
        for (int i=0;i<cur+a-lim;++i) binoms[i]=COM.C(a+b,i+lim);
        vector<mint> ndp=NTT.multiply(dp,binoms);
        dp.resize(cur+a-b);
        for (int i=0;i<dp.size();++i) dp[i]=ndp[i+b-lim];
    };

    for (;n--;){
        int a,b; cin >> a >> b;
        update(a,b);
    }

    mint ans=accumulate(dp.begin(),dp.end(),mint(0));
    cout << ans << '\n';
}