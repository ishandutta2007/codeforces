#include<stdio.h>
#include<cstring>
#define MAXN 110000
using namespace std;
char str[MAXN];
long sum[MAXN];
long n,m;
int main()
{
    char p=getchar();n=0;
    while(p!='\n')
    {
                  str[++n]=p;
                  p=getchar();
                  }
    for(long i=1;i<n;i++)
    {
             sum[i]=sum[i-1];
             if(str[i]==str[i+1])sum[i]++;
             }
    scanf("%ld",&m);
    for(long i=1;i<=m;i++)
    {
             long l,r;scanf("%ld%ld",&l,&r);
             r--;
             printf("%ld\n",sum[r]-sum[l-1]);
             }
    return 0;
}