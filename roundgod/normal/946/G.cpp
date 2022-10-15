#include<bits/stdc++.h>
#define maxn 250200
#define inf 1001500007

using namespace std;
int a[maxn],pos[maxn],b[maxn][2],c[maxn],d[maxn],n,ans,l,r,mid;
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    for (int i=1;i<=n;i++) a[i]+=(n-i);
    c[0]=0; for (int i=1;i<=n;i++) c[i]=d[i]=inf;
    for (int i=1;i<=n;i++)
    {
        //cout << a[i] << ' ';
        l=0; r=n;
        while (r-l>1)
        {
            mid=(l+r)>>1;
            if (a[i]<d[mid]) r=mid; else l=mid;
        }
        if (d[l+1]>a[i]){
            d[++l]=a[i];
            while (c[l]==a[i]&&pos[l]<i-1) d[++l]=a[i];
        }
        a[i]--;
        l=0; r=n;
        while (r-l>1)
        {
            mid=(l+r)>>1;
            if (a[i]<c[mid]) r=mid; else l=mid;
        }
        if (c[l+1]>a[i])
        {
            c[l+1]=a[i];
            pos[l+1]=i;
        }
    }
    //printf("\n");
    //for (int i=0;i<=n;i++) printf("%d ",c[i]); printf("\n");
    //for (int i=0;i<=n;i++) printf("%d ",d[i]); printf("\n");
    for (int i=0;i<=n;i++) if (c[i]<inf||d[i]<inf) ans=i;
    cout << max(0,n-ans-1) << endl;
}