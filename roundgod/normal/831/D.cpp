#include<bits/stdc++.h>
#define MAXN 1005
#define MAXK 2005
#define INF 10000000000
using namespace std;
int n,k,p,a[MAXN],b[MAXK];
long long maxi(long long x,long long y)
{
    return x>y?x:y;
}
long long mini(long long x,long long y)
{
    return x<y?x:y;
}
long long t[MAXN][MAXK];
int main()
{
    scanf("%d %d %d",&n,&k,&p);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(int i=0;i<k;i++)
        scanf("%d",&b[i]);
    sort(a,a+n);
    sort(b,b+k);
    for(int i=0;i<n;i++)
        for(int j=0;j<k;j++)
            t[i][j]=max(a[i]-b[j],b[j]-a[i])+max(b[j]-p,p-b[j]);
    long long ans=INF;
    for(int i=0;i<k-n+1;i++)
    {
        long long q=-INF;
        for(int j=0;j<n;j++)
            q=maxi(q,t[j][j+i]);
        ans=mini(ans,q);
    }
    printf("%I64d\n",ans);
    return 0;
}