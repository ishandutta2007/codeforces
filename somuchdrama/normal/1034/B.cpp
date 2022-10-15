// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC optimize("O3,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using std::cerr;using std::cin;using std::cout;using std::abs;using std::min;using std::max;using std::swap;using std::map;using std::unordered_map;using std::unordered_set;using std::bitset;using std::pair;using std::set;using std::string;using std::vector;using std::sort;using ll=long long;using uint=unsigned int;using pii=pair<int,int>;using pll=pair<ll,ll>;using ull = unsigned long long;using ld=long double;using vci=vector<int>;using vcl=vector<ll>;template<typename T>void _dbg(const char*_s,T _h){cerr<<_s<<" = "<<_h<<"\n";}template<typename T,typename...Ts>void _dbg(const char*_s,T _h,Ts..._t){int _b=0;while(((_b+=*_s=='(')-=*_s==')')!=0||*_s!=',')cerr<<*_s++;cerr<<" = "<<_h<<",";_dbg(_s+1,_t...);}
#define f first
#define s second
#define pb emplace_back
#define fon(i,n) for(int i=0;i<(n);++i)
struct init{init(){cin.tie(0);std::iostream::sync_with_stdio(0);cout<<std::fixed<<std::setprecision(10);cerr<<std::fixed<<std::setprecision(5);}~init(){
#ifdef LOCAL
#define dbg(...) _dbg(#__VA_ARGS__,__VA_ARGS__)
cerr<<"Time elapsed: "<<(double)clock()/CLOCKS_PER_SEC<<"s.\n";
#else
#define dbg(...) 
#endif
}}init;template<typename T,typename U>void upx(T&x,U y){if(x<y)x=y;}template<typename T,typename U>void upn(T&x,U y){if(x>y)x=y;}
#define int ll

const int N=2018;
int num[20][20];

// vector<int> g[N];
// int kl[N], kr[N];
// bool used[N];

// bool dfskuhn(int v) {
//     if (used[v]) 
//         return 0;
//     used[v] = 1;
//     for (int to : g[v]) 
//         if (!kr[to]) 
//             return kl[kr[to] = v] = to;
//     for (int to : g[v]) 
//         if (dfskuhn(kr[to])) 
//             return kl[kr[to] = v] = to;
//     return 0;
// }

// vector<pii> kuhn(int n) {
//     for (int go = 1; go--;) {
//         memset(used, 0, sizeof used);
//         for (int i = 1; i <= n; ++i)
//             if (!kl[i] && dfskuhn(i))
//                 go = 1;
//     }

//     vector<pii> ans;
//     for (int i = 1; i <= n; ++i)
//         if (kl[i]){
//             dbg(i,kl[i]);
//             ans.pb(i, kl[i]);
//         }

//     return ans;
// }

vector <int> g[N];
int mt[N];
int used[N];
 
bool try_kuhn (int v) {
    if (used[v])  return false;
    used[v] = true;
    for (size_t i=0; i<g[v].size(); ++i) {
        int to = g[v][i];
        if (mt[to] == -1 || try_kuhn (mt[to])) {
            mt[to] = v;
            return true;
        }
    }
    return false;
}


const int D=12;
int dx[D]={0,1,2,3,+2,+1,+0,-1,-2,-3,-2,-1};
int dy[D]={3,2,1,0,-1,-2,-3,-2,-1,+0,+1,+2};
int n,m;
bool ok(int x,int y){
    return 0<=x&&x<n&&0<=y&&y<m;
}

int32_t main() {

    cin>>n>>m;
    if(m>n)swap(n,m);

    int x=max(0ll,(n-15)/6);
    int ans=6*x*m;
    n-=6*x;

    x=max(0ll,(m-15)/6);
    ans+=6*x*n;
    m-=6*x;

    int p=0,q=0;
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)
            if((i+j)&1){
                num[i][j]=p++;
                dbg(i,j,num[i][j]);
            }
            else 
                num[i][j]=q++;
    // p--,q--;

    fon(i,n)
        fon(j,m)
            if((i+j)&1)
                fon(d,D){
                    int ti=i+dx[d];
                    int tj=j+dy[d];
                    if(ok(ti,tj)){
                        g[num[i][j]].pb(num[ti][tj]);
                    }
                }

    memset(mt,-1,sizeof mt);
    for (int v=0; v<p; ++v) {
        memset(used,0,sizeof used);
        // used.assign (n, false);
        try_kuhn (v);
    }
 
    for (int i=0; i<q; ++i)
        if (mt[i] != -1){
            dbg(i,mt[i]);
            ans+=2;
        }

    cout<<ans<<'\n';


    return 0;
}