#include<stdio.h>
#include<cstring>
#define jsb 1000000007
using namespace std;
typedef long long LL;
char str[200];
int n;
LL ans=0;
LL tw[200]; 
int main()
{
    scanf("%s",str+1);n=strlen(str+1);
    tw[0]=1;for(int i=1;i<=n;i++)tw[i]=tw[i-1]*2ll%jsb;
    for(int i=1;i<=n;i++)if(str[i]=='1')
    ans=(ans+((tw[i-1]*tw[n-i]%jsb)*tw[n-i]%jsb))%jsb;
    printf("%I64d\n",ans);
    return 0;
}