#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
int n,a,b,c;
int main()
{
    scanf("%d%d%d%d",&n,&a,&b,&c);
    int cnt=0;
    if(n<=1)
    {
        printf("0\n");
        return 0;
    }
    if(a<=b&&a<=c)
    {
        printf("%d\n",a*(n-1));
        return 0;
    }
    else if(b<=a&&b<=c)
    {
        printf("%d\n",b*(n-1));
        return 0;
    }
    else
    {
        printf("%d\n",min(a,b)+c*(n-2));
        return 0;
    }
    return 0;
}