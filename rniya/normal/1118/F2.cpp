#include <bits/stdc++.h>
using namespace std;
const long long MOD=998244353;

template<uint_fast64_t Modulus> class modint{
    using u64=uint_fast64_t;
    public:
    u64 a;
    constexpr modint(const u64 x=0) noexcept:a(((x%Modulus)+Modulus)%Modulus){}
    constexpr u64 &value() noexcept{return a;}
    constexpr const u64 &value() const noexcept{return a;}
    constexpr modint &operator+=(const modint &rhs) noexcept{
        a+=rhs.a;
        if (a>=Modulus) a-=Modulus;
        return *this;
    }
    constexpr modint operator+(const modint &rhs) const noexcept{
        return modint(*this)+=rhs;
    }
    constexpr modint &operator++() noexcept{
        return ++a,*this;
    }
    constexpr modint operator++(int) noexcept{
        modint t=*this; return ++a,t;
    }
    constexpr modint &operator-=(const modint &rhs) noexcept{
        if (a<rhs.a) a+=Modulus;
        a-=rhs.a;
        return *this;
    }
    constexpr modint operator-(const modint &rhs) const noexcept{
        return modint(*this)-=rhs;
    }
    constexpr modint &operator--() noexcept{
        return --a,*this;
    }
    constexpr modint operator--(int) noexcept{
        modint t=*this; return --a,t;
    }
    constexpr modint &operator*=(const modint &rhs) noexcept{
        a=a*rhs.a%Modulus;
        return *this;
    }
    constexpr modint operator*(const modint &rhs) const noexcept{
        return modint(*this)*=rhs;
    }
    constexpr modint &operator/=(modint rhs) noexcept{
        u64 exp=Modulus-2;
        while(exp){
            if (exp&1) *this*=rhs;
            rhs*=rhs; exp>>=1;
        }
        return *this;
    }
    constexpr modint operator/(const modint &rhs) const noexcept{
        return modint(*this)/=rhs;
    }
    constexpr modint operator-() const noexcept{
        return modint(Modulus-a);
    }
    constexpr bool operator==(const modint &rhs) const noexcept{
        return a==rhs.a;
    }
    constexpr bool operator!=(const modint &rhs) const noexcept{
        return a!=rhs.a;
    }
    constexpr bool operator!() const noexcept{return !a;}
    friend constexpr modint pow(modint rhs,long long exp) noexcept{
        modint res{1};
        while(exp){
            if (exp&1) res*=rhs;
            rhs*=rhs; exp>>=1;
        }
        return res;
    }
    template<class T> friend constexpr modint operator+(T x,modint y) noexcept{
        return modint(x)+y;
    }
    template<class T> friend constexpr modint operator-(T x,modint y) noexcept{
        return modint(x)-y;
    }
    template<class T> friend constexpr modint operator*(T x,modint y) noexcept{
        return modint(x)*y;
    }
    template<class T> friend constexpr modint operator/(T x,modint y) noexcept{
        return modint(x)/y;
    }
    friend ostream &operator<<(ostream &s,const modint &rhs) noexcept{
        return s << rhs.a;
    }
    friend istream &operator>>(istream &s,modint &rhs) noexcept{
        u64 a; rhs=modint{(s >> a,a)}; return s;
    }
};

using mint=modint<MOD>;

struct LowestCommonAncestor{
    int n,h;
    vector<vector<int>> G,par;
    vector<int> dep;
    LowestCommonAncestor(int n):n(n),G(n),dep(n){
        h=1;
        while((1<<h)<=n) ++h;
        par.assign(h,vector<int>(n,-1));
    }
    void add_edge(int u,int v){
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    void dfs(int v,int p,int d){
        par[0][v]=p;
        dep[v]=d;
        for (int u:G[v]){
            if (u!=p) dfs(u,v,d+1);
        }
    }
    void build(int r=0){
        dfs(r,-1,0);
        for (int k=0;k<h-1;++k) for (int v=0;v<n;++v){
            if (par[k][v]>=0) par[k+1][v]=par[k][par[k][v]];
        }
    }
    int lca(int u,int v){
        if (dep[u]>dep[v]) swap(u,v);
        for (int k=0;k<h;++k){
            if ((dep[v]-dep[u])&1<<k) v=par[k][v];
        }
        if (u==v) return u;
        for (int k=h-1;k>=0;--k){
            if (par[k][u]!=par[k][v]) u=par[k][u],v=par[k][v];
        }
        return par[0][u];
    }
    int distance(int u,int v){
        return dep[u]+dep[v]-dep[lca(u,v)]*2;
    }
};

const int MAX_N=3e5+10;

int n,k,ok=1;
vector<int> G[MAX_N];
int a[MAX_N],dep[MAX_N],P[MAX_N];
mint dp[MAX_N][2];
queue<int> que;

void dfs1(int v,int p){
    if (!ok) return;
    for (int u:G[v]){
        if (u==p) continue;
        dfs1(u,v);
        if (a[u]&&P[a[u]]!=u) que.emplace(a[u]);
        while(!que.empty()){
            int c=que.front(); que.pop();
            if (a[v]!=c&&a[v]) ok=0;
            else a[v]=c;
        }
    }
}

void dfs2(int v,int p){
    if (a[v]){
        dp[v][1]=1;
        for (int u:G[v]){
            if (u==p) continue;
            dfs2(u,v);
            dp[v][1]*=dp[u][0]+dp[u][1];
        }
    } else {
        vector<pair<mint,mint>> ch;
        dp[v][0]=1;
        for (int u:G[v]){
            if (u==p) continue;
            dfs2(u,v);
            dp[v][0]*=dp[u][0]+dp[u][1];
            ch.emplace_back(dp[u][0]+dp[u][1],dp[u][1]);
        }
        for (auto p:ch) dp[v][1]+=dp[v][0]/p.first*p.second;
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for (int i=0;i<n;++i) cin >> a[i];
    LowestCommonAncestor LCA(n);
    for (int i=0;i<n-1;++i){
        int u,v; cin >> u >> v; --u,--v;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
        LCA.add_edge(u,v);
    }
    LCA.build();
    for (int i=1;i<=k;++i) P[i]=-1;
    for (int v=0;v<n;++v) if (a[v]){
        if (P[a[v]]<0) P[a[v]]=v;
        else P[a[v]]=LCA.lca(P[a[v]],v);
    }
    dfs1(0,-1);
    if (!ok){cout << 0 << '\n'; return 0;}
    dfs2(0,-1);
    cout << dp[0][1] << '\n';
}