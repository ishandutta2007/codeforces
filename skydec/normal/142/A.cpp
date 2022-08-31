#include<stdio.h>
using namespace std;
int n;
long long maxans,minans;
inline void bmax(long long x){if(x>maxans)maxans=x;}
inline void bmin(long long x){if(x<minans)minans=x;}
int check(int a,int b,int c)
{
    bmax((a+1)*1ll*(b+2)*(c+2));
    bmax((a+2)*1ll*(b+1)*(c+2));
    bmax((a+2)*1ll*(b+2)*(c+1));
    
    bmin((a+1)*1ll*(b+2)*(c+2));
    bmin((a+2)*1ll*(b+1)*(c+2));
    bmin((a+2)*1ll*(b+2)*(c+1));
}
int main()
{
    minans=(long long)1e16;
    scanf("%d",&n);
    for(int i=1;i*i<=n;i++)
    if(n%i==0)
    for(int j=1;j<=i;j++)
    if((n/i)%j==0)
    check(i,j,n/(i*j));
    printf("%I64d %I64d\n",minans-n,maxans-n);
    return 0;
}