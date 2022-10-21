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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,k,m; cin >> n >> k >> m;
    struct section{
        int l,r,x;
        section(int l,int r,int x):l(l),r(r),x(x){}
        const bool operator<(const section &rhs){return r<rhs.r;}
    };
    vector<section> S;
    for (int i=0;i<m;++i){
        int l,r,x; cin >> l >> r >> x;
        S.emplace_back(--l,r,x);
    }
    sort(S.begin(),S.end());
    mint ans=1;
    for (int d=0;d<k;++d){
        vector<int> imos(n+1,0),L(n+1,-1);
        for (int i=0;i<m;++i){
            if (S[i].x&1<<d) ++imos[S[i].l],--imos[S[i].r];
            else L[S[i].r]=max(L[S[i].r],S[i].l);
        }
        vector<mint> dp(n+1,0),sum(n+2,0);
        dp[0]=sum[1]=1;
        for (int i=0;i<n;++i){
            imos[i+1]+=imos[i]; L[i+1]=max(L[i+1],L[i]);
            if (!imos[i]) dp[i+1]=sum[i+1]-sum[L[i]+1];
            sum[i+2]=sum[i+1]+dp[i+1];
        }
        ans*=sum[n+1]-sum[L[n]+1];
    }
    cout << ans << '\n';
}