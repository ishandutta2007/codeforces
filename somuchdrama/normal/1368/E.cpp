#include <bits/stdc++.h>
using namespace std;using ll=long long;using uint=unsigned int;using pii=pair<int,int>;using pll=pair<ll,ll>;using ull = unsigned long long;using ld=long double;template<typename T>void _(const char*s,T h){cerr<<s<<" = "<<h<<"\n";}template<typename T,typename...Ts>void _(const char*s,T h,Ts...t){int b=0;while(((b+=*s=='(')-=*s==')')!=0||*s!=',')cerr<<*s++;cerr<<" = "<<h<<",";_(s+1,t...);}// break continue pop_back 998244353
// #define int ll
// #define pii pll
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
 
const int N=2e5+5,B=20;
vector<int> gi[N],go[N];
int x[N];
vector<int> w[N];
int c[N*4][3];
int cnt[N];
set<pii,std::greater<pii>> s;
void add(int v){
    s.erase({cnt[v],v});
    x[v]=1;
    for(int j:w[v]){
        int res=0;
        forn(i,3){
            int o=c[j][i];
            res+=x[o];
        }
        if(res==1){
            forn(i,3){
                int o=c[j][i];
                if(!x[o]){
                    s.erase({cnt[o],o});
                    s.insert({--cnt[o],o});
                }
            }
        }
        if(res==2){
            forn(i,3){
                int o=c[j][i];
                if(x[o]&&o!=v){
                    --cnt[o];
                }
            }
        }
    }
}
void del(int v){
    s.insert({cnt[v],v});
    x[v]=0;
    cnt[v]=0;
    for(int j:w[v]){
        int res=0;
        forn(i,3){
            int o=c[j][i];
            res+=x[o];
        }
        if(!res){
            forn(i,3){
                int o=c[j][i];
                if(!x[o]&&o!=v){
                    s.erase({cnt[o],o});
                    s.insert({++cnt[o],o});
                }
            }
            cnt[v]++;
        }
        if(res==1){
            forn(i,3){
                int o=c[j][i];
                if(x[o]){
                    ++cnt[o];
                }
            }
        }
    }
}
int32_t main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;++i){
            gi[i].clear();
            go[i].clear();
            w[i].clear();
            cnt[i]=0;
            x[i]=0;
        }
        forn(i,m){
            int a,b;
            a=i+1;b=i+2;
            cin>>a>>b;
            go[a].pb(b);
            gi[b].pb(a);
        }
        int z=0;
        for(int i=1;i<=n;++i){
            for(int p:gi[i])
                for(int y:go[i]){
                    w[i].pb(z);
                    w[p].pb(z);
                    w[y].pb(z);
                    cnt[i]++;
                    cnt[p]++;
                    cnt[y]++;
                    c[z][0]=i;
                    c[z][1]=p;
                    c[z][2]=y;
                    z++;
                }
        }
        int u=0;
        s.clear();
        for(int i=1;i<=n;++i){
            s.insert({cnt[i],i});
        }
        vector<int> va;
        while(1){
            int v=s.begin()->s;
            if(s.begin()->f){
                add(v);
                u++;
                va.pb(v);
                if(u*7>n*4){
                    u--;
                    int oi=rng()%(sz(va));
                    swap(va[oi],va[sz(va)-1]);
                    int o=va.back();
                    va.pop_back();
                    del(o);
                }
            }else{
                break;
            } 
        }
        cout<<u<<'\n';
        for(int i=1;i<=n;++i){
            if(x[i]){
                cout<<i<<' ';
            }
        }
        cout<<'\n';
    }
 
    return 0;
}