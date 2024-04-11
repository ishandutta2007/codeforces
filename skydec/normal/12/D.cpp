#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<map>
#define MAXN 500005
using namespace std;
int a[MAXN],b[MAXN],c[MAXN];
map<int,int>la,lb,lc;
int tmp[MAXN];
int n;
int cnt[MAXN];
struct jsb
{
       int x,y,z;
}data[MAXN];
bool cmp(jsb x1,jsb y1){return x1.x<y1.x;}
void add(int p,int v)
{
     for(int x=p;x<=n;x+=x&-x)
     if(v<cnt[x]||!cnt[x])cnt[x]=v;
}
int ask(int p)
{
    int reu=21000000;
    for(;p;p-=p&-p)if(cnt[p])if(cnt[p]<reu)reu=cnt[p];
    return reu;
}
int main()
{
    //freopen("ball.in","r",stdin);
    //freopen("ball.out","w",stdout);
    scanf("%d",&n);
    int tot=0;
    for(int i=1;i<=n;i++){scanf("%d",&a[i]);tmp[i]=a[i];}
    tot=0;sort(tmp+1,tmp+1+n);
    for(int i=1;i<=n;i++)
    if(i==1||tmp[i]!=tmp[i-1])
    la[tmp[i]]=++tot;
    for(int i=1;i<=n;i++)
    a[i]=n-la[a[i]]+1;
    //
    for(int i=1;i<=n;i++){scanf("%d",&b[i]);tmp[i]=b[i];}
    tot=0;sort(tmp+1,tmp+1+n);
    for(int i=1;i<=n;i++)
    if(i==1||tmp[i]!=tmp[i-1])
    lb[tmp[i]]=++tot;
    for(int i=1;i<=n;i++)
    b[i]=n-lb[b[i]]+1;
    //
    for(int i=1;i<=n;i++){scanf("%d",&c[i]);tmp[i]=c[i];}
    tot=0;sort(tmp+1,tmp+1+n);
    for(int i=1;i<=n;i++)
    if(i==1||tmp[i]!=tmp[i-1])
    lc[tmp[i]]=++tot;
    for(int i=1;i<=n;i++)
    c[i]=n-lc[c[i]]+1;
    for(int i=1;i<=n;i++)data[i]=(jsb){a[i],b[i],c[i]};
    sort(data+1,data+1+n,cmp);
    int ans=0;
    for(int i=1;i<=n;i++)
    {
            int j=i;
            while(data[j+1].x==data[i].x&&j<n)j++;
            for(int k=i;k<=j;k++)ans+=(ask(data[k].y-1)<data[k].z);
            for(int k=i;k<=j;k++)add(data[k].y,data[k].z);
            i=j;
            }
    printf("%d\n",ans);
    return 0;
}