#include<stdio.h>
#define MAXN 110000
#define jsb 1000000007
using namespace std;
typedef long long LL;
int n,x;
LL a[MAXN];
LL sum=0;
int Pow(int a,LL b)
{
    int c=1;
    for(;b;b>>=1,a=a*1ll*a%jsb)
    if(b&1)c=c*1ll*a%jsb;
    return c;
}
#define minS(a,b) ((a)<(b)?(a):(b))
int main()
{
    scanf("%d%d",&n,&x);
    for(int i=1;i<=n;i++)
    {
            scanf("%I64d",&a[i]);
            sum+=a[i]*1ll;
            }
    for(int i=1;i<=n;i++)a[i]=sum-a[i];
    for(int i=n;i>=1;i--)
    {
            int j=i;
            while(j!=1&&a[j-1]==a[i])j--;
            if((i-j+1)%x==0)
            {
                            for(int k=j;k<=j+((i-j+1)/x)-1;k++)
                            a[k]=a[i]+1ll;
                            i=j+((i-j+1)/x);
                            }
            else
            {
                printf("%d\n",Pow(x,minS(sum,a[i])));
                return 0;
                }
                }
    return 0;
}