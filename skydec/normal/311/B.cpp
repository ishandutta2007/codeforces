#include<stdio.h>
#include<cstring>
#include<algorithm>
#define MAXN (110000)
using namespace std;
typedef long long LL;
LL n,m,p;
LL d[MAXN];
LL h[MAXN];
LL fz[MAXN];
LL socute[MAXN];
LL sum[MAXN];
LL q[MAXN];
LL up(LL j,LL k){return fz[k]-fz[j];}
LL down(LL j,LL k){return k-j;}
int main()
{
    scanf("%I64d%I64d%I64d",&n,&m,&p);
    for(LL i=2;i<=n;i++){scanf("%I64d",&d[i]);d[i]+=d[i-1];}
    for(LL i=1;i<=m;i++)
    {
            LL a,t;scanf("%I64d%I64d",&a,&t);
            h[i]=t-d[a];
            }
    sort(h+1,h+1+m);
    for(LL i=1;i<=m;i++)sum[i]=sum[i-1]+h[i];
    for(int i=1;i<=m;i++)fz[i]=(LL)1e16;
    fz[0]=0;LL ans=(LL)1e16;
    for(LL mod=1;mod<=p;mod++)
    {
            //prLLf("%d\n",ans);
            for(LL i=1;i<=m;i++)fz[i]+=sum[i];
            LL tail=1;LL top=1;
            q[1]=0;
            for(LL i=1;i<=m;i++)
            {
                    while((top!=tail)&&(up(q[top],q[top+1])<down(q[top],q[top+1])*h[i]))top++;
                    socute[i]=fz[q[top]]+(i-q[top])*h[i]-sum[i];
                    while((top!=tail)&&(up(q[tail-1],q[tail])*down(q[tail],i)>down(q[tail-1],q[tail])*up(q[tail],i)))tail--;
                    q[++tail]=i;
                    }
            for(LL i=1;i<=m;i++)fz[i]=socute[i];
            if(fz[m]<ans)ans=fz[m];
            }
    printf("%I64d\n",ans);
    return 0;
}