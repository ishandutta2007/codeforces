#include<stdio.h>
using namespace std;
long finish[50005]={0};long fpint[6]={0};
long n,m;long t[50005][6];
long max(long a,long b){if(a>b)return a;else return b;}
int main()
{
    scanf("%ld%ld",&m,&n);
    for(long i=1;i<=m;i++)
    for(long j=1;j<=n;j++)
    scanf("%ld",&t[i][j]);
    for(long i=1;i<=m;i++)
    for(long j=1;j<=n;j++)
    {
             fpint[j]=max(finish[i],fpint[j])+t[i][j];
             finish[i]=fpint[j];
             }
    for(long i=1;i<=m-1;i++)printf("%ld ",finish[i]);printf("%ld",finish[m]);
    //for(;;);
    return 0;
}