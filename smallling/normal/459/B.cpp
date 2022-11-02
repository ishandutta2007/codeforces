#include<cstdio>
#include<algorithm>

using namespace std;

int n,a[200010],o1,o2;

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)
        if(a[i]==a[1])o1++;
        else break;
    for(int i=n;i;i--)
        if(a[i]==a[n])o2++;
        else break;
    if(o1==n)printf("0 %I64d",1ll*n*(n-1)/2ll);
    else printf("%d %I64d",a[n]-a[1],1ll*o1*o2);
}