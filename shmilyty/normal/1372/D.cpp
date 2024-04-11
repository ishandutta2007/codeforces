#include <bits/stdc++.h>
using namespace std;
int t,l,r;
int n,a[400010],k;
long long ans,sum;
int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
        a[i+n]=a[i];
    k=(n+1)/2-1;
    l=1,r=l+k*2;
    for(int i=l;i<=r;i+=2)
        sum+=a[i];
    ans=max(ans,sum);
    while(r<=2*n) {
        l+=2,r+=2;
        sum-=a[l-2];
        sum+=a[r];
        ans=max(ans,sum);
    }
    l=2,r=l+k*2;
    sum=0;
    for(int i=l;i<=r;i+=2)
        sum+=a[i];
    ans=max(ans,sum);
    while(r<=2*n) {
        l+=2,r+=2;
        sum-=a[l-2];
        sum+=a[r];
        ans=max(ans,sum);
    }
    printf("%lld\n",ans);
    return 0;
}