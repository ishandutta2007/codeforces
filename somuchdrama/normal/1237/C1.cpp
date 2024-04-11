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

const int N=3e5+5;
struct pt{
    int x,y,z,i;
}a[N];
int xs[N],ys[N],zs[N],cx=0,cy=0,cz=0;
vector<pt> b[N];
vector<pt> c[N];
vector<pt> ans;
bool zc(const pt&p1,const pt&p2){
    return p1.z<p2.z;
}
int32_t main(){
    int n;
    cin>>n;
    forn(i,n){
        cin>>a[i].x>>a[i].y>>a[i].z;
        a[i].i=i+1;
        xs[cx++]=a[i].x;
    }
    sort(xs,xs+cx);cx=std::unique(xs,xs+cx)-xs;
    forn(i,n){
        a[i].x=std::lower_bound(xs,xs+cx,a[i].x)-xs;
        b[a[i].x].pb(a[i]);
    }
    vector<pt> zhopa;
    forn(x,cx){
        cy=0;
        for(pt&p:b[x]){
            ys[cy++]=p.y;
        }
        sort(ys,ys+cy);cy=std::unique(ys,ys+cy)-ys;
        for(pt&p:b[x]){
            p.y=std::lower_bound(ys,ys+cy,p.y)-ys;
            c[p.y].pb(p);
        }
        vector<pt> rest;
        forn(y,cy){
            sort(c[y].begin(), c[y].end(),zc);
            for(int j=0;j+1<c[y].size();j+=2){
                ans.pb(c[y][j]);
                ans.pb(c[y][j+1]);
            }
            if(c[y].size()&1){
                rest.pb(c[y].back());
            }
            c[y].clear();
        }
        for(int j=0;j+1<rest.size();j+=2){
            ans.pb(rest[j]);
            ans.pb(rest[j+1]);
        }
        if(rest.size()&1)zhopa.pb(rest.back());
    }
    for(int j=0;j+1<zhopa.size();j+=2){
        ans.pb(zhopa[j]);
        ans.pb(zhopa[j+1]);
    }
    int en=0;
    for(pt p:ans){
        cout<<p.i;
        if(en)cout<<'\n';
        else cout<<' ';
        en^=1;
    }

    return 0;
}