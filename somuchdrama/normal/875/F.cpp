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
const int N=2e5+1;
int p[N],size[N],es[N];
int get(int x){
    return x==p[x]?x:(p[x]=get(p[x]));
}
struct kek{
    int x,y,c;
}a[N];
void join(int x,int y){
    p[y]=x;
    size[x]+=size[y];
    es[x]+=es[y]+1;
}
int32_t main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        p[i]=i;
        size[i]=1;
        es[i]=0;
    }
    forn(i,m)cin>>a[i].x>>a[i].y>>a[i].c;
    sort(a,a+m,[](const kek&p1,const kek&p2){return p1.c>p2.c;});
    int ans=0;
    forn(i,m){
        int x=get(a[i].x);
        int y=get(a[i].y);
        if(x!=y){
            if(size[x]>es[x]&&size[y]>es[y]){
                ans+=a[i].c;
                join(x,y);
            }else if(size[x]>es[x]){
                ans+=a[i].c;
                es[x]++;
            }else if(size[y]>es[y]){
                ans+=a[i].c;
                es[y]++;
            }
        }else if(size[x]>es[x]){
            ans+=a[i].c;
            es[x]++;
        }
    }
    cout<<ans<<'\n';

    return 0;
}