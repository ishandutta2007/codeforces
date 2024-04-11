#include <bits/stdc++.h>
using namespace std;
#define ll int
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

vector<ll> sal;
vector<ll> boss;
ll N; 


//Unionfind
struct unionfind {
	//-1
	//id
	  vector<long long> r;
      vector<bool> lp;
	  unionfind(long long N) {
		    r = vector<long long>(N, -1);
            lp = vector<bool>(N,false);
	  }
	  long long root(long long x) {
		    if (r[x] < 0) return x;
		    return r[x] = root(r[x]);
	  }
	  bool unite(long long x, long long y) {
		    x = root(x);
		    y = root(y);
		    if (x == y){
                lp[x] = true;
                return false;
            }
		    if (r[x] > r[y]) swap(x, y);
		    r[x] += r[y];
		    r[y] = x;
            lp[x] = (lp[x]||lp[y]);
		    return true;
	  }
	  long long size(long long x) {
		    return max(-r[root(x)],0LL);
	  }
  
  // 2x, ytrue
    bool same(long long x, long long y) { 
        long long rx = root(x);
        long long ry = root(y);
        return rx == ry;
    }
 
    bool loop(ll x){
        return lp[root(x)];
    }
 
    //
    void eval(ll i,ll x){
        r[i] = (-1)*x;
    }
};

void divide(vector<vector<ll>> &a,vector<ll> lab,ll b){
    if(a.size()==1){
        boss[lab[0]] = b;
        return;
    }
    int M = a.size();
    ll mx = 0;
    rep(i,M){
        if(mx<a[0][i]) mx = a[0][i];
    }
    unionfind uf(M);
    rep(i,M){
        rep(j,M){
            if(j>=i) break;
            if(a[i][j]!=mx) uf.unite(i,j);
        }
    }
    map<ll,vector<ll>> team;
    rep(i,M){
        ll r = uf.root(i);
        if(team.count(r)){
            team[r].push_back(i);
        }
        else team[r] = {i};
    }
    N++;
    ll b2 = N;
    sal.push_back(mx);
    boss.push_back(b);
    for(auto[s,v]:team){
        int L = v.size();
        vector<vector<ll>> a2(L,vector<ll>(L,0LL));
        vector<ll> lab2;
        rep(i,L) lab2.push_back(lab[v[i]]);
        rep(i,L){
            rep(j,L){
                a2[i][j] = a[v[i]][v[j]];
            }
        }
        divide(a2,lab2,b2);
    }
}

int main() {
    riano_; string ans;
    cin >> N;
    vector<vector<ll>> a(N,vector<ll>(N,0LL));
    sal.assign(N+1,0LL);
    boss.assign(N+1,-1LL);
    rep(i,N){
        rep(j,N){
            cin >> a[i][j];
        }
    }
    rep(i,N){
        sal[i+1] = a[i][i];
    }
    vector<ll> lab;
    rep(i,N) lab.push_back(i+1);
    divide(a,lab,0);
    cout << N << endl;
    rep(i,N){
        cout << sal[i+1] << " ";
    }
    cout << endl;
    rep(i,N+1){
        if(boss[i]==0){
            cout << i << endl; break;
        }
    }
    rep(i,N){
        if(boss[i+1]!=0){
            cout << i+1 << " " << boss[i+1] << endl;
        }
    }
}