#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int i=0;i<n;i++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define rrep2(i,n,k) for(int i=n-1;i>=n-k;i--)
#define vll(n,i) vector<long long>(n,i)
#define v2ll(n,m,i) vector<vector<long long>>(n,vll(m,i))
#define v3ll(n,m,k,i) vector<vector<vector<long long>>>(n,v2ll(m,k,i))
#define v4ll(n,m,k,l,i) vector<vector<vector<vector<long long>>>>(n,v3ll(m,k,l,i))
#define all(v) v.begin(),v.end()
#define chmin(k,m) k = min(k,m)
#define chmax(k,m) k = max(k,m)
#define Pr pair<ll,ll>
#define Tp tuple<ll,ll,ll>
#define riano_ std::ios::sync_with_stdio(false);std::cin.tie(nullptr)

//Graph
struct graph {
    long long N;
	vector<vector<tuple<long long,long long,int>>> G;
    vector<long long> par_v;
    vector<long long> par_e;
    int edge_count = 0;
    
	graph(long long n) {
        N = n;
		G = vector<vector<tuple<long long,long long,int>>>(N);
        par_v = vector<long long>(N,-1);
        par_e = vector<long long>(N,-1);
	}

    void unite(long long a,long long b,long long cost = 1,bool directed = false){
        G[a].emplace_back(b,cost,edge_count);
        if(!directed) G[b].emplace_back(a,cost,edge_count);
        edge_count++;
    }
};

const ll mod = 2e18;
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
    modint & operator++(){
        val++;
        if (val == mod) val = 0;
        return *this;
    }
    modint operator++(int){
        modint<mod> res = *this;
        ++*this;
        return res;
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
typedef modint<mod> mint;
mint pw(long long a,long long b,long long m = mod){
    if(a%m==0) return mint(0);
    if(b==0) return mint(1);
    else if(b%2==0){
        long long x = pw(a,b/2,m).val;
        return mint(x*x);
    }
    else{
        long long x = pw(a,b-1,m).val;
        return mint(a*x);
    }
}
mint modinv(long long a, long long m = mod) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    return mint(u);
}
#define vm(n,i) vector<mint>(n,i)
#define v2m(n,m,i) vector<vector<mint>>(n,vm(m,i))
#define v3m(n,m,k,i) vector<vector<vector<mint>>>(n,v2m(m,k,i))
#define v4m(n,m,k,l,i) vector<vector<vector<vector<mint>>>>(n,v3m(m,k,l,i))
void out(vector<ll> &v){
    for(ll x:v) cout << x << " ";
    cout << "\n"; return;
}

void NO(){
    cout << "NO" << "\n";
}

int main(){
    riano_; ll ans = 0;
    ll N,M,K,H,W,T,Q; cin >> T;
    string col = "RBB";
    rep(ii,T){
        //cout << ii << "\n";
        cin >> N >> M;
        ll a[N][M];
        ll mi0 = 2e18,ma0 = 0,mii = 0,mai = 0;
        rep(i,N){
            rep(j,M){
                cin >> a[i][j];
                if(j==0&&a[i][j]<mi0){
                    mi0 = a[i][j]; mii = i;
                }
                if(j==0&&a[i][j]>ma0){
                    ma0 = a[i][j]; mai = i;
                }
            }
        }
        vector<ll> c(N,2);
        queue<ll> red,blue;
        red.push(mai); blue.push(mii);
        // c[mii] = 1;
        // if(c[mai]!=2){
        //     NO(); continue;
        // }
        // c[mai] = 0; //red
        ll th = -1;
        bool ok = true;
        rep(j,M){
            if(a[mii][j]==a[mai][j]) ok = false;
            if(a[mii][j]<a[mai][j]) th = j+1;
        }
        if(th==M||th==-1) ok = false;
        rep(j,th){
            if(a[mii][j]>a[mai][j]) ok = false;
        }
        if(!ok){
            NO(); continue;
        }
        //cout << ii << "\n";
        vector<Pr> lf_mn,lf_mx,rh_mn,rh_mx;
        rep(i,N){
            ll tmnl = 2e18,tmxl = 0;
            ll tmnr = 2e18,tmxr = 0;
            rep(j,M){
                if(j<th){
                    chmin(tmnl,a[i][j]); chmax(tmxl,a[i][j]);
                }
                else{
                    chmin(tmnr,a[i][j]); chmax(tmxr,a[i][j]);
                }
            }
            lf_mx.emplace_back(tmxl,i); lf_mn.emplace_back(tmnl,i);
            rh_mx.emplace_back(tmxr,i); rh_mn.emplace_back(tmnr,i);
        }
        sort(all(lf_mn)); sort(all(lf_mx)); reverse(all(lf_mx));
        sort(all(rh_mn)); sort(all(rh_mx)); reverse(all(rh_mx));
        ll l_min = 2e18,l_max = 0,r_min = 2e18,r_max = 0;
        vector<int> ix(4,0);
        while(!red.empty()){
            ll id = red.front(); red.pop();
            //cout << "red" << id << "\n";
            if(c[id]==1){
                ok = false; break;
            }
            c[id] = 0;
            rep(j,M){
                if(j<th) chmin(l_min,a[id][j]);
                else chmax(r_max,a[id][j]);
            }
            while(ix[1]<N&&lf_mx[ix[1]].first>=l_min){
                red.push(lf_mx[ix[1]].second); ix[1]++;
            }
            while(ix[2]<N&&rh_mn[ix[2]].first<=r_max){
                red.push(rh_mn[ix[2]].second); ix[2]++;
            }
            while(!blue.empty()){
                ll id2 = blue.front(); blue.pop();
                //cout << "blue" << id2 << "\n";
                if(c[id2]==0){
                    ok = false; break;
                }
                c[id2] = 1;
                rep(j,M){
                    if(j<th) chmax(l_max,a[id2][j]);
                    else chmin(r_min,a[id2][j]);
                }
                while(ix[0]<N&&lf_mn[ix[0]].first<=l_max){
                    blue.push(lf_mn[ix[0]].second); ix[0]++;
                }
                while(ix[3]<N&&rh_mx[ix[3]].first>=r_min){
                    blue.push(rh_mx[ix[3]].second); ix[3]++;
                }
            }
        }
        //cout << ii << "\n";
        if(l_max>=l_min||r_max>=r_min) ok = false;
        if(!ok){
            NO(); continue;
        }
        //cout << ii << "\n";
        cout << "YES" << "\n";
        rep(i,N){
            cout << col[c[i]];
        }
        cout << " " << th << "\n";
    }
    
    //cout << ans << endl;
}