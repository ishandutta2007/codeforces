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
struct pt{
    double x,y;
};
#define sqr(x) ((x)*(x))
double dist(pt a, pt b){
    return sqrt(sqr(a.x-b.x)+sqr(a.y-b.y));
}

int32_t main() {

    double a,b,c; pt p1,p2;
    cin>>a>>b>>c>>p1.x>>p1.y>>p2.x>>p2.y;
    double ans=abs(p1.x-p2.x)+abs(p1.y-p2.y);
    vector<pt> v1={{p1.x,(-c-a*p1.x)/b},{(-c-b*p1.y)/a,p1.y}};
    vector<pt> v2={{p2.x,(-c-a*p2.x)/b},{(-c-b*p2.y)/a,p2.y}};
    for (pt w1:v1)
        for(pt w2:v2){
            dbg(w1.x,w1.y,w2.x,w2.y,dist(p1,w1)+dist(w1,w2)+dist(w2,p2));
            upn(ans,dist(p1,w1)+dist(w1,w2)+dist(w2,p2));
        }
    cout<<ans<<'\n';



    return 0;
}