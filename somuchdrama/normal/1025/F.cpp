// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using std::sort;using std::cerr;using std::cin;using std::cout;using std::abs;using std::min;using std::max;using std::swap;using std::map;using std::unordered_map;using std::unordered_set;using std::bitset;using std::pair;using std::set;using std::string;using std::vector;using ll=long long;using uint=unsigned int;using pii=pair<int,int>;using pll=pair<ll,ll>;using ull = unsigned long long;using ld=long double;using vci=vector<int>;using vcl=vector<ll>;template<typename T>void _dbg(const char*_s,T _h){cerr<<_s<<" = "<<_h<<"\n";}template<typename T,typename...Ts>void _dbg(const char*_s,T _h,Ts..._t){int _b=0;while(((_b+=*_s=='(')-=*_s==')')!=0||*_s!=',')cerr<<*_s++;cerr<<" = "<<_h<<",";_dbg(_s+1,_t...);}
#define f first
#define s second
#define pb emplace_back
struct init{init(){cin.tie(0);std::iostream::sync_with_stdio(0);cout<<std::fixed<<std::setprecision(10);cerr<<std::fixed<<std::setprecision(5);}~init(){
#ifdef LOCAL
#define dbg(...) _dbg(#__VA_ARGS__,__VA_ARGS__)
cerr<<"Time elapsed: "<<(double)clock()/CLOCKS_PER_SEC<<"s.\n";
#else
#define dbg(...) 
#endif
}}init;

const int N=2018;
struct point
{
    ll x, y;
    point() {}
    point(ll _x, ll _y): x(_x), y(_y) {}
};

std::istream & operator >>(std::istream & is, point & p) {
    return is >> p.x >> p.y;
}

std::ostream & operator <<(std::ostream & os, point & p) {
    return os << p.x << ' ' << p.y;
}

struct vc
{
    ll x, y;
    vc() {}
    vc(ll _x, ll _y): x(_x), y(_y) {}
    vc(point a, point b) {
        x = b.x - a.x;
        y = b.y - a.y;
    }
};

point operator +(point a, vc v) {
    return {a.x + v.x, a.y + v.y};
}
vc turn(vc a) {
    return {a.y, -a.x};
}
ll operator %(vc a, vc b) {
    return a.x*b.y-a.y*b.x;
}

inline bool pr(const vc & v) {
    return v.y<0||(v.y==0&&v.x<0);
}
point a[N];
pii ds[N*N];
bool cmp(const pii&p,const pii&q){
    vc v1(a[p.f],a[p.s]),v2(a[q.f],a[q.s]);
    return v1%v2>0;
}
int p[N];
int w[N];

int32_t main() {

    int n;
    cin>>n;
    for(int i=0;i<n;++i)
        cin>>a[i];
    int m=0;
    for(int i=0;i<n;++i)
        for(int j=i+1;j<n;++j){
            vc v(a[i],a[j]);
            if(pr(v))ds[m++]={j,i};
            else ds[m++]={i,j};
        }
    sort(ds,ds+m,cmp);
    std::iota(p,p+n,0);
    point c1=a[ds[0].f],c2=a[ds[0].s];
    sort(p,p+n,[&c1,&c2](int p1,int p2){
        vc v0(c1,c2);
        vc v1(c1,a[p1]);
        vc v2(c1,a[p2]);
        return v0%v1==v0%v2?a[p1].x<a[p2].x:v0%v1<v0%v2;
    });
    dbg(ds[0].f,ds[0].s);
    for (int i=0;i<n;++i){
        w[p[i]]=i;
    }
    ll ans=0;
    for (int i=0;i<m;++i){
        int x=ds[i].f,y=ds[i].s;
        int ft=w[y]+1;
        ll cup=n-ft;
        ll cdw=ft-2;
        ll tup=(cup*(cup-1))/2;
        ll tdw=(cdw*(cdw-1))/2;
        ans+=tup*tdw;
        swap(w[x],w[y]);
    }
    cout<<ans<<'\n';


    return 0;
}