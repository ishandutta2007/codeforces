#include<stdio.h>
#define MAXN 110000
using namespace std;
int n;int w[MAXN];
int sum[MAXN];
int l,r,ql,qr;
int main()
{
    scanf("%d",&n);
    scanf("%d%d%d%d",&l,&r,&ql,&qr);
    for(int i=1;i<=n;i++)
    {
            scanf("%d",&w[i]);
            sum[i]=sum[i-1]+w[i];
            }
    int ans=2100000000;
    for(int j=0;j<=n;j++)
    {
            int reu=0;
            reu+=sum[j]*l+(sum[n]-sum[j])*r;
            if(n-j>j)
            {
                     reu+=(n-2*j-1)*qr;
                     }
            else if(n-j!=j)reu+=(j-(n-j)-1)*ql;
            if(reu<ans)ans=reu;
            }
    printf("%d\n",ans);
    return 0;
}