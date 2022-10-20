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

vector<ll> cand;
//dfs
//s: i:dfs t:
vector<int> vis; int t;
vector<int> depth;
vector<int> par;

//L
int L = 2e9;

void dfs(Graph &G, int s,int i){
    t++;
    //cout << s << endl;
    cand.push_back(s);
    //cout << "p" << s << endl;
    for(int nx:G[s]){
        //cout << s << " " << nx << endl;
        //if(t>=L) break;
        if(vis[nx]==i){
            if(nx==par[s]||nx>s+1) continue;
            if(nx!=s){
                cand.push_back(nx);
                //cout << "p" << nx << endl;
            }
            cand.push_back(s);
            //cout << "p" << s << endl;
            continue;
        }
        depth[nx] = depth[s] + 1;
        vis[nx] = i;
        par[nx] = s;
        dfs(G,nx,i);
        cand.push_back(s);
        //cout << "p" << s << endl;
    }
    t--;
    
}
    

int main() {
    riano_; string ans;
    ll N,K; cin >> N >> K;
    Graph G(K);
    rep(i,K){
        rep(j,K){
            G[i].push_back(j);
        }
    }
    //main
    vis.assign(K+1,-1);
    depth.assign(K+1,-1);
    par.assign(K+1,-1);
    int s = 0;
    vis[s] = 0; depth[s] = 0; t = -1; //s:
    
    dfs(G,s,0); //s: 0:dfs

    // rep(i,cand.size()){
    //     cout << cand[i] << " ";
    // }
    // cout << endl;
    cand.pop_back();
    rep(i,N){
        ans += (char)('a'+cand[(i%(int)(cand.size()))]);
    }
    cout << ans << endl;
}