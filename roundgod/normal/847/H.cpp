#include<cmath>
#include<set>
#include<cstdio>
#include<vector>
#include<queue>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define maxn 200020

using namespace std;
typedef long long ll;

ll n,a[maxn],b[maxn],c[maxn],s[maxn],t[maxn],ans,sum;

int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    b[1]=a[1];c[n]=a[n];s[0]=s[1]=0;t[n+1]=t[n]=0;
    for (int i=2;i<=n;i++) b[i]=max(b[i-1]+1,a[i]),s[i]=s[i-1]+(b[i]-a[i]);
    for (int i=n-1;i>=1;i--) c[i]=max(c[i+1]+1,a[i]),t[i]=t[i+1]+(c[i]-a[i]);
    ans=-1;
    for (int i=0;i<=n;i++)
    {
        sum=s[i]+t[i+1];
        if (b[i]==c[i+1]) sum++;
        if (ans==-1||sum<ans) ans=sum;
    }
    printf("%I64d\n",ans);
    return 0;
}