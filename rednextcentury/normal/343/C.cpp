#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[1000000];
long long b[1000000];
bool check(long long mid)
{
    int l=0;
    for (int i=0;i<n;i++)
    {
        if (abs(a[i]-b[l])>mid)continue;
        int s=l;

        while(1)
        {
            l++;
            if (l==m)return 1;
            if (min(abs(a[i]-b[s])+abs(b[s]-b[l]),abs(a[i]-b[l])+abs(b[l]-b[s]))>mid)
                break;
        }
        if (l==m)return 1;
    }
    if (l==m)return 1;
    return 0;
}
long long binsearch(long long l,long long r)
{
    long long ans=-1;
    while(l<=r)
    {
        long long mid=(l+r)/2;
        if (check(mid))
            ans=mid,r=mid-1;
        else
            l=mid+1;
    }
    return ans;
}
int main()
{
    scanf("%d%d",&n,&m);
    for (int i=0;i<n;i++)
        scanf("%I64d",&a[i]);
    for (int j=0;j<m;j++)
        scanf("%I64d",&b[j]);
    printf("%I64d\n",binsearch(0,(1LL<<50)));
}