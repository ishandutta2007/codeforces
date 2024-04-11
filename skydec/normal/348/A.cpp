#include<stdio.h>
using namespace std;
typedef long long LL;
int n;
LL sum;
int main()
{
    scanf("%d",&n);LL max=0;
    for(int i=1;i<=n;i++)
    {
            LL p;scanf("%I64d",&p);sum+=p;
            if(p>max)max=p;
            }
    LL ans=sum/(n-1);
    if(sum%(n-1)!=0)ans++;
    if(ans<max)ans=max;
    printf("%I64d\n",ans);
    return 0;
}