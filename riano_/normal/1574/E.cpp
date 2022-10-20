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

int main() {
    riano_; //ll ans = 0;
    ll N,M,K; cin >> N >> M >> K;
    map<Pr,ll> g;
    ll col[2][M];
    ll row[2][N];
    rep(i,2){
        rep(j,M){
            col[i][j] = 0;
        }
    }
    rep(i,2){
        rep(j,N){
            row[i][j] = 0;
        }
    }
    ll cd = 0;
    ll fr_c = M,fr_r = N;
    ll ng_c = 0,ng_r = 0;
    ll it[2];
    it[0] = 0,it[1] = 0;
    rep(i,K){
        ll x,y,t; cin >> x >> y >> t;
        x--; y--;
        Pr p = make_pair(x,y);
        if(!g.count(p)||g[p]==-1){
            g[p] = t;
            
            if(t!=-1){
                it[(x+y+t)%2]++;
                cd++;
                col[((x+t)%2)][y]++;
                if(col[((x+t)%2)][y]==1){
                    if(col[1-((x+t)%2)][y]==0){
                        fr_c--;
                    }
                    else{
                        ng_c++;
                    }
                }
                row[((y+t)%2)][x]++;
                if(row[((y+t)%2)][x]==1){
                    if(row[1-((y+t)%2)][x]==0){
                        fr_r--;
                    }
                    else{
                        ng_r++;
                    }
                }
            }
        }
        else if(t==-1){
            ll pr = g[p];
            g[p] = t;
            it[(x+y+pr)%2]--;
            cd--;
                col[((x+pr)%2)][y]--;
                if(col[((x+pr)%2)][y]==0){
                    if(col[1-((x+pr)%2)][y]==0){
                        fr_c++;
                    }
                    else{
                        ng_c--;
                    }
                }
                row[((y+pr)%2)][x]--;
                if(row[((y+pr)%2)][x]==0){
                    if(row[1-((y+pr)%2)][x]==0){
                        fr_r++;
                    }
                    else{
                        ng_r--;
                    }
                }
        }
        else if(g[p]!=t){
            g[p] = t;
            it[(x+y+t)%2]++;
            it[1-(x+y+t)%2]--;
                col[((x+t)%2)][y]++;
                col[1-((x+t)%2)][y]--;
                if(col[((x+t)%2)][y]==1){
                    if(col[1-((x+t)%2)][y]==0){
                        
                    }
                    else{
                        ng_c++;
                    }
                }
                else{
                    if(col[1-((x+t)%2)][y]==0){
                        ng_c--;
                    }
                }
                row[((y+t)%2)][x]++;
                row[1-((y+t)%2)][x]--;
                if(row[((y+t)%2)][x]==1){
                    if(row[1-((y+t)%2)][x]==0){
                        
                    }
                    else{
                        ng_r++;
                    }
                }
                else{
                    if(row[1-((y+t)%2)][x]==0){
                        ng_r--;
                    }
                }
        }
        mint ans = 0;
        if(ng_c==0){
            ans += mint(pw(2LL,fr_c,mod));
        }
        if(ng_r==0){
            ans += mint(pw(2LL,fr_r,mod));
        }
        if(ng_c==0&&ng_r==0){
            if(cd==0){
                ans -= mint(2);
            }
            else if(it[0]*it[1]==0){
                ans -= mint(1);
            }
        }
        cout << ans << "\n";
    }    
    //cout << ans << endl;
}