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

const int N=1e5+5;
int x[N];
struct t{
    int a,b,c;
};
int32_t main(){

    int n,m;
    cin>>n>>m;
    forn(i,m){
        int a,b,c;
        cin>>a>>b>>c;
        x[a]+=c;
        x[b]-=c;
    }
    vector<t> ans;
    set<pii,std::greater<pii>> s1,s2;
    for(int i=1;i<=n;++i){
        if(x[i]>0)s1.insert({x[i],i});
        if(x[i]<0)s2.insert({-x[i],i});
    }
    while(!s1.empty()){
        pii p1=*s1.begin();
        pii p2=*s2.begin();
        s1.erase(s1.begin());
        s2.erase(s2.begin());
        int z=min(p1.f,p2.f);
        x[p1.s]-=z;
        x[p2.s]+=z;
        ans.push_back({p1.s,p2.s,z});
        if(x[p1.s]>0)s1.insert({x[p1.s],p1.s});
        if(x[p2.s]<0)s2.insert({-x[p2.s],p2.s});
    }
    cout<<ans.size()<<'\n';
    for(auto&i:ans)cout<<i.a<<' '<<i.b<<' '<<i.c<<'\n';
    return 0;
}