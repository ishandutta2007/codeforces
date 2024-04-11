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


//mod
long long modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}

//squared tree dp 2
ll N,K;
#define type vector<ll>
type el; //dp
vector<type> dp(5001); //
vector<vector<type>> cand(5001);

//dfs  merge
vector<int> vis;
vector<int> par;
void dfs(Graph &G, int s,int ii){
    
    //cout << s << endl;
    for(int nx:G[s]){
        if(vis[nx]==ii) continue;
        par[nx] = s;
        vis[nx] = ii;
        dfs(G,nx,ii);
    }

    if(cand[s].size()==0){
        dp[s] = el; //at leaf
    }
    else{
        ll L = cand[s].size();
        ll siz = 1;     //siz:
        rep(i,L){
            siz = max(siz,(ll)(cand[s][i].size())+1);
        }

        // rep(i,L){
        //     for(ll x:cand[s][i]){
        //         cout << x << " ";
        //     }
        //     cout << endl;
        // }

        siz = min(siz,K+1);
        dp[s].assign(siz+1,0LL);
        vector<vector<ll>> ds(L);
        rep(i,L){
            ll J = cand[s][i].size();
            ds[i].assign(J+1,0LL);
            rep(j,J){
                ds[i][j+1] = (ds[i][j] + cand[s][i][j]) % mod;
            }
        }
        //dp[s]
        ll sum[L],prd[siz+1];
        ll pf[L+1][siz+1],pb[L+1][siz+1];
        rep(i,siz+1){
            pf[0][i] = 1; pb[L][i] = 1;
        }
        rep(i,L) sum[i] = 0;
        rep(i,siz+1) prd[i] = 1;
        rep(j,L){
            prd[0] *= ds[j][ds[j].size()-1]; prd[0] %= mod;
            sum[j] += ds[j][ds[j].size()-1];
            pf[j+1][0] = prd[0];
        }
        for(int j=L-1;j>=0;j--){
            pb[j][0] = pb[j+1][0]*ds[j][ds[j].size()-1]%mod;
        }
        //cout << prd[0] << endl;
        ll res = 0;
        for(ll i=1;i<=siz;i++){
            if(i*2<=K){
                rep(j,L){
                    if(cand[s][j].size()>=i){
                        sum[j] += cand[s][j][i-1]; sum[j] %= mod;
                    }
                    prd[i] *= sum[j]; prd[i] %= mod;
                    pf[j+1][i] = prd[i];
                }
                for(ll j=L-1;j>=0;j--){
                    pb[j][i] = pb[j+1][i]*sum[j]%mod;
                }
                dp[s][i] = (mod+prd[i]-prd[i-1])%mod;
            }
            else if(i<=K){
                rep(j,L){
                    if(cand[s][j].size()>=i){
                        dp[s][i] += cand[s][j][i-1]*((pf[j][K-i]*pb[j+1][K-i])%mod)%mod;
                    }
                }
                dp[s][i] %= mod;
            }
            // else{
            //     rep(j,L){
            //         if(cand[s][j].size()>=i){
            //             res += (cand[s][j][i-1]*prd[K-i]%mod)*(modinv(ds[j][K-i],mod))%mod;
            //         }
            //     }
            //     res %= mod;
            // }
        }
        
        dp[s][0] = prd[0]%mod;
        // cout << prd[0] << endl;
        // cout << dp[s][0] << endl;
    }

    //push
    if(par[s]!=0) cand[par[s]].push_back(dp[s]);
    //cout << "end" << s << endl;
    cand[s].clear();
}
    


int main() {
    riano_; mint ans = 0;
    cin >> N >> K;
    //main
    Graph G(N+1);
    rep(i,N-1){
        ll a,b; cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    int s = 1,ii = 0; //
    vis.assign(N+1,-1);
    par.assign(N+1,-1);
    vis[s] = 0; par[s] = 0;
    el = {1,0};
    dfs(G,s,ii);
    rep(i,K+1){
        if(dp[1].size()>=i+1){
            ans += mint(dp[1][i]);
            //cout << dp[1][i] << endl;
        }
    }
    cout << ans << endl;
}