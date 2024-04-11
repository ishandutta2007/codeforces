#include<stdio.h>
using namespace std;
bool flag[1000]={false};
long n,k;
long a[35];
int main()
{
    scanf("%ld%ld",&n,&k);
    for(long i=1;i<=k;i++)
    {
             scanf("%ld",&a[i]);
             flag[a[i]]=true;
             }
    for(long i=1;i<=k;i++)
    {
             printf("%ld ",a[i]);
             long tot=n-1;
             for(long j=1;j<=n*k;j++)
             if(!flag[j])
             {
                         tot--;
                         flag[j]=true;
                         printf("%ld ",j);
                         if(!tot)break;
                         }
             printf("\n");
                         }
    return 0;
}