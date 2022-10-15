#include <bits/stdc++.h>
using std::cerr;using std::cin;using std::cout;using std::abs;using std::min;using std::max;using std::swap;using std::map;using std::unordered_map;using std::unordered_set;using std::bitset;using std::pair;using std::set;using std::string;using std::vector;using std::sort;using ll=long long;using uint=unsigned int;using pii=pair<int,int>;using pll=pair<ll,ll>;using ull = unsigned long long;using ld=long double;template<typename T>void _dbg(const char*s,T h){cerr<<s<<" = "<<h<<"\n";}template<typename T,typename...Ts>void _dbg(const char*s,T h,Ts...t){int b=0;while(((b+=*s=='(')-=*s==')')!=0||*s!=',')cerr<<*s++;cerr<<" = "<<h<<",";_dbg(s+1,t...);}// break continue pop_back 998244353
#define int ll
#define pii pll
#define f first
#define s second
#define pb emplace_back
#define forn(i,n) for(int i=0;i<(n);++i)
struct init{init(){cin.tie(0);std::iostream::sync_with_stdio(0);cout<<std::fixed<<std::setprecision(10);cerr<<std::fixed<<std::setprecision(5);}~init(){
#ifdef LOCAL
#define dbg(...) _dbg(#__VA_ARGS__,__VA_ARGS__)
cerr<<"Time elapsed: "<<(double)clock()/CLOCKS_PER_SEC<<"s.\n";
#else
#define dbg(...) 
#endif
}}init;template<typename T,typename U>void upx(T&x,U y){if(x<y)x=y;}template<typename T,typename U>void upn(T&x,U y){if(x>y)x=y;}
const int N=1e6+6,OO=1e9;
int t[N*4],mod[N*4],sh=1;
void apply(int v,int x){ 
    t[v]+=x; //<--
    mod[v]+=x; //<--
}
void push(int v,int tl,int tr){
    if(tl!=tr){
        apply(v+v,mod[v]);
        apply(v+v+1,mod[v]); 
        mod[v]=0; //<--
    }
}
inline void recalc(int v){
    t[v]=max(t[v+v],t[v+v+1]);
}
void build(){for(int i=sh-1;i>0;--i)recalc(i);}
// int get(int v,int tl,int tr,int l,int r){
//     if(l>tr||r<tl)return -OO;//<--
//     if(l<=tl&&tr<=r)return t[v];
//     push(v,tl,tr);
//     int tm=(tl+tr)/2;
//     int res=-OO; //<--
//     if(tm>=l)upx(res,get(v+v,tl,tm,l,r)); //<--
//     if(tm+1<=r)upx(res,get(v+v+1,tm+1,tr,l,r)); //<--
//     return res;
// }
void add(int v,int tl,int tr,int l,int r,int val){
    if(l<=tl&&tr<=r){
        apply(v,val);
        return;
    }
    push(v,tl,tr);
    int tm=(tl+tr)/2;
    if(tm>=l)add(v+v,tl,tm,l,r,val);
    if(tm+1<=r)add(v+v+1,tm+1,tr,l,r,val);
    recalc(v);
}
void add(int l,int r,int val){
    add(1,0,sh-1,l,r,val);
}
// int get(int l,int r){
//     return get(1,0,sh-1,l,r);
// }
int spusk(){
    int v=1,tl=0,tr=sh-1;
    push(v,tl,tr);
    if(t[v]<=0)return -1;
    while(v<sh){
        push(v,tl,tr);
        int tm=(tl+tr)/2;
        if(t[v+v+1]>0){
            v=v+v+1;
            tl=tm+1;
        }else{
            v=v+v;
            tr=tm;
        }
    }
    return tl;
}
int a[N],b[N];
int32_t main() {
    while(sh<N)sh*=2;
    int n,m;
    cin>>n>>m;
    forn(i,n){
        cin>>a[i];
        add(0,a[i],+1);
    }
    forn(i,m){
        cin>>b[i];
        add(0,b[i],-1);
    }
    // forn(i,sh+sh){
    //     dbg(i,t[i],mod[i]);
    // }
    int q;
    cin>>q;
    while(q--){
        int p,x,y;
        cin>>p>>x>>y;
        --x;
        if(p==1){
            add(0,a[x],-1);
            a[x]=y;
            add(0,a[x],+1);
        }else{
            add(0,b[x],+1);
            b[x]=y;
            add(0,b[x],-1);
        }
        // forn(i,sh+sh){
        //     dbg(i,t[i],mod[i]);
        // }
        cout<<spusk()<<'\n';
    }

    return 0;
}