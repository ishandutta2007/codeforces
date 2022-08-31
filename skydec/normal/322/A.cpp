#include<stdio.h>
#include<cstring>
using namespace std;
long n,m;
int main()
{
    scanf("%ld%ld",&n,&m);
    printf("%ld\n",n+m-1);
    for(long i=1;i<=n;i++)printf("%ld %ld\n",i,1);
    for(long i=2;i<=m;i++)printf("%ld %ld\n",1,i);
    //for(;;);
    return 0;
}