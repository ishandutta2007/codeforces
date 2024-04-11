#include<stdio.h>
#include<cstring>
using namespace std;
char p[110000][3];
long n;long tot=0;
int main()
{
    scanf("%ld",&n);
    for(long i=1;i<=n;i++)
    {
             scanf("%s",p[i]+1);
             if(i==1||p[i][1]==p[i-1][2])tot++;
             }
    printf("%ld\n",tot);
    return 0;
}