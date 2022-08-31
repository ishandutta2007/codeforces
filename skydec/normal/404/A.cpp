#include<stdio.h>
using namespace std;
char p[305][305];
long n;
int main()
{
    scanf("%ld",&n);
    for(long i=1;i<=n;i++)scanf("%s",p[i]+1);
    char s1=p[1][1];char s2=p[1][2];bool flag=true;
    if(s1==s2)flag=false;
    for(long i=1;i<=n;i++)
    for(long j=1;j<=n;j++)
    if(i==j)
    {
            if(s1!=p[i][j])flag=false;
            }
    else
    if(i+j==n+1)
    {
            if(s1!=p[i][j])flag=false;
            }
    else
    {
            if(s2!=p[i][j])flag=false;
            }
    if(flag)printf("YES\n");else printf("NO\n");
    return 0;
}