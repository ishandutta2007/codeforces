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
    ll T; cin >> T;
    rep(ii,T){
        int n,d; cin >> n >> d;
        int p[n+1];
        p[n] = -1;
        if(d>(n*(n-1)/2)){
            cout << "NO" << "\n"; continue;
        }
        int b = 2,nd = 1,nx = 4;
        bool ok = true;
        for(int i=2;i<=n;i++){
            if(i==nx){
                nd++; b = i; nx *= 2;
            }
            int r = nd+((n-i)*nd+((n-i)*(n-i+1)/2));
            if(r>=d){
                p[i] = i/2; d -= nd;
                if(d<0) ok = false;
                continue;
            }
            int l = (nd+1)+((n-i-1)*(nd+1)+((n-i)*(n-i-1)/2));
            int req = d-l;
            // cout << d << "\n";
            // cout << i << " " << req << "\n";
            // cout << nd << "\n";
            //p[i] = b;
            for(int j=i;j<n;j++){
                p[j] = j-1;
                if((nd+1)==req) p[n] = j-1;
                nd++;
            }
            if(p[n]<0) p[n] = n-1;
            break;
        }
        if(!ok){
            cout << "NO" << "\n"; continue;
        }
        cout << "YES" << "\n";
        for(int i=2;i<=n;i++){
            cout << p[i] << " ";
        }
        cout << "\n";
    }
    //cout << ans << endl;
}