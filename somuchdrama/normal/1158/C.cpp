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

const int N=5e5+5;
int go[N];
int a[N],prev[N];
set<int,std::greater<int>> g[N];
int s[N];
void dfs1(int v){
    s[v]=1;
    for(int to:g[v]){
        dfs1(to);
        s[v]+=s[to];
    }
}
void dfs(int v){
    int val=a[v]-s[v];
    for(int to:g[v]){
        val+=s[to];
        a[to]=val;
        dfs(to);
    }
}
int32_t main() {

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=1;i<=n+1;++i)g[i].clear();
        for(int i=1;i<=n;++i){
            cin>>go[i];
            if(go[i]==-1)go[i]=i+1;
            g[go[i]].insert(i);
        }
        int ok=1;
        vector<int> op;
        for(int i=1;i<=n&&ok;++i){
            for(int j:g[i]){
                if(op.empty()||op.back()!=j){
                    ok=0;
                    break;
                }
                op.pop_back();
            }
            op.pb(i);
        }
        if(!ok){
            cout<<"-1\n";
            continue;
        }
        dfs1(n+1);
        a[n+1]=n+1;
        dfs(n+1);
        for(int i=1;i<=n;++i)
            cout<<a[i]<<' ';
        cout<<'\n';
    }

    return 0;
}