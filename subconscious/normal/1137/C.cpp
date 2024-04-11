#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define x0 fxaa
#define y0 fxbb
#define x1 fxcc
#define y1 fxdd
#define st first
#define nd second
using namespace std;
using ll=long long;
using ld=long double;
constexpr int N=1e5+5,mod=1e9+7;
constexpr ld eps=1e-9,inf=1e50;
int n,m,d;
char s[N][55];
int b[N],v[N],f[N],tot;
int dfn[N],low[N],sta[N],beg[N],top,cnt,scc;
vector<int>q[N];
bool in[N];
void tj(int x){
    dfn[x]=low[x]=++cnt;
    sta[++top]=x,in[x]=1;
    for(int i=b[x];i;i=f[i])
        if(!dfn[v[i]]){
            tj(v[i]);
            low[x]=min(low[x],low[v[i]]);
        }else if(in[v[i]])
            low[x]=min(low[x],dfn[v[i]]);
    if(low[x]==dfn[x]){
        ++scc;
        do{
            int c=sta[top];
            in[c]=0;beg[c]=scc;
            q[scc].emplace_back(c);
        }while(sta[top--]!=x);
    }
}
int ans[N][55];
bool ck[N][55],is[N];
vector<pair<int,int>>vc;
int cm,tmax;
void dfs(int pos,int dy){
    //printf("%d %d\n",pos,dy);
    ck[pos][dy]=1;
    is[pos]|=(s[pos][dy]=='1');
    vc.emplace_back(make_pair(pos,dy));
    tmax=max(tmax,ans[pos][dy]);
    for(int i=b[pos];i;i=f[i])if(beg[v[i]]==beg[pos]&&!ck[v[i]][dy%d+1])
        dfs(v[i],dy%d+1);
}
int main(){
    scanf("%d%d%d",&n,&m,&d);
    rep(i,m){
        int x,y;
        scanf("%d%d",&x,&y);
        v[++tot]=y,f[tot]=b[x],b[x]=tot;
    }
    rep(i,n)scanf("%s",s[i]+1);
    rep(i,n)rep(j,d)ans[i][j]=-mod;
    ans[1][1]=0;
    tj(1);

    for(int ns=scc;ns;--ns){
        for(int pos:q[ns])rep(j,d)if(!ck[pos][j]){
            vc.clear();tmax=-mod;
            for(int p2:q[ns])is[p2]=0;
                //puts("NEW:");
            dfs(pos,j);
            cm=0;for(int p2:q[ns])cm+=is[p2];
            for(auto k:vc){
                ans[k.st][k.nd]=cm+tmax;
                for(int i=b[k.st];i;i=f[i])
                if(beg[v[i]]!=beg[k.st])
                    ans[v[i]][k.nd%d+1]=max(ans[v[i]][k.nd%d+1],ans[k.st][k.nd]);
            }
        }
    }
    int ret=0;
    rep(i,n)rep(j,d)ret=max(ret,ans[i][j]);
    printf("%d\n",ret);
    return 0;
}