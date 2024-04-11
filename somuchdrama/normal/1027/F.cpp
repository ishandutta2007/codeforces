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
const int N=2e6+1;
int p[N],size[N],es[N];
int get(int x){
    return x==p[x]?x:(p[x]=get(p[x]));
}
int a[N],b[N];
void join(int x,int y){
    x=get(x);
    y=get(y);
    if(x^y){
        p[y]=x;
        size[x]+=size[y];
        es[x]+=es[y]+1;
    }else{
        es[x]++;
    }
}
int xs[N],mx[N],sx[N];
int32_t main(){
    int n,m=0;
    cin>>n;
    forn(i,n){
        cin>>a[i]>>b[i];
        xs[m++]=a[i];
        xs[m++]=b[i];
    }
    sort(xs,xs+m);
    m=std::unique(xs,xs+m)-xs;
    forn(i,m){
        p[i]=i;
        size[i]=1;
        es[i]=0;
    }
    forn(i,n){
        int x=std::lower_bound(xs,xs+m,a[i])-xs;
        int y=std::lower_bound(xs,xs+m,b[i])-xs;
        join(x,y);
    }
    forn(i,m){
        int c=get(i);
        upx(sx[c],xs[i]);
        if(sx[c]>mx[c])swap(sx[c],mx[c]);
    }
    int ans=0;
    forn(i,m){
        if(i==get(i)){
            dbg(es[i],size[i]);
            if(es[i]>size[i]){
                ans=-1;
                break;
            }
            if(es[i]==size[i])upx(ans,mx[i]);
            else upx(ans,sx[i]);
        }
    }
    cout<<ans<<'\n';

    return 0;
}