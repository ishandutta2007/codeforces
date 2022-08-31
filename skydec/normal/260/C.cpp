#include<stdio.h>
#define MAXN 290000
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;
long long a[MAXN];
long st[MAXN][18];
long n,x;
long tw[18];
long find(long l,long r)
{
     if(l>r)return 2100000000;
     long tt=r-l+1;
     long reu=2100000000;
     for(long i=17;i>=0;i--)
     if((tt&tw[i])>0)
     {
                     reu=min(reu,st[l][i]);
                     tt-=tw[i];
                     l+=tw[i];
                     }
     return reu;
}
int main()
{
    scanf("%ld%ld",&n,&x);
    tw[0]=1;for(long i=1;i<=17;i++)tw[i]=2*tw[i-1];
    for(long i=1;i<=n;i++)
    {
             scanf("%ld",&a[i]);
             st[i][0]=a[i];
             }
    for(long j=1;j<=17;j++)
    for(long i=1;i<=n;i++)
    st[i][j]=min(st[i][j-1],st[i+tw[j-1]][j-1]);
    for(long i=1;i<=n;i++)
    {
             long j=i+1;
             if(j>n)j=1;
             bool flag=true;
             if(x>=j)
             {
                     long ts=a[i]-1;
                     if(i==n)ts--;
                     if(find(1,j-1)<ts+1)flag=false;
                     if(find(j,x)<ts+2)flag=false;
                     if(find(x+1,n)<ts+1)flag=false;
                     }
             else
             {
                     long ts=a[i];
                     if(x==i)ts--;
                     if(find(1,x)<ts+1)flag=false;
                     if(find(j,n)<ts+1)flag=false;
                     if(find(x+1,i)<ts)flag=false;
                     }
             if(flag)
             {
                     if(x>=j)
                     {
                             long ts=a[i]-1;
                             if(i==n&&x==n)ts--;
                             a[i]+=1ll*n-1ll*j+1+1ll*ts*1ll*n+x;
                             for(long iq=1;iq<=j-1;iq++)
                             printf("%I64d ",a[iq]-(ts+1));
                             for(long iq=j;iq<=x;iq++)
                             printf("%I64d ",a[iq]-(ts+2));
                             for(long iq=x+1;iq<=n;iq++)
                             printf("%I64d ",a[iq]-(ts+1));
                             }
                     else
                     {  
                             long ts=a[i];
                             if(x==i)ts--;
                             a[i]+=1ll*n-1ll*j+1+1ll*ts*1ll*n+x;
                             for(long iq=1;iq<=x;iq++)
                             printf("%I64d ",a[iq]-(ts+1));
                             for(long iq=x+1;iq<=i;iq++)
                             printf("%I64d ",a[iq]-(ts));
                             for(long iq=i+1;iq<=n;iq++)
                             printf("%I64d ",a[iq]-(ts+1));
                             }
                     return 0;
                     }
                     }
    return 0;
}