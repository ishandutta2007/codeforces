#include<stdio.h>
#include<cstring>
#define MAXN 1010000
using namespace std;
int n;char str[MAXN];
int main()
{
    scanf("%s",str+1);
    n=strlen(str+1);
    for(int i=1;i<=n;i++)if(str[i]=='r')printf("%d\n",i);
    for(int i=n;i>=1;i--)if(str[i]=='l')printf("%d\n",i);
    return 0;
}