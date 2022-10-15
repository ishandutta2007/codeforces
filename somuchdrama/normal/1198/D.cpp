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

const int N=52;
char f[N][N];
int p[N][N];
int d[N][N][N][N];
int get(int i1,int j1,int i2,int j2){
    return p[i2][j2]-p[i1-1][j2]-p[i2][j1-1]+p[i1-1][j1-1];
}

int32_t main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;++i)for(int j=1;j<=n;++j){
        cin>>f[i][j];
        p[i][j]=p[i-1][j]+p[i][j-1]-p[i-1][j-1]+(f[i][j]=='#');
    }
    for(int x=1;x<=n;++x)for(int y=1;y<=n;++y)for(int i1=1;x+i1-1<=n;++i1)for(int j1=1;y+j1-1<=n;++j1){
        int i2=i1+x-1,j2=j1+y-1;
        if(i1==i2&&j1==j2){d[i1][j1][i2][j2]=(f[i1][j1]=='#');continue;}
        int&u=d[i1][j1][i2][j2];u=max(x,y);
        for(int im=i1;im<=i2;++im)if(!get(im,j1,im,j2))upn(u,d[i1][j1][im-1][j2]+d[im+1][j1][i2][j2]);
        for(int jm=j1;jm<=j2;++jm)if(!get(i1,jm,i2,jm))upn(u,d[i1][j1][i2][jm-1]+d[i1][jm+1][i2][j2]);
    }
    cout<<d[1][1][n][n]<<'\n';

    return 0;
}