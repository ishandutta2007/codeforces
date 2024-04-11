#include<stdio.h>
#include<cstring>
#define MAXN 110000
using namespace std;
int l[MAXN],r[MAXN];int a[MAXN];
int ml[MAXN],mr[MAXN];
int n;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    r[n]=mr[n]=n+1;
    for(int i=n-1;i>=1;i--)
    {
            int j=i+1;
            while(j!=n+1&&a[j]<a[i])j=r[j];
            r[i]=j;
            j=i+1;
            while(j!=n+1&&a[j]>a[i])j=mr[j];
            mr[i]=j;
            }
    l[1]=ml[1]=0;
    for(int i=2;i<=n;i++)
    {
            int j=i-1;
            while(j&&a[j]<a[i])j=l[j];
            l[i]=j;
            j=i-1;
            while(j&&a[j]>a[i])j=ml[j];
            ml[i]=j;
            }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
            int j=mr[i];
            while(j!=n+1)
            {
                         if(a[j]>a[i])break;
                         if(j>r[i])break;
                         if((a[j]^a[i])>ans)
                         ans=(a[j]^a[i]);
                         j=r[j];
                         }
            j=ml[i];
            while(j)
            {
                         if(a[j]>a[i])break;
                         if(j<l[i])break;
                         if((a[j]^a[i])>ans)
                         ans=(a[j]^a[i]);
                         j=l[j];
                         }
                         }
    printf("%d\n",ans);
    return 0;
}