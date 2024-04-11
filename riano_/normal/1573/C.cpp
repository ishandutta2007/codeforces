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
    riano_; //ll ans = 2e9;
    ll T; cin >> T;
    rep(ii,T){
        ll N; cin >> N; ll ans = 1;
        Graph G(N+1);
        vector<set<ll>> rq(N+1);
        ll in[N+1];
        rep(i,N+1) in[i] = 0;
        rep(i,N){
            ll K; cin >> K;
            in[i+1] = K;
            rep(j,K){
                ll u; cin >> u;
                G[u].push_back(i+1);
                rq[i+1].insert(u);
            }
        }
        //BFS ()
        set<ll> go; ll dist[N+1],par[N+1]; // ll par[N+1];
        bool st[N+1];
        rep(i,N+1) st[i] = false;
        rep(i,N+1){
            dist[i] = 2000000000; par[i] = -1;
        }
        rep(i,N){
            if(rq[i+1].empty()){
                go.insert(i+1); dist[i+1] = 0;
            }
        }
        int pr = 0;
        while(!go.empty()){
            auto itr = go.lower_bound(pr);
            if(itr==go.end()){
                ans++; itr = go.begin();
            }
            int s = *itr; go.erase(itr);
            if(st[s]) continue;
            st[s] = true;
            pr = s;
            //cout << s << "\n";
            for(int x:G[s]){
                dist[x] = dist[s];
                par[x] = s;
                in[x]--;
                rq[x].erase(s);
                if(rq[x].empty()){
                    go.insert(x);
                }
            }
        }
        rep(i,N){
            if(!rq[i+1].empty()) ans = -1;
        }
        cout << ans << "\n";
    }
}