#include <bits/stdc++.h>
using std::cerr;using std::cin;using std::cout;using std::abs;using std::min;using std::max;using std::swap;using std::map;using std::unordered_map;using std::unordered_set;using std::bitset;using std::pair;using std::set;using std::string;using std::vector;using std::sort;using ll=long long;using uint=unsigned int;using pii=pair<int,int>;using pll=pair<ll,ll>;using ull = unsigned long long;using ld=long double;template<typename T>void _(const char*s,T h){cerr<<s<<" = "<<h<<"\n";}template<typename T,typename...Ts>void _(const char*s,T h,Ts...t){int b=0;while(((b+=*s=='(')-=*s==')')!=0||*s!=',')cerr<<*s++;cerr<<" = "<<h<<",";_(s+1,t...);}// break continue pop_back 998244353
#define int ll
#define pii pll
#define f first
#define s second
#define pb emplace_back
#define forn(i,n) for(int i=0;i<(n);++i)
#define sqr(x) ((x)*(x))
#ifdef LOCAL
#define dbg(...) _(#__VA_ARGS__,__VA_ARGS__)
#else
//#define dbg(...) _(#__VA_ARGS__,__VA_ARGS__)
 
#define dbg(...)
#endif
struct init{init(){
#ifdef LOCAL
        freopen("input.txt","r",stdin);
#endif // LOCAL
        cin.tie(0);std::iostream::sync_with_stdio(0);cout<<std::fixed<<std::setprecision(10);cerr<<std::fixed<<std::setprecision(5);}}init;template<typename T,typename U>void upx(T&x,U y){if(x<y)x=y;}template<typename T,typename U>void upn(T&x,U y){if(x>y)x=y;}
 
const int N=5e5+5;
vector<int> g[N];
int u[N];
int vis=0;
void dfs(int v){
    u[v]=1;
    dbg(v);
    vis++;
    for(int to:g[v]){
        if(!u[to])
            dfs(to);
    }
}
int n,m;
ll fl;
void output(const vector<int>&ans){
    if(ans.size()==n||ans.size()==0){
        cout<<"No\n";
    }else{
        cout<<"Yes\n";
        cout<<ans.size()<<'\n';
        for(int i:ans)cout<<i<<' ';
        cout<<'\n';
    }
}
vector<int> way;
bool fnd(int v){
    u[v]=2;
    way.pb(v);
    vector<ll> qqq;
    qqq.push_back(v);
    vector<ll> pr(n + 1, -1);
    ll lst = 0;
    ll mem = -1;
    while(qqq.size() > lst){
        ll vv = qqq[lst++];
        for (auto i : g[vv]){
            if (u[i] != 2){
                qqq.push_back(i);
                if (mem == -1 && g[i].size() % 3 == 1)
                    mem = i;
                u[i] = 2;
                pr[i] = vv;
            }
        }
    }
    ll gd = (mem != -1);
    while(mem != -1){
        way.push_back(mem);
        mem = pr[mem];
    }
    return gd;
}
int rem[N];
void doans(vector<int>&ans){
    for(int i=1;i<=n;++i)
        if(!rem[i])
            ans.pb(i);
}
vector<int> g2[N];
int dt[N];
int col[N];
int up[N];
int curcol;
int solved;
void dfs2(int v,int fr, int dep=0){
    col[v]=curcol;
    dt[v]=dep;
    up[v]=fr;
    int zhopa=-1;
    for(int to:g2[v]){
        if(!col[to]){
            //dfs2(to, v, dep+1);
        }else if(fr!=to){
            if(zhopa == -1 || dt[to]>dt[zhopa]){
                zhopa=to;
            }
        }
    }
    dbg(v,zhopa);
    if(!solved && zhopa != -1){
        solved=1;
        int curv=v;
        while(curv!=zhopa){
            rem[curv]=1;
            curv=up[curv];
        }
        rem[zhopa] = 1;
        return;
    }
 
    for(int to:g2[v]){
        if(!col[to]){
            dfs2(to, v, dep+1);
        }
    }
 
 
}
vector<int> idet[N];
 
