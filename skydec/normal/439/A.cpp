#include<stdio.h>
using namespace std;
long n,d;
long sum=0;
int main()
{
    scanf("%ld%ld",&n,&d);
    for(long i=1;i<=n;i++)
    {
             long v;scanf("%ld",&v);sum+=v;
             }
    sum+=(n-1)*10;
    if(sum>d)
    {
             printf("-1");
             return 0;
             }
    printf("%ld\n",(n-1)*2+((d-sum)/5));
    return 0;
}