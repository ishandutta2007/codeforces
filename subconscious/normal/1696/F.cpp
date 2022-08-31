#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define trav(a,x) for(auto&a:x)
#define all(x) begin(x),end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair
#define x0 fuckhel
#define y0 fuckoscar
#define x1 fucksub
#define y1 fuckzzy
#define st first
#define nd second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef vector<int> vi;
const int N=105,mod=1e9+7;
int T,n;
bool eq[N][N][N];
char s[N];
vi level[N];int top;
int is[N],f[N],dis[N][N];
vi g[N];
void dfs(int x,int fa,int tp){
    if(x==tp)dis[x][tp]=0;else dis[x][tp]=dis[fa][tp]+1;
    for(int v:g[x])if(v!=fa)dfs(v,x,tp);
}
bool check(int bg){
    rep(i,n)f[i]=0;
    for(int x:level[bg])f[x]=1;
    int now=bg;
    for(;;){
        int cnt=0;vi nlevel;
        for(int i=2;i<=n;++i)if(f[i]==0){
            ++cnt;vi tmp;
            for(int x:level[now])if(eq[f[x]][i][x]){
                tmp.pb(x);
                nlevel.pb(is[i]);
            }
            if(tmp.size()>1)return 0;
            else if(tmp.size()==1)f[i]=tmp[0];
        }
        if(cnt==0)break;
        if(nlevel.size()==0)return 0;
        rep(i,(int)nlevel.size()-1)if(nlevel[i-1]!=nlevel[i])return 0;
        int nxt=nlevel[0];
        if(level[nxt].size()!=nlevel.size())return 0;
        now=nxt;
    }
    rep(i,n)rep(j,n)if(i==j)dis[i][j]=0;
    else if(f[i]==j||f[j]==i)dis[i][j]=1;
    else dis[i][j]=mod;
    rep(i,n)g[i].clear();
    for(int i=2;i<=n;++i)g[i].pb(f[i]),g[f[i]].pb(i);
    rep(i,n)dfs(i,0,i);
    rep(k,n)rep(i,n)rep(j,n)if(eq[i][j][k]!=(dis[i][k]==dis[j][k]))return 0;
    return 1;
}
int main(){
    for(scanf("%d",&T);T--;){
        scanf("%d",&n);
        rep(i,n){
            rep(k,n)eq[i][i][k]=1;
            for(int j=i+1;j<=n;++j){
                scanf("%s",s+1);
                rep(k,n)eq[i][j][k]=eq[j][i][k]=(s[k]=='1');
            }
        }
        top=0;
        for(int i=2;i<=n;++i){
            bool flag=0;
            rep(j,top)if(eq[level[j].back()][i][1]){
                level[j].pb(i);flag=1;is[i]=j;break;
            }
            if(!flag){
                level[top+1].clear();++top;
                level[top].pb(i),is[i]=top;
            }
        }
        // level[top+1].pb(1);is[1]=top+1;
        bool flag=0;
        rep(now,top){
            if(check(now)){
                puts("Yes");
                for(int i=2;i<=n;++i)printf("%d %d\n",i,f[i]);
                flag=1;break;
            }
        }
        if(!flag){puts("No");}
    }
    return 0;
}
/*
5
5
2 1 5 3 4
*/