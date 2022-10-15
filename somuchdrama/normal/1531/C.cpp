#include <bits/stdc++.h>
using namespace std;using ll=long long;using uint=unsigned int;using pii=pair<int,int>;using pll=pair<ll,ll>;using ull = unsigned long long;using ld=long double;template<typename T>void _(const char*s,T h){cerr<<s<<" = "<<h<<"\n";}template<typename T,typename...Ts>void _(const char*s,T h,Ts...t){int b=0;while(((b+=*s=='(')-=*s==')')!=0||*s!=',')cerr<<*s++;cerr<<" = "<<h<<",";_(s+1,t...);}// break continue pop_back 998244353
#define int ll
#define pii pll
#define f first
#define s second
#define pb emplace_back
#define forn(i,n) for(int i=0;i<(n);++i)
#define sz(a)((int)(a).size())
#define sqr(x) ((x)*(x))
struct init{init(){cin.tie(0);iostream::sync_with_stdio(0);cout<<fixed<<setprecision(10);cerr<<fixed<<setprecision(5);}~init(){
#ifdef LOCAL
#define dbg(...) _(#__VA_ARGS__,__VA_ARGS__)
cerr<<"Time elapsed: "<<(double)clock()/CLOCKS_PER_SEC<<"s.\n";
#else
#define dbg(...) 
#endif
}}init;template<typename T,typename U>void upx(T&x,U y){if(x<y)x=y;}template<typename T,typename U>void upn(T&x,U y){if(x>y)x=y;}mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());const int D=4,dx[]={+1,0,-1,0},dy[]={0,+1,0,-1};
const int N=22;
char f[N][N];
bool solve(int n,int z){
    forn(i,z)forn(j,z)f[i][j]='.';
    if(n>z*z)return 0;
    if(n+2==z*z)return 0;
    int px,py;
    forn(diag,z+z-1){
        int len=diag+1,sx=diag,sy=diag-sx;
        if(len>z)len=z+z-len,sx=z-1,sy=diag-sx;
        if(n<len){
            if(n==1&&diag%2==1){
                f[px][py]=f[py][px]='.';
                n+=2;
            }
            if(n&1)f[(diag+1)/2][(diag+1)/2]='o',--n;
            for(int x=(diag-1)/2,y=diag-x;n>0;--x,++y){
                n-=2;
                f[x][y]='o';
                f[y][x]='o';
            }
            break;
        }
        for(int x=sx,y=sy;x>=0&&y<z;--x,++y)f[x][y]='o';
        n-=len;
        px=sx,py=sy;
    }
    return 1;
}
int32_t main(){
    int n;
    cin>>n;
    if(n==2){
        cout<<"-1\n";
        return 0;
    }
    if(n==7){
        cout<<"4\no...\no...\no...\noooo\n";
        return 0;
    }
    for(int z=1;z<=n;++z){
        if(solve(n,z)){
            cout<<z<<'\n';
            forn(i,z){
                forn(j,z)cout<<f[z-i-1][j];
                cout<<'\n';
            }
            break;
        }
    }
    return 0;
}