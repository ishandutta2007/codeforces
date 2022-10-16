#include <cstdio>
using namespace std;
const int maxn=200005;
int n,q,i,j;
long long a[maxn];
long long now,v;
int l,r,mid;
int getpos(long long v)
{
    if (v>=a[n])
        return n+1;
    l=1;
    r=n;
    while (l<r)
    {
        mid=(l+r+1)>>1;
        if (a[mid]>v)
            r=mid-1;
        else
            l=mid;
    }
    while (a[r]>v)
        r--;
    while (a[r+1]<=v)
        r++;
    return r;
}
int main()
{
    scanf("%d%d",&n,&q);
    for (i=1;i<=n;i++)
        scanf("%I64d",&a[i]);
    for (i=1;i<=n;i++)
        a[i]+=a[i-1];
    for (i=1;i<=q;i++)
    {
        scanf("%I64d",&v);
        now+=v;
        j=getpos(now);
        if (j==n+1)
        {
            j=0;
            now=0;
        }
        printf("%d\n",n-j);
    }
    return 0;
}