#include<cstdio>
#include<algorithm>
using namespace std;
#define N 100010
int n,m,a[N],he[N],ne[N*2],ad[N*2],q[N];bool f1[N],f2[N];
void addE(int x,int y)
{
    static int t=1;
    ++t,ne[t]=he[x],he[x]=t,ad[t]=y,
    ++t,ne[t]=he[y],he[y]=t,ad[t]=x;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",a+i);
    for(int i=1,x,y;i<=m;i++)scanf("%d%d",&x,&y),addE(x,y);
    int L=1,R=0;
    for(int i=1;i<=n;i++)
        if(a[i]==1)f1[i]=1,q[++R]=i;
    while(L<=R)
    {
        int x=q[L++];
        for(int p=he[x];p;p=ne[p])if(~p&1)
            if(!f1[ad[p]]&&a[ad[p]]!=1)f1[ad[p]]=1,q[++R]=ad[p];
    }
    L=1,R=0;
    for(int i=1;i<=n;i++)
        if(a[i]==2)f2[i]=1,q[++R]=i;
    while(L<=R)
    {
        int x=q[L++];
        for(int p=he[x];p;p=ne[p])if(p&1)
            if(!f2[ad[p]])
            {
                f2[ad[p]]=1;
                if(a[ad[p]]!=1)q[++R]=ad[p];
            }
    }
    for(int i=1;i<=n;i++)printf("%d\n",f1[i]&&f2[i]);
    return 0;
}