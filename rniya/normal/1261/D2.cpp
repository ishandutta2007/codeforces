#include <bits/stdc++.h>
using namespace std;
#define LOCAL
#pragma region Macros
typedef long long ll;
#define ALL(x) (x).begin(),(x).end()
// const long long MOD=1e9+7;
const long long MOD=998244353;
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

template<uint_fast64_t Modulus> class modint{
    using u64=uint_fast64_t;
    public:
    u64 a;
    constexpr modint(const u64 x=0) noexcept:a(x%Modulus){}
    constexpr u64 &value() noexcept{return a;}
    constexpr const u64 &value() const noexcept{return a;}
    constexpr modint &operator+=(const modint &rhs) noexcept{
        a+=rhs.a;
        if (a>=Modulus) a-=Modulus;
        return *this;
    }
    constexpr modint operator+(const modint &rhs) const noexcept{
        return modint(*this)+=rhs;
    }
    constexpr modint &operator++() noexcept{
        return ++a,*this;
    }
    constexpr modint operator++(int) noexcept{
        modint t=*this; return ++a,t;
    }
    constexpr modint &operator-=(const modint &rhs) noexcept{
        if (a<rhs.a) a+=Modulus;
        a-=rhs.a;
        return *this;
    }
    constexpr modint operator-(const modint &rhs) const noexcept{
        return modint(*this)-=rhs;
    }
    constexpr modint &operator--() noexcept{
        return --a,*this;
    }
    constexpr modint operator--(int) noexcept{
        modint t=*this; return --a,t;
    }
    constexpr modint &operator*=(const modint &rhs) noexcept{
        a=a*rhs.a%Modulus;
        return *this;
    }
    constexpr modint operator*(const modint &rhs) const noexcept{
        return modint(*this)*=rhs;
    }
    constexpr modint &operator/=(modint rhs) noexcept{
        u64 exp=Modulus-2;
        while(exp){
            if (exp&1) *this*=rhs;
            rhs*=rhs; exp>>=1;
        }
        return *this;
    }
    constexpr modint operator/(const modint &rhs) const noexcept{
        return modint(*this)/=rhs;
    }
    constexpr modint operator-() const noexcept{
        return modint(Modulus-a);
    }
    constexpr bool operator==(const modint &rhs) const noexcept{
        return a==rhs.a;
    }
    constexpr bool operator!=(const modint &rhs) const noexcept{
        return a!=rhs.a;
    }
    constexpr bool operator!() const noexcept{return !a;}
    friend constexpr modint pow(modint rhs,long long exp) noexcept{
        modint res{1};
        while(exp){
            if (exp&1) res*=rhs;
            rhs*=rhs; exp>>=1;
        }
        return res;
    }
    template<class T> friend constexpr modint operator+(T x,modint y) noexcept{
        return modint(x)+y;
    }
    template<class T> friend constexpr modint operator-(T x,modint y) noexcept{
        return modint(x)-y;
    }
    template<class T> friend constexpr modint operator*(T x,modint y) noexcept{
        return modint(x)*y;
    }
    template<class T> friend constexpr modint operator/(T x,modint y) noexcept{
        return modint(x)/y;
    }
    friend ostream &operator<<(ostream &s,const modint &rhs) noexcept{
        return s << rhs.a;
    }
    friend istream &operator>>(istream &s,modint &rhs) noexcept{
        u64 a; rhs=modint{(s >> a,a)}; return s;
    }
};

using mint=modint<MOD>;

const int MAX=5e5+10;
vector<mint> fac(MAX),finv(MAX),inv(MAX);
void COMinit(){
    fac[0]=fac[1]=1;
    finv[0]=finv[1]=1;
    inv[1]=1;
    for (int i=2;i<MAX;++i){
        fac[i]=fac[i-1]*i;
        inv[i]=-inv[MOD%i]*(MOD/i);
        finv[i]=finv[i-1]*inv[i];
    }
}
mint COM(int n,int k){
    if (n<k||n<0||k<0) return 0;
    return fac[n]*finv[k]*finv[n-k];
}

// Be careful with the value of MAX and conducting COMinit()

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
        while(pow(root,(mod-1)>>1)==1) ++root;
        root=pow(root,(mod-1)>>max_base);
    }
    void ensure_base(int nbase){
        if (nbase<=base) return;
        rev.resize(1<<nbase);
        for (int i=0;i<(1<<nbase);++i){
            rev[i]=(rev[i>>1]>>1)|((i&1)<<(nbase-1));
        }
        roots.resize(1<<nbase);
        for (;base<nbase;++base){
            Mint z=pow(root,1<<(max_base-1-base));
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
        while((1<<nbase)<need) ++nbase;
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
        for (int i=0;i<C.size();++i) res[i]=C[i].a;
        return res;
    }
};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,k; cin >> n >> k;
    vector<int> h(n);
    for (int i=0;i<n;++i) cin >> h[i];
    vector<vector<mint>> P(n,vector<mint>(3));
    for (int i=0;i<n;++i){
        if (h[i]==h[(i+1)%n]){
            P[i][0]=0; P[i][1]=k; P[i][2]=0;
        } else {
            P[i][0]=1; P[i][1]=k-2; P[i][2]=1;
        }
    }
    NumberTheoreticTransform<MOD> NTT;
    auto dfs=[&](auto self,int l,int r)->vector<mint>{
        if (r-l==1) return P[l];
        int mid=(l+r)>>1;
        return NTT.multiply(self(self,l,mid),self(self,mid,r));
    };
    vector<mint> dp=dfs(dfs,0,n);
    mint ans=0;
    for (int j=n+1;j<dp.size();++j) ans+=dp[j];
    cout << ans << '\n';
}