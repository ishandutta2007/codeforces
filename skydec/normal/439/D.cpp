#include<cstdio>
#include<cstdlib>
#include<cstring>
#define MAXN 110000
using namespace std;
typedef long long LL;
int a[MAXN],b[MAXN];
int n,m;
void read(int &x)
{
     x=0;char p=getchar();
     while(!(p<='9'&&p>='0'))p=getchar();
     while(p<='9'&&p>='0')x*=10,x+=p-48,p=getchar();
}
LL check(int u)
{
             LL reu=0;
             for(int i=1;i<=n;i++)
             if(a[i]<u)reu+=(LL)u-a[i];
             for(int i=1;i<=m;i++)
             if(b[i]>u)reu+=(LL)b[i]-u;
             return reu;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)read(a[i]);
    for(int i=1;i<=m;i++)read(b[i]);
    int l,r;
    l=0;r=1000000000;
    for(int i=1;i<=100;i++)
    {
            int l0=l+(r-l)/3;
            int r0=r-(r-l)/3;
            if(check(l0)<=check(r0))r=r0;else l=l0;
            }
    LL ans=(LL)1e16;
    for(int i=l;i<=r;i++)
    {
            LL p=check(i);
            if(p<ans)ans=p;
            }
    printf("%I64d\n",ans);
    return 0;
}