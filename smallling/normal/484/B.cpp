#include<cstdio>
#include<algorithm>

using namespace std;

int n,ans,a[200020],o;

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    sort(a+1,a+1+n);
    n=unique(a+1,a+1+n)-(a+1);
    for(int i=1;i<=n;i++)
        for(int j=a[i]+a[i];j-a[i]<=a[n];j+=a[i])
        {
            o=lower_bound(a+1,a+1+n,j)-a-1;
            if(o<=i)continue;
            ans=max(ans,a[o]%a[i]);
        }
    printf("%d",ans);
}