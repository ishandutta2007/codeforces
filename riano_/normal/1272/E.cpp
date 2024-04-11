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
    ll N; cin >> N;
    ll a[N+1];
    rep(i,N) cin >> a[i+1];
    Graph G(N+1);
    //BFS ()
    queue<int> go; ll dist[N+1],par[N+1]; // ll par[N+1];
    rep(i,N+1){
        dist[i] = 2000000000; par[i] = -1;
    }
    rep(i,N){
        ll j = i+1;
        bool ok = false;
        if(j+a[j]<=N){
            if((a[j+a[j]]+a[j])%2==1){
                ok = true;
            }
            else{
                G[j+a[j]].push_back(j);
                //cout << j+a[j]] << " " << j << endl;
            }
        }
        if(j-a[j]>=1){
            if((a[j-a[j]]+a[j])%2==1){
                ok = true;
            }
            else{
                G[j-a[j]].push_back(j);
                //cout << a[j-a[j]] << " " << j << endl;
            }
        }
        if(ok){
            go.push(j); dist[j] = 1;
        }
    }
    while(!go.empty()){
        int s = go.front(); go.pop();
        for(int x:G[s]){
            if(dist[x]<=dist[s]+1) continue;
            dist[x] = dist[s] + 1;
            par[x] = s;
            go.push(x);
        }
    }

    rep(i,N){
        if(dist[i+1]>1e9){
            dist[i+1] = -1;
        }
        cout << dist[i+1] << " ";
    }
    cout << endl;
    //cout << ans << endl;
}