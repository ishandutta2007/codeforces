#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int i=0;i<n;i++)
#define Pr pair<ll,ll>
#define Tp tuple<int,int,int>
#define riano_ std::ios::sync_with_stdio(false);std::cin.tie(nullptr);typedef modint<mod> mint
using Graph = vector<vector<int>>;

const ll mod = 998244353;
template<uint64_t mod>
struct modint{
    uint64_t val;
    constexpr modint(const int64_t val_=0) noexcept:val((val_%int64_t(mod)+int64_t(mod))%int64_t(mod)){}
    constexpr modint operator-() const noexcept{
        return modint(*this)=mod-val;
    }
    constexpr modint operator+(const modint rhs) const noexcept{
        return modint(*this)+=rhs;
    }
    constexpr modint operator-(const modint rhs) const noexcept{
        return modint(*this)-=rhs;
    }
    constexpr modint operator*(const modint rhs) const noexcept{
        return modint(*this)*=rhs;
    }
    constexpr modint operator/(const modint rhs) const noexcept{
        return modint(*this)/=rhs;
    }
    constexpr modint &operator+=(const modint rhs) noexcept{
        val+=rhs.val;
        val-=((val>=mod)?mod:0);
        return (*this);
    }
    constexpr modint &operator-=(const modint rhs) noexcept{
        val+=((val<rhs.val)?mod:0);
        val-=rhs.val;
        return (*this);
    }
    constexpr modint &operator*=(const modint rhs) noexcept{
        val=val*rhs.val%mod;
        return (*this);
    }
    constexpr modint &operator/=(modint rhs) noexcept{
        uint64_t ex=mod-2;
        modint now=1;
        while(ex){
            now*=((ex&1)?rhs:1);
            rhs*=rhs,ex>>=1;
        }
        return (*this)*=now;
    }
    constexpr bool operator==(const modint rhs) noexcept{
        return val==rhs.val;
    }
    constexpr bool operator!=(const modint rhs) noexcept{
        return val!=rhs.val;
    }
    friend constexpr ostream &operator<<(ostream& os,const modint x) noexcept{
        return os<<(x.val);
    }
    friend constexpr istream &operator>>(istream& is,modint& x) noexcept{
        uint64_t t;
        is>>t,x=t;
        return is;
    }
};

int main() {
    riano_; //ll ans = 0;
    vector<vector<int>> div(20001);
    for(int i=1;i<=20000;i++){
        for(int j=1;j*j<=i;j++){
            if(i%j==0){
                div[i].push_back(j);
                if(j*j!=i){
                    div[i].push_back(i/j);
                }
            }
        }
    }
    ll T; cin >> T;
    rep(ii,T){
        int a,b,c; cin >> a >> b >> c;
        int A,B,C;
        int mc = 2e8;
        for(int i=1;i<=20000;i++){
            int cost = abs(i-b);
            int cca = 2e8,ccc = 2e8,ca,cc;
            for(int x:div[i]){
                if(cca>abs(x-a)){
                    ca = x; cca = abs(x-a);
                }
            }
            for(int j=i;j<=40000;j+=i){
                if(ccc>abs(j-c)){
                    cc = j; ccc = abs(j-c);
                }
            }
            cost += (cca+ccc);
            if(cost<mc){
                A = ca; B = i; C = cc;
                mc = cost;
            }
        }
        cout << mc << "\n";
        cout << A << " " << B << " " << C << "\n";
    }
    //cout << ans << endl;
}