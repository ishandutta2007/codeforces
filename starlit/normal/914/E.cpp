#include<bits/stdc++.h>
#define N 200005
#define L 20
using namespace std;
char val[N];
bool vis[N];
int n,now,f[N],dp[N],lst[N],to[N<<1],hd[N<<1],lk[N],cnt,siz[N];
long long tms[1<<20][2],vv[N][L],inc[N][L],ans[N];
void ini(int x)
{
    siz[x]=1;
    for(int s,i=lk[x];i;i=hd[i])
    if(!siz[s=to[i]])
    ini(s),siz[x]+=siz[s];
}
int getr(int x,int y,int nn)
{
    for(int s,i=lk[x];i;i=hd[i])
    if((!vis[s=to[i]])&&s^y&&siz[s]>nn)
    return getr(s,x,nn);
    return x;
}
void dfs(int x,int y,int fr)
{
    siz[x]=1;
    vv[x][dp[fr]]=vv[y][dp[fr]]^(1<<val[x]);
    //cout<<"dfs "<<x<<"("<<vv[x][dp[fr]]<<endl;
    tms[vv[x][dp[fr]]][0]++;
    tms[vv[x][dp[fr]-1]][1]++;
    for(int s,i=lk[x];i;i=hd[i])
    if((!vis[s=to[i]])&&s^y)
    dfs(s,x,fr),siz[x]+=siz[s];
}
void cal(int x,int y,int fr)
{
    long long test=inc[x][dp[fr]],t2=inc[x][dp[fr]-1];
    inc[x][dp[fr]]+=tms[vv[x][dp[fr]]^(1<<val[fr])][0];
    inc[x][dp[fr]-1]-=tms[vv[x][dp[fr]-1]^(1<<val[f[fr]])][1];
    //cout<<"cal "<<x<<endl;
    //cout<<inc[x][dp[fr]]-test<<"/"<<inc[x][dp[fr]-1]-t2<<endl;
    for(int i=0;i<L;i++)
    inc[x][dp[fr]]+=tms[vv[x][dp[fr]]^(1<<val[fr])^(1<<i)][0],
    inc[x][dp[fr]-1]-=tms[vv[x][dp[fr]-1]^(1<<val[f[fr]])^(1<<i)][1];
    for(int s,i=lk[x];i;i=hd[i])
    if((!vis[s=to[i]])&&s^y)
    cal(s,x,fr);
}
void clr(int x,int y,int fr)
{
    tms[vv[x][dp[fr]]][0]=0;
    tms[vv[x][dp[fr]-1]][1]=0;
    for(int s,i=lk[x];i;i=hd[i])
    if((!vis[s=to[i]])&&s^y)
    clr(s,x,fr);
}
long long upd(int x,int y,int fr)
{
    for(int s,i=lk[x];i;i=hd[i])
    if(dp[s=to[i]]>dp[fr]&&s^y)
    inc[x][dp[fr]]+=upd(s,x,fr);
    if(x^fr)
    ans[x]+=inc[x][dp[fr]];
    else ans[x]+=(inc[x][dp[fr]]>>1)+1;
    return inc[x][dp[fr]];
}
void build(int x,int ff)
{
    vis[x=getr(x,x,siz[x]>>1)]=1;
    dp[x]=dp[f[x]=ff]+1;
    //cout<<"Build "<<x<<"("<<dp[x]<<")"<<endl;
    dfs(x,x,x);
    cal(x,x,x);
    clr(x,x,x);
    for(int i=lk[x];i;i=hd[i])
    if(!vis[to[i]])build(to[i],x);
    upd(x,x,x);
}
inline void add(int u,int v)
{to[++cnt]=v,hd[cnt]=lk[u],lk[u]=cnt;}
int u,v;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++)
    scanf("%d%d",&u,&v),
    add(u,v),add(v,u);
    scanf("%s",val+1);
    for(int i=1;i<=n;i++)
    val[i]-='a';
    ini(1),build(1,0);
    for(int i=1;i<=n;i++)
    printf("%lld ",ans[i]);
}
/*
5
1 2
1 3
1 4
1 5
fffff
*/