#include<cstdio>
#include<algorithm>

using namespace std;

long long a[100010],f[100010],Max,n,o;

int main()
{
    scanf("%I64d",&n);
    for(int i=1;i<=n;i++)
        scanf("%I64d",&o),a[o]+=o;
    for(int i=100000;i;i--)
    {
        f[i]=max(max(a[i],f[i+1]),Max+a[i]);
        Max=max(Max,f[i+1]);
    }
    printf("%I64d",f[1]);
}