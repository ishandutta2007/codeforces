#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int i=0;i<n;i++)
#define Pr pair<ll,ll>
#define Tp tuple<ll,ll,ll>
#define riano_ std::ios::sync_with_stdio(false);std::cin.tie(nullptr);typedef modint<mod> mint
using Graph = vector<vector<int>>;

const ll mod = 1000000007;
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
    riano_; ll ans = 0;
    ll T; cin >> T;
    rep(ii,T){
        string S; cin >> S;
        map<char,ll> cnt;
        cnt['L'] = 0; cnt['R'] = 0; cnt['U'] = 0; cnt['D'] = 0;
        rep(i,S.size()){
            cnt[S[i]]++;
        }
        ll dx = min(cnt['R'],cnt['L']);
        ll dy = min(cnt['U'],cnt['D']);
        if(dx==0&&dy==0){
            cout << 0 << "\n"; cout << "\n";
        }
        else if(dx==0){
            cout << 2 << "\n"; cout << "UD" << "\n";
        }
        else if(dy==0){
            cout << 2 << "\n"; cout << "RL" << "\n";
        }
        else{
            string op;
            rep(i,dx){
                op += 'R';
            }
            rep(i,dy){
                op += 'U';
            }
            rep(i,dx){
                op += 'L';
            }
            rep(i,dy){
                op += 'D';
            }
            cout << op.size() << "\n";
            cout << op << "\n";
        }
    }
    //cout << ans << endl;
}