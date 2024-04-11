#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,a[MAXN],b[MAXN];
int pre[MAXN],suf[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n;i++) scanf("%d",&b[i]);
        suf[n]=n;
        for(int i=n-1;i>=1;i--)
        {
            if(b[i]<a[i+1]) suf[i]=i;
            else suf[i]=suf[i+1];
        }
        for(int i=1;i<=n;i++) printf("%d ",*lower_bound(b+1,b+n+1,a[i])-a[i]);
        printf("\n");
        for(int i=1;i<=n;i++) printf("%d ",b[suf[i]]-a[i]);
        printf("\n");
    }
    return 0;
}