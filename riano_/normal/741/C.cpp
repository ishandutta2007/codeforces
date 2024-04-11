#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int i=0;i<n;i++)
#define Pr pair<ll,ll>
#define Tp tuple<ll,ll,ll>
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
    riano_; ll ans = 0;
    ll N; cin >> N;
    //main 
    //unionfind uf(2*N+1);
    Graph G(2*N+1);
    ll p1[N],p2[N];
    rep(i,N){
        ll a,b; cin >> a >> b;
        p1[i] = a; p2[i] = b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    rep(i,N){
        G[2*i+1].push_back(2*i+2);
        G[2*i+2].push_back(2*i+1);
    }

    //BFS ()
    queue<int> go; ll dist[2*N+1],par[2*N+1]; // ll par[N+1];
    rep(i,2*N+1){
        dist[i] = 2000000000; par[i] = -1;
    }
    rep(i,2*N){
        if(dist[i+1]<2000000000) continue;
    dist[i+1] = 0; go.push(i+1);
    while(!go.empty()){
        int s = go.front(); go.pop();
        for(int x:G[s]){
            if(dist[x]<=dist[s]+1) continue;
            dist[x] = dist[s] + 1;
            par[x] = s;
            go.push(x);
        }
    }
    }
    rep(i,N){
        if(dist[p1[i]]%2==0){
            cout << 1 << " " << 2 << endl;
        }
        else{
            cout << 2 << " " << 1 << endl;
        }
    }
    //cout << ans << endl;
}