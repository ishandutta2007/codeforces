#include<stdio.h>
#include<cstring>
using namespace std;
char p[18];long t;bool can[18];
bool l[20];
bool check(long a,long b)
{
    memset(l,true,sizeof l);
    for(long i=1;i<=a;i++)
    for(long j=1;j<=b;j++)
    {
        if(p[(i-1)*b+j]=='O')l[j]=false;
    }
    for(long i=1;i<=b;i++)if(l[i])return true;
    return false;
}
int main()
{
    scanf("%ld",&t);
    for(long is=1;is<=t;is++)
    {
        memset(can,false,sizeof can);
        memset(p,0,sizeof p);
        scanf("%s",p+1);
        long reu=0;
        for(long j=1;j<=12;j++)
        if(12%j==0)
        if(check(j,12/j)){reu++;can[j]=true;}
        printf("%ld ",reu);
        for(long i=1;i<=12;i++)if(can[i])printf("%ldx%ld ",i,12/i);
        putchar('\n');
    }
    return 0;
}