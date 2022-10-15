#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
int n,a,b;
int main()
{
    scanf("%d%d%d",&n,&a,&b);
    for(int i=0;a*i<=n;i++)
    {
        if((n-a*i)%b==0)
        {
            puts("YES");
            printf("%d %d\n",i,(n-a*i)/b);
            return 0;
        }
    }
    puts("NO");
    return 0;
}