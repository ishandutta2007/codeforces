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

template<typename T> vector<T> compress(vector<T> v){
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    return v;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<int> L(n),R(n),comp;
    comp.emplace_back(-1);
    comp.emplace_back(MOD-1);
    mint all=1;
    for (int i=0;i<n;++i){
        cin >> L[i] >> R[i];
        comp.emplace_back(L[i]);
        comp.emplace_back(++R[i]);
        all*=R[i]-L[i];
    }
    reverse(L.begin(),L.end());
    reverse(R.begin(),R.end());
    comp=compress(comp);
    for (int i=0;i<n;++i){
        L[i]=lower_bound(comp.begin(),comp.end(),L[i])-comp.begin();
        R[i]=lower_bound(comp.begin(),comp.end(),R[i])-comp.begin();
    }
    int m=comp.size()-1;
    vector<vector<mint>> COM(m,vector<mint>(n+1));
    for (int i=0;i<m;++i){
        int num=comp[i+1]-comp[i];
        for (int j=0;j<=n;++j){
            COM[i][j]=1;
            for (int k=1;k<=j;++k) (COM[i][j]*=(num+j-k))/=k;
        }
    }
    vector<vector<mint>> dp(n+1,vector<mint>(m,0));
    dp[0][0]=1;
    for (int i=0;i<n;++i){
        for (int j=0;j<m;++j){
            for (int k=j+1;k<m;++k){
                for (int l=0;i+l<n;++l){
                    if (k<L[i+l]||R[i+l]<=k) break;
                    dp[i+l+1][k]+=dp[i][j]*COM[k][l+1];
                }
            }
        }
    }
    mint ans=0;
    for (int j=0;j<m;++j) ans+=dp[n][j];
    cout << ans/all << '\n';
}