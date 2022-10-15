#include <bits/stdc++.h>
using namespace std;using ll=long long;using uint=unsigned int;using pii=pair<int,int>;using pll=pair<ll,ll>;using ull = unsigned long long;using ld=long double;template<typename T>void _(const char*s,T h){cerr<<s<<" = "<<h<<"\n";}template<typename T,typename...Ts>void _(const char*s,T h,Ts...t){int b=0;while(((b+=*s=='(')-=*s==')')!=0||*s!=',')cerr<<*s++;cerr<<" = "<<h<<",";_(s+1,t...);}// break continue pop_back 998244353
#define int ll
#define pii pll
#define f first
#define s second
#define pb emplace_back
#define forn(i,n) for(int i=0;i<(n);++i)
#define sqr(x) ((x)*(x))
struct init{init(){cin.tie(0);iostream::sync_with_stdio(0);cout<<fixed<<setprecision(10);cerr<<fixed<<setprecision(5);}~init(){
#ifdef LOCAL
#define dbg(...) _(#__VA_ARGS__,__VA_ARGS__)
cerr<<"Time elapsed: "<<(double)clock()/CLOCKS_PER_SEC<<"s.\n";
#else
#define dbg(...) 
#endif
}}init;template<typename T,typename U>void upx(T&x,U y){if(x<y)x=y;}template<typename T,typename U>void upn(T&x,U y){if(x>y)x=y;}
const int N=5e5+5;
int a[N];
int mx[N*4];
int s=1,n;
void pu(int l,int r,int x){
    for(l+=s,r+=s+1;l<r;l/=2,r/=2){
        if(l&1)upn(mx[l++],x);
        if(r&1)upn(mx[--r],x);
    }
}
void out(int v,int px=1e9){
    upn(mx[v],px);
    if(v<s){
        upn(px,mx[v]);
        out(v+v,px);
        out(v+v+1,px);
    }else if(v<s+n)cout<<mx[v]<<' ';
}
map<int,vector<int>> w;
int lt[N],b[N];
int ans=0;
void kek(int r,int x){
    if(r==n)return;
    int l=lt[r];
    int len=r-l+1;
    upx(ans,(len-1)/2);
    int m=(l+r)/2;
    if(b[l]==1&&b[r]==2)pu(l,m,x);
    if(b[l]==2&&b[r]==1)pu(m+1,r,x);
    if(b[l]==1&&b[r]==1)pu(l,r,x);
}
int32_t main(){
    cin>>n;
    forn(i,n){
        cin>>a[i];
        w[a[i]].pb(i);
    }
    while(s<n)s*=2;
    forn(i,s+s)mx[i]=1e9;
    set<int> m;
    forn(i,n+1){
        lt[i]=i;
        b[i]=2;
        m.insert(i);
    }
    for(auto&[k,v]:w){
        for(int i:v){
            b[i]=1;
            int sl=(i&&b[i-1]==2);
            int sr=(i+1<n&&b[i+1]==2);
            if(sl&&sr){
                int er=*m.lower_bound(i+1);
                m.erase(i-1);
                m.erase(i);
                lt[er]=lt[i-1];
            }else if(sl){
                int er=*m.lower_bound(i+1);
                m.erase(i-1);
                m.insert(i);
                lt[er]=i+1;
                lt[i]=lt[i-1];
            }else if(sr){
                int er=*m.lower_bound(i+1);
                m.erase(i);
                if(i){
                    m.insert(i-1);
                    lt[i-1]=lt[i];
                }
                lt[er]=i;
            }else{
                int er=*m.lower_bound(i);
                if(i){
                    m.insert(i-1);
                    lt[i-1]=lt[er];
                }
                lt[er]=i+1;
                lt[i]=i;
                m.insert(i);
            }
        }
        for(int i:v)for(int j=-1;j<2;++j)kek(*m.lower_bound(i+j),k);
    }
    cout<<ans<<'\n';
    out(1);
    cout<<'\n';
    return 0;
}