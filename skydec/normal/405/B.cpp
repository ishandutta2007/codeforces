#include<stdio.h>
using namespace std;
char domino[4000];long len;long ans=0;
int main()
{
    scanf("%ld",&len);
    scanf("%s",domino+1);
    for(long i=1;i<=len;i++)
    if(domino[i]=='.')
    {
             long left=i;long right=i;
             for(long j=i-1;j>=1;j--)
             if(domino[j]=='R')left=j;
             else if(domino[j]=='L')break;
             for(long j=i+1;j<=len;j++)
             if(domino[j]=='L')right=j;
             else if(domino[j]=='R')break;
             if(i-left==right-i)ans++;
             }
     printf("%ld\n",ans);
     //for(;;);
     return 0;
}