#include<stdio.h>
#include<cstring>
#define MAXN 500
using namespace std;
struct chuan
{
       int tt[27];
       int cc;
       char str[MAXN];
       void make()
       {
            scanf("%s",str+1);
            for(int i=1;i<=strlen(str+1);i++)
            tt[str[i]-'a'+1]++;
            }
}data[MAXN],big;
int n;
int s,t;
int flow[MAXN][MAXN];
int cost[MAXN][MAXN];
int head[MAXN];int next[MAXN*MAXN*2],p[MAXN*MAXN*2];
int tot=1;
void line(int a,int b,int fl,int co)
{
     tot++;p[tot]=b;next[tot]=head[a];head[a]=tot;
     flow[a][b]=fl;cost[a][b]=co;
}
int pre[MAXN],q[MAXN*MAXN],dis[MAXN];bool inq[MAXN];
int spfa()
{
    memset(pre,-1,sizeof pre);
    memset(dis,63,sizeof dis);
    memset(inq,false,sizeof inq);
    q[q[0]=1]=s;dis[s]=0;inq[s]=true;
    for(int i=1;i<=q[0];i++)
    {
            int x=q[i];
            for(int u=head[x];u;u=next[u])
            if(flow[x][p[u]])
            if(dis[x]+cost[x][p[u]]<dis[p[u]])
            {
                                              dis[p[u]]=dis[x]+cost[x][p[u]];
                                              pre[p[u]]=x;
                                              if(!inq[p[u]])
                                              {
                                                            inq[p[u]]=true;
                                                            q[++q[0]]=p[u];
                                                            }
                                                            }
            inq[x]=false;
                                                            }
    return pre[t];
}
int main()
{
    big.make();
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
            data[i].make();
            scanf("%d",&data[i].cc);
            }
    s=0;t=n+26+1;
    for(int i=1;i<=26;i++)
    if(big.tt[i])
    {
                 line(n+i,t,big.tt[i],0);
                 line(t,n+i,0,0);
                 }
    for(int i=1;i<=n;i++)
    if(data[i].cc)
    {
            line(s,i,data[i].cc,i);
            line(i,s,0,-i);
            for(int j=1;j<=26;j++)
            if(data[i].tt[j])
            {
                             line(i,n+j,data[i].tt[j],0);
                             line(n+j,i,0,0);
                             }
            }
    int ans=0;int fff=0;
    while(spfa()!=-1)
    {
                     int tp=t;int mins=2100000000;
                     int cos=0;
                     for(;tp;tp=pre[tp])
                     {
                                        if(flow[pre[tp]][tp]<mins)mins=flow[pre[tp]][tp];
                                        cos+=cost[pre[tp]][tp];
                                        }
                     ans+=cos*mins;fff+=mins;
                     for(tp=t;tp;tp=pre[tp])
                     {
                                            flow[pre[tp]][tp]-=mins;
                                            flow[tp][pre[tp]]+=mins;
                                            }
                                            }
    if(fff!=strlen(big.str+1))ans=-1;
    printf("%d\n",ans);
    return 0;
}