#include<stdio.h>
#include<cstring>
using namespace std;
char p[205];
long n;long now=0;
long abs(long x){if(x<0)return -x;else return x;}
int main()
{
    scanf("%ld",&n);
    scanf("%s",p+1);
    for(long i=1;i<=n;i++)if(p[i]=='X')now++;
    if(now==n/2)
    {
        printf("0\n%s",p+1);
        return 0;
    }
    printf("%ld\n",abs(now-n/2));
    if(now>n/2)
    {
        for(long i=1;i<=n;i++)
        if(p[i]=='X'&&now>n/2)
        {
            p[i]='x';now--;
        }
    }
    else
    {
        for(long i=1;i<=n;i++)
        if(p[i]=='x'&&now<n/2)
        {
            p[i]='X';now++;
        }
    }
    printf("%s",p+1);
    return 0;
}