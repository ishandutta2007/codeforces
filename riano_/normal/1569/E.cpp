#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int i=0;i<n;i++)
#define Pr pair<ll,ll>
#define Tp tuple<int,int,int>
#define all(v) v.begin(),v.end()
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

vector<ll> p;
ll K,A,H; 

vector<Pr> score(ll tmp,vector<ll> t1,ll f){
    int N = t1.size();
    int id = 0;
    vector<Pr> res;
    rep(i,N-1){
        res.push_back(make_pair(t1[id+tmp%2],p[i]));
        if(i!=N-2) t1.push_back(t1[id+1-tmp%2]);
        else{
            res.push_back(make_pair(t1[id+1-tmp%2],f));
        }
        tmp /= 2;
        id += 2;
    }
    sort(all(res));
    return res;
}


// abm
long long pw(long long a,long long b,long long m){
    if(b==0) return 1;
    else if(b%2==0){
        long long x = pw(a,b/2,m);
        return (x*x)%m;
    }
    else{
        long long x = pw(a,b-1,m);
        return (a*x)%m;
    }
}


ll calc(vector<Pr> v){
    ll res = 0;
    for(auto[s,r]:v){
        res += s*(pw(A,r,mod))%mod;
    }
    res %= mod;
    return res;
}

int main() {
    riano_; ll ans = 0;
    cin >> K >> A >> H;
    if(K==1){
        if((A+2*A*A)%mod==H){
            cout << 1 << " " << 2 << endl;
        }
        else if((A*A+2*A)%mod==H){
            cout << 2 << " " << 1 << endl;
        }
        else{
            cout << -1 << endl;
        }
        return 0;
    }
    vector<ll> pl = {3,5,9,17};
    vector<ll> ct = {1,2,4,8};
    for(ll i=K-2;i>=0;i--){
        rep(j,ct[i]){
            p.push_back(pl[i]);
        }
    }
    vector<ll> t1,t2;
    rep(i,(1<<(K-1))){
        t1.push_back(i+1);
        t2.push_back(i+1+(1<<(K-1)));
    }
    ll match = ((1<<(K-1))-1);
    // cout << match << endl;
    // for(ll x:p){
    //     cout << x << " ";
    // }
    // for(auto x:t1){
    //     cout << x << " ";
    // }
    // cout << endl;
    // for(auto x:t2){
    //     cout << x << " ";
    // }
    // cout << endl;
    vector<vector<ll>> half(2);
    map<Pr,vector<Pr>> memo;
    //bitsearch bit  320bit
    for(int tmp=0;tmp<(1<<20);tmp++){
        if(tmp>=(1<<match)){ //
            break;
        }
        auto v = score(tmp,t1,1);
        // cout << tmp << endl;
        // for(auto[id,r]:v){
        //     cout << id << " " << r << endl;
        // }
        // cout << "----------" << endl;
        half[0].push_back(calc(v));
        memo[make_pair(0LL,calc(v))] = v;
        v = score(tmp,t1,2);
        half[1].push_back(calc(v));
        memo[make_pair(1LL,calc(v))] = v;
    }
    rep(i,2){
        sort(half[i].begin(),half[i].end());
        half[i].push_back(2e9);
    }
    for(int tmp=0;tmp<(1<<20);tmp++){
        if(tmp>=(1<<match)){ //
            break;
        }
        rep(i,2){
            auto v = score(tmp,t2,i+1);
            ll hb = (mod+H-calc(v))%mod;
            ll id = lower_bound(all(half[1-i]),hb) - half[1-i].begin();
            if(half[1-i][id]==hb){
                auto v2 = memo[make_pair(1-i,hb)];
                for(auto [ii,x]:v2){
                    cout << x << " ";
                }
                for(auto [ii,x]:v){
                    cout << x << " ";
                }
                cout << endl;
                return 0;
            }
        }
    }
    cout << -1 << endl;
}