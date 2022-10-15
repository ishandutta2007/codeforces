#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000001
using namespace std;
int n,k;
int a[MAXN],min1[MAXN],min2[MAXN];
int main()
{
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        if(i==0) min1[i]=a[i]; else min1[i]=min(a[i],min1[i-1]);
    }
    min2[n-1]=a[n-1];
    for(int i=n-2;i>=0;i--)
        min2[i]=min(min2[i+1],a[i]);
    if(k==1)
    {
        sort(a,a+n);
        printf("%d\n",a[0]);
    }
    else if(k>=3)
    {
        sort(a,a+n);
        printf("%d\n",a[n-1]);
    }
    else
    {
        int ans=-INF;
        for(int i=0;i<n-1;i++)
            ans=max(ans,max(min1[i],min2[i+1]));
        printf("%d\n",ans);
    }
    return 0;
}