#include <bits/stdc++.h>
using std::cerr;using std::cin;using std::cout;using std::abs;using std::min;using std::max;using std::swap;using std::map;using std::unordered_map;using std::unordered_set;using std::bitset;using std::pair;using std::set;using std::string;using std::vector;using std::sort;using ll=long long;using uint=unsigned int;using pii=pair<int,int>;using pll=pair<ll,ll>;using ull = unsigned long long;using ld=long double;template<typename T>void _(const char*s,T h){cerr<<s<<" = "<<h<<"\n";}template<typename T,typename...Ts>void _(const char*s,T h,Ts...t){int b=0;while(((b+=*s=='(')-=*s==')')!=0||*s!=',')cerr<<*s++;cerr<<" = "<<h<<",";_(s+1,t...);}// break continue pop_back 998244353
#define int ll
#define pii pll
#define f first
#define s second
#define pb emplace_back
#define forn(i,n) for(int i=0;i<(n);++i)
#define sqr(x) ((x)*(x))
struct init{init(){cin.tie(0);std::iostream::sync_with_stdio(0);cout<<std::fixed<<std::setprecision(10);cerr<<std::fixed<<std::setprecision(5);}~init(){
#ifdef LOCAL
#define dbg(...) _(#__VA_ARGS__,__VA_ARGS__)
cerr<<"Time elapsed: "<<(double)clock()/CLOCKS_PER_SEC<<"s.\n";
#else
#define dbg(...) 
#endif
}}init;template<typename T,typename U>void upx(T&x,U y){if(x<y)x=y;}template<typename T,typename U>void upn(T&x,U y){if(x>y)x=y;}

const int N=2e5+5,OO=1e9+7;
int a[N];
int t[N*4];
int nxl[N];
int nxg[N];

int n,sh=1;
void build(){
    forn(i,N*4)t[i]=OO;
    while(sh<n+n)sh*=2;
    forn(i,n+n)t[i+sh]=a[i];
    for(int i=sh;--i;)t[i]=min(t[i+i],t[i+i+1]);
}
int get(int l,int r){//[..]
    int res=OO;
    for(l+=sh,r+=sh+1;l<r;l/=2,r/=2){
        if(l&1)upn(res,t[l++]);
        if(r&1)upn(res,t[--r]);
    }
    return res;
}
int ans[N];
int st[N];
int dist(int i,int j){
    if(i<j)return j-i;
    else return j-i+n;
}
int u[N];
int calc(int v){
    if(ans[v]==-2){
        if(u[v]){
            ans[v]=-1;
        }else{
            u[v]=1;
            if(dist(v,nxg[v])>dist(v,nxl[v])){
                ans[v]=dist(v,nxl[v]);
            }else{
                int go=calc(nxg[v]);
                if(go==-1)ans[v]=-1;
                else ans[v]=dist(v,nxg[v])+go;
            }
        }
    }
    return ans[v];
}
int32_t main(){
    cin>>n;
    forn(i,n){
        ans[i]=-2;
        cin>>a[i];
        a[n+i]=a[i];
    }
    build();
    int p=0;
    a[n+n]=OO;
    st[p]=n+n;
    for(int i=n+n-1;i>=0;--i){
        while(a[i]>a[st[p]])p--;
        nxg[i]=st[p]%n;
        st[++p]=i;
    }
    forn(i,n){
        int tar=(a[i]-1)/2;
        if(get(0,n-1)>tar){
            nxl[i]=i;
            continue;
        }
        int l=i,r=i+n;
        while(r-l>1){
            int m=(l+r)/2;
            if(get(i,m)<=tar)r=m;
            else l=m;
        }
        nxl[i]=r%n;
    }
    forn(i,n)cout<<calc(i)<<' ';
    cout<<'\n';

    return 0;
}