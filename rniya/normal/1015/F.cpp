#include <bits/stdc++.h>
using namespace std;
const long long MOD=1e9+7;

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

const int MAX_N=210;

mint dp[MAX_N][MAX_N][MAX_N];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; string S; cin >> n >> S; n<<=1;
    int s=S.size();
    vector<int> rec(s,0);
    for (int i=0;i<s;++i){
        S[i]=(S[i]=='('?')':'(');
        for (int j=i;j>0;--j){
            for (int k=j;k<=i;++k){
                if (S[k]!=S[k-j]) break;
                if (k==i) rec[i]=i-j+1;
            }
        }
        S[i]=(S[i]=='('?')':'(');
    }
    dp[0][0][0]=1;
    for (int i=0;i<n;++i){
        for (int j=0;j<MAX_N/2;++j){
            for (int k=0;k<=s;++k){
                if (k==s){
                    dp[i+1][j+1][k]+=dp[i][j][k];
                    if (j-1>=0) dp[i+1][j-1][k]+=dp[i][j][k];
                } else if (S[k]=='('){
                    dp[i+1][j+1][k+1]+=dp[i][j][k];
                    if (j-1>=0) dp[i+1][j-1][rec[k]]+=dp[i][j][k];
                } else {
                    if (j-1>=0) dp[i+1][j-1][k+1]+=dp[i][j][k];
                    dp[i+1][j+1][rec[k]]+=dp[i][j][k];
                }
            }
        }
    }
    cout << dp[n][0][s] << '\n';
}