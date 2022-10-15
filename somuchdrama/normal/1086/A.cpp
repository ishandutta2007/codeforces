#include <bits/stdc++.h>
using std::cerr;using std::cin;using std::cout;using std::abs;using std::min;using std::max;using std::swap;using std::map;using std::unordered_map;using std::unordered_set;using std::bitset;using std::pair;using std::set;using std::string;using std::vector;using std::sort;using ll=long long;using uint=unsigned int;using pii=pair<int,int>;using pll=pair<ll,ll>;using ull = unsigned long long;using ld=long double;using vci=vector<int>;using vcl=vector<ll>;template<typename T>void _dbg(const char*_s,T _h){cerr<<_s<<" = "<<_h<<"\n";}template<typename T,typename...Ts>void _dbg(const char*_s,T _h,Ts..._t){int _b=0;while(((_b+=*_s=='(')-=*_s==')')!=0||*_s!=',')cerr<<*_s++;cerr<<" = "<<_h<<",";_dbg(_s+1,_t...);}
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
#define int ll



int32_t main() {

    vector<pii> a(3);
    for(pii &i:a)
        cin>>i.f>>i.s;
    sort(a.begin(), a.end());
    int mx=a[1].f;
    set<pii> ans;
    int mny=123456789,mxy=-123456789;
    for(pii i:a){
        upn(mny,i.s);
        upx(mxy,i.s);
    }
    for(int y=mny;y<=mxy;++y)
        ans.insert({mx,y});
    for(int x=a[0].f;x<mx;++x){
        ans.insert({x,a[0].s});
    }
    for(int x=a[1].f;x<=a[2].f;++x){
        ans.insert({x,a[2].s});
    }
    cout<<ans.size()<<'\n';
    for(pii i:ans){
        cout<<i.f<<' '<<i.s<<'\n';
    }




    return 0;
}