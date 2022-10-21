#include <bits/stdc++.h>
using namespace std;
const long long MOD=998244353;

template<uint_fast64_t Modulus> class modint{
    using u64=uint_fast64_t;
    public:
    u64 a;
    constexpr modint(const u64 x=0) noexcept:a(((x%Modulus)+Modulus)%Modulus){}
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
    int N,K; cin >> N >> K;
    vector<int> a(N),b(K);
    for (int i=0;i<N;++i) cin >> a[i];
    for (int i=0;i<K;++i) cin >> b[i];
    map<int,int> cnt;
    for (int i=0;i<N;++i) ++cnt[a[i]];
    NumberTheoreticTransform<MOD> NTT;
    vector<vector<mint>> dp(K,vector<mint>(N+1,0));
    for (int i=0;i<K;++i){
        vector<vector<mint>> poly;
        int now=0;
        for (auto x:cnt){
            if (b[i]<=x.first) break;
            poly.emplace_back();
            for (int j=0;j<=min(2,x.second);++j){
                poly[now].emplace_back(j==1?2:1);
            }
            ++now;
        }
        auto dfs=[&](auto self,int l,int r)->vector<mint>{
            if (l==r) return {1};
            if (r-l==1) return poly[l];
            int mid=(l+r)>>1;
            return NTT.multiply(self(self,l,mid),self(self,mid,r));
        };
        vector<mint> mul=dfs(dfs,0,now);
        for (int j=0;j<mul.size();++j) dp[i][j]=mul[j];
    }
    int q; cin >> q;
    for (;q--;){
        int Q; cin >> Q; Q>>=1;
        mint ans=0;
        for (int i=0;i<K;++i){
            int pos=Q-b[i]-1;
            if (pos<0||pos>N) continue;
            ans+=dp[i][Q-b[i]-1];
        }
        cout << ans << '\n';
    }
}