int qwe[N];
bool ebat(int v,int tar,int co){
 
 
    qwe[v] = 1;
    vector<ll> qq;
    vector<ll> prr(n+1, -1);
    ll lst = 0;
    qq.push_back(v);
    while (lst < qq.size()){
        ll vv = qq[lst++];
        for (auto i : g[vv]){
            if (col[i] == co && !qwe[i]){
                qq.push_back(i);
                prr[i] = vv;
                qwe[i] = 1;
            }
        }
    }
    if (prr[tar] != -1){
        ll nw = tar;
        while (prr[nw] != -1){
            way.push_back(nw);
            nw = prr[nw];
        }
        way.push_back(nw);
        return 1;
    }
    return 0;
 
 
}
 
ll us111[N];
vector<int> v2;
 
int32_t main(){
 
    int te;
    cin>>te;
    while(te--){
        vis=0;
        dbg("====");
        cin>>n>>m;
        way.clear();
        for(int i=1;i<=n;++i){
            rem[i]=0;
            u[i]=0;
            g[i].clear();
            g2[i].clear();
            idet[i].clear();
            qwe[i]=0;
            col[i]=0;
            us111[i] = 0;
        }
        forn(i,m){
            int a,b;
            cin>>a>>b;
            g[a].pb(b);
            g[b].pb(a);
        }
        dfs(1);
        if(vis!=n){
            dbg("component");
            vector<int> ans;
            for(int i=1;i<=n;++i)if(u[i])ans.pb(i);
            output(ans);
            continue;
        }
        solved=0;
        for(int i=1;!solved&&i<=n;++i){
            if(g[i].size()%3==0){
                dbg("est nolik");
                vector<int> ans;
                for(int j=1;j<=n;++j)if(i!=j)ans.pb(j);
                output(ans);
                solved=1;
            }
        }
        if(solved)continue;
        int a=0,b=0;
        for(int i=1;i<=n;++i){
            if(g[i].size()%3==1){
                if(a)b=i;
                else a=i;
            }
        }
        if(a&&b){
            dbg("put 1");
            way.clear();
            fnd(a);
            for(int i:way)
            {
                rem[i]=1;
                dbg(i);
            }
            vector<int> ans;
            doans(ans);
            output(ans);
            dbg(a, b);
            continue;
        }
        for(int i=1;i<=n;++i){
            for(int to:g[i]){
                if(g[i].size()%3==2&&g[to].size()%3==2){
                    g2[i].pb(to);
                    dbg(i,to);
                }
            }
        }
        curcol=0;
        for(int i=1;!solved&&i<=n;++i){
            if(g[i].size()%3==2&&!col[i]){
                curcol++;
                dfs2(i, i);
                if(solved){
                    dbg("cyc 2");
                    vector<int> ans;
                    doans(ans);
                    output(ans);
                }
            }
        }
        if(solved)continue;
        for(int to:g[a]){
            idet[col[to]].pb(to);
        }
        for(int i=1;i<=n;++i)dbg(i,col[i]);
        v2.clear();
        for(int i=1;!solved&&i<=curcol;++i){
            if(idet[i].size()%3==2){
                v2.pb(i);
            }
        }
 
        if(v2.size()>=2){
            dbg("sraka");
 
            int x=v2[0];
            int y=v2[1];
            {
                way.clear();
                for(int i=1;i<=n;++i)qwe[i]=0;
                int h1=idet[x][0];
                int h2=idet[x][1];
                ebat(h1,h2,x);
                dbg(h1,h2);
                for (int i = 0; i < idet[x].size(); i++){
                    ll v = idet[x][i];
                    us111[v] = 1;
                }
                ll koll = 0;
                for(int i:way){
                    rem[i]=1;
                    dbg(i);
                    koll+=us111[i];
                    if(koll >= 2) break;
                }
            }
            {
                way.clear();
                for(int i=1;i<=n;++i)qwe[i]=0;
                int h1=idet[y][0];
                int h2=idet[y][1];
                int ewq=ebat(h1,h2,y);
                dbg(ewq);
                dbg(h1,h2);
                for (int i = 0; i < idet[y].size(); i++){
                    ll v = idet[y][i];
                    us111[v] = 1;
                }
                ll koll = 0;
                for(int i:way){
                    rem[i]=1;
                    dbg(i);
                    koll += us111[i];
                    if(koll >= 2) break;
                }
            }
            rem[a]=1;
            dbg(a);
            vector<int> ans;
            doans(ans);
            output(ans);
            continue;
        }
        cout<<"No\n";
    }
 
 
 
    return 0;
}