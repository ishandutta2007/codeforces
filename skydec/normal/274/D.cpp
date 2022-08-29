#include<stdio.h>
#include<cstring>
#include<algorithm>
#include<vector>
#define pb push_back
#define MAXN 210000
using namespace std;
vector<int>data[MAXN];
int n,m;int tot=0;
int head[MAXN],next[MAXN*3],p[MAXN*3];
int now;
int tmp[MAXN];int d[MAXN];int ans[MAXN];int tt=0;
bool cmp(int a,int b){return data[now][a]<data[now][b];}
void line(int a,int b)
{
     tot++;p[tot]=b;next[tot]=head[a];head[a]=tot;
     d[b]++;
     //printf("_%d %d\n",a,b);
}
int tto;
int main()
{
    scanf("%d%d",&n,&m);tto=m;
    for(int i=1;i<=n;i++)
    {
            data[i].pb(0);
            for(int j=1;j<=m;j++)
            {
                    int v;scanf("%d",&v);
                    data[i].pb(v);
                    }
                    }
    for(int i=1;i<=n;i++)
    {
            now=i;tmp[0]=0;
            for(int j=1;j<=m;j++)
            if(data[i][j]!=-1)tmp[++tmp[0]]=j;
            sort(tmp+1,tmp+1+tmp[0],cmp);int xg1,xg2;
            xg1=xg2=0;
            for(int j=1;j<=tmp[0];j++)
            {
                    int k=j;
                    while(k<tmp[0]&&data[i][tmp[k+1]]==data[i][tmp[j]])
                    k++;
                    xg2=++tto;
                    if(xg1)for(int s=j;s<=k;s++)line(xg1,tmp[s]);
                    for(int s=j;s<=k;s++)line(tmp[s],xg2);
                    xg1=xg2;
                    j=k;
                    }
                    }
    tmp[0]=0;
    for(int i=1;i<=tto;i++)if(!d[i])tmp[++tmp[0]]=i;
    for(int i=1;i<=tmp[0];i++)
    {
            int x=tmp[i];if(x<=m)ans[++tt]=x;
            //printf("%d\n",x);
            for(int u=head[x];u;u=next[u])
            {
                    d[p[u]]--;
                    if(d[p[u]]==0)tmp[++tmp[0]]=p[u];
                    }
                    }
    if(tt!=m)
    {
             printf("-1\n");
             }
    else for(int i=1;i<=m;i++)printf("%d ",ans[i]);
    return 0;
}