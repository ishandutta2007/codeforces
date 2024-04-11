#include <bits/stdc++.h>
using namespace std;using ll=long long;using uint=unsigned int;using pii=pair<int,int>;using pll=pair<ll,ll>;using ull = unsigned long long;using ld=long double;template<typename T>void _(const char*s,T h){cerr<<s<<" = "<<h<<"\n";}template<typename T,typename...Ts>void _(const char*s,T h,Ts...t){int b=0;while(((b+=*s=='(')-=*s==')')!=0||*s!=',')cerr<<*s++;cerr<<" = "<<h<<",";_(s+1,t...);}// break continue pop_back 998244353
#define int ll
#define pii pll
#define f first
#define s second
#define pb emplace_back
#define forn(i,n) for(int i=0;i<(n);++i)
#define sz(a)((int)(a).size())
#define sqr(x) ((x)*(x))
struct init{init(){cin.tie(0);std::iostream::sync_with_stdio(0);cout<<std::fixed<<std::setprecision(10);cerr<<std::fixed<<std::setprecision(5);}~init(){
#ifdef LOCAL
#define dbg(...) _(#__VA_ARGS__,__VA_ARGS__)
cerr<<"Time elapsed: "<<(double)clock()/CLOCKS_PER_SEC<<"s.\n";
#else
#define dbg(...) 
#endif
}}init;template<typename T,typename U>void upx(T&x,U y){if(x<y)x=y;}template<typename T,typename U>void upn(T&x,U y){if(x>y)x=y;}mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());const int D=4,dx[]={+1,0,-1,0},dy[]={0,+1,0,-1};
const int N=5e5+5,OO=1e18;
int a[N],b[N],p[N];
int t[N*4],mod[N*4];
int sh=1;
void apply(int v,int x){ 
    t[v]+=x; //<--
    mod[v]+=x; //<--
}
void push(int v){
    apply(v+v,mod[v]);
    apply(v+v+1,mod[v]); 
    mod[v]=0; //<--
}
void build(int n){
    while(sh<n)sh*=2;
    forn(i,sh+sh)t[i]=OO*2;//<--
    forn(i,sh+sh)mod[i]=0;//<--
    t[sh]=0;
}
int get(int v,int tl,int tr,int i){
    if(tl==tr)return t[v];
    push(v);
    int tm=(tl+tr)/2;
    if(tm>=i)return get(v+v,tl,tm,i); //<--
    else return get(v+v+1,tm+1,tr,i); //<--
}
void add(int v,int tl,int tr,int l,int r,int val){
    if(l<=tl&&tr<=r){
        apply(v,val);
        return;
    }
    push(v);
    int tm=(tl+tr)/2;
    if(tm>=l)add(v+v,tl,tm,l,r,val);
    if(tm+1<=r)add(v+v+1,tm+1,tr,l,r,val);
}
void add(int l,int r,int val){
    add(1,0,sh-1,l,r,val);
}
void cha(int v,int tl,int tr,int i,int val){
    if(tl==tr){
        upn(t[v],val);
        return;
    }
    push(v);
    int tm=(tl+tr)/2;
    if(tm>=i)cha(v+v,tl,tm,i,val);
    else cha(v+v+1,tm+1,tr,i,val);
}
void cha(int i,int val){
    cha(1,0,sh-1,i,val);
}
int get(int i){
    return get(1,0,sh-1,i);
}

vector<int> wa[N],wb[N];
int pre[N];

int32_t main(){
    int n,m;
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        wa[a[i]].pb(i);
    }
    int sum=0;
    for(int i=1;i<=n;++i){
        cin>>p[i];
        sum+=p[i];
    }
    cin>>m;
    for(int i=1;i<=m;++i){
        cin>>b[i];
        wb[b[i]].pb(i);
    }
    build(m+1);
    for(int i=1;i<=n;++i){
        for(int j:wb[a[i]])pre[j]=get(j-1);
        int pos=lower_bound(b,b+m+1,a[i])-b;
        if(p[i]>=0)add(0,pos-1,p[i]);
        else add(0,m,p[i]);
        for(int j:wb[a[i]])cha(j,pre[j]);
    }
    int res=get(m);
    if(res>=OO)cout<<"NO\n";
    else cout<<"YES\n"<<res<<'\n';

    return 0;
}