#include<stdio.h>
#include<cstring>
#include<algorithm>
#include<map>
#define MAXN 1010000
using namespace std;
int a[MAXN];
int tmp[MAXN];
int n;map<int,int>ls;
int ans[MAXN];int ys[MAXN];
int res=0;int cho;
int ti[MAXN],cnt[MAXN];
int tq[MAXN];
int before[MAXN],next[MAXN];
int q[MAXN];
int wz[MAXN];
int tt[MAXN];int t2[MAXN];
void relax(int x)
{
     if(ti[x]!=cho)
     {
                   ti[x]=cho;
                   cnt[x]=0;
                   }
}
void init()
{
     for(int i=1;i<=n;i++)
     {
             next[wz[a[i]]]=i;
             before[i]=wz[a[i]];
             wz[a[i]]=i;
             }
}
int ask(int x)
{
    int reu=0;
    for(;x;x-=x&-x)
    {
                   relax(x);
                   if(cnt[x]>reu)reu=cnt[x];
                   }
    return reu;
}
void add(int x,int v)
{
     for(;x<=n;x+=x&-x)
     {
                       relax(x);
                       if(v>cnt[x])cnt[x]=v;
                       }
}
int main()
{
    scanf("%d",&n);int tot=0;
    for(int i=1;i<=n;i++){scanf("%d",&a[i]);tmp[i]=a[i];}sort(tmp+1,tmp+1+n);
    for(int i=1;i<=n;i++)if(i==1||tmp[i]!=tmp[i-1]){ls[tmp[i]]=++tot;ys[tot]=tmp[i];}
    for(int i=1;i<=n;i++)a[i]=ls[a[i]];init();int now=1;cho=0;
    while(1)
    {
            bool find=0;
            cho++;int biua,biub;
            for(;now<=n;now++)
            {
             if(tq[now]!=cho){tq[now]=cho;q[now]=0;}
             if(q[now])add(q[now],now);
             if(t2[a[now]]!=cho)t2[a[now]]=cho,tt[a[now]]=0;
             if(tt[a[now]]>=3)
             {
                              biua=biub=a[now];
                              find=1;
                              now++;
                              break;
                              }
             tt[a[now]]++;
             if(before[now])
             {
                              int s=ask(before[now]-1);
                              if(s>before[now])
                              {
                                               find=1;
                                               biua=a[now];
                                               biub=a[s];
                                               now++;
                                               break;
                                               }
                                               }
             q[next[now]]=now;tq[next[now]]=cho;
             }
            if(!find)break;
            ans[res*4+1]=ans[res*4+3]=biub;
            ans[res*4+2]=ans[res*4+4]=biua;
            res++;
            }
    printf("%d\n",res*4);for(int i=1;i<=res*4;i++)printf("%d ",ys[ans[i]]);
    return 0;
}