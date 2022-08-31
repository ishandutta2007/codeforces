#include<stdio.h>
using namespace std;
int main()
{
    long a[5];
    long ans=0;
    for(long i=1;i<=4;i++)
    {
        scanf("%ld",&a[i]);
    }
    for(long i=2;i<=4;i++)
    {
        for(long j=1;j<i;j++)
        if(a[i]==a[j])ans++,a[j]=-1;
    }
    printf("%ld\n",ans);
    return 0;
}