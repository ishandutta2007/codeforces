#include <bits/stdc++.h>
using std::cerr;using std::cin;using std::cout;using std::abs;using std::min;using std::max;using std::swap;using std::map;using std::unordered_map;using std::unordered_set;using std::bitset;using std::pair;using std::set;using std::string;using std::vector;using std::sort;using ll=long long;using uint=unsigned int;using pii=pair<int,int>;using pll=pair<ll,ll>;using ull = unsigned long long;using ld=long double;template<typename T>void _dbg(const char*_s,T _h){cerr<<_s<<" = "<<_h<<"\n";}template<typename T,typename...Ts>void _dbg(const char*_s,T _h,Ts..._t){int _b=0;while(((_b+=*_s=='(')-=*_s==')')!=0||*_s!=',')cerr<<*_s++;cerr<<" = "<<_h<<",";_dbg(_s+1,_t...);}
#define int ll
#define f first
#define s second
#define pb emplace_back
#define sz(a) ((int)a.size())
#define forn(i,n) for(int i=0;i<(n);++i)
struct init{init(){cin.tie(0);std::iostream::sync_with_stdio(0);cout<<std::fixed<<std::setprecision(10);cerr<<std::fixed<<std::setprecision(5);}~init(){
#ifdef LOCAL
#define dbg(...) _dbg(#__VA_ARGS__,__VA_ARGS__)
cerr<<"Time elapsed: "<<(double)clock()/CLOCKS_PER_SEC<<"s.\n";
#else
#define dbg(...) 
#endif
}}init;template<typename T,typename U>void upx(T&x,U y){if(x<y)x=y;}template<typename T,typename U>void upn(T&x,U y){if(x>y)x=y;}
#ifdef LOCAL
const int N=10,K=3,M=998244353;
#else
const int N=1e5+5,K=400,M=998244353;
#endif
int a[N],k;
struct block{
    int dp[K]={0};
    int f[K]={0};
    int g[K+1]={0};
    int h=0,mn=0,ans=0;
    void dec(){
        h--;
        int pos=k-h-mn;
        if(pos>=0&&pos<=K)ans+=g[pos];
    }
    void inc(){
        int pos=k-h-mn;
        if(pos>=0&&pos<=K)ans-=g[pos];
        h++;
    }
    void kok(){
        ans=h=0;
        mn=M;
        forn(i,K)upn(mn,f[i]);
        forn(i,K){
            g[f[i]-mn]+=dp[i];
            if(f[i]<=k)ans+=dp[i];
        }
        ans%=M;
    }
    void decpart(int l,int r){
        forn(i,K){
            g[f[i]-mn]=0;
            f[i]+=h;
        }
        for(int i=l;i<=r;++i)f[i]--;
        kok();
    }
    void incpart(int l,int r){
        forn(i,K){
            g[f[i]-mn]=0;
            f[i]+=h;
        }
        for(int i=l;i<=r;++i)f[i]++;
        kok();
    }
    void kek(int i,int x){
        dp[i]=x;
        g[f[i]-mn]+=dp[i];
        if(f[i]<=k)ans+=dp[i];
    }
}bs[N/K+2];
void decrange(int l,int r){
    if(r<l)return;
    int bl=l/K,br=r/K;
    if(bl==br)bs[bl].decpart(l%K,r%K);
    else{
        bs[bl].decpart(l%K,K-1);
        for(int i=bl+1;i<br;++i)bs[i].dec();
        bs[br].decpart(0,r%K);
    }
}
void incrange(int l,int r){
    if(r<l)return;
    int bl=l/K,br=r/K;
    if(bl==br)bs[bl].incpart(l%K,r%K);
    else{
        bs[bl].incpart(l%K,K-1);
        for(int i=bl+1;i<br;++i)bs[i].inc();
        bs[br].incpart(0,r%K);
    }
}
int w[N],ww[N];
int32_t main() {
    int n;
    cin>>n>>k;
    for(int i=1;i<=n;++i){
        cin>>a[i]; 
    }
    memset(ww,0,sizeof ww);
    memset(w,0,sizeof w);
    int m=(n+K)/K,dp=1;
    bs[0].kek(0,dp);
    for(int i=1;i<=n;++i){
        decrange(ww[a[i]],w[a[i]]-1);
        incrange(w[a[i]],i-1);
        dp=0;
        forn(j,m)dp+=bs[j].ans;
        dp%=M;
        bs[i/K].kek(i%K,dp);
        ww[a[i]]=w[a[i]];
        w[a[i]]=i;
    }
    if(dp<0)dp+=M;
    cout<<dp<<'\n';
    return 0;
}
/*
9 1
9 8 7 6 5 3 1 3 1

8 2
1 1 2 3 4 5 6 7

*/