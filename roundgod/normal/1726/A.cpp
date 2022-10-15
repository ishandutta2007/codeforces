#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,a[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        if(n==1) {puts("0"); continue;}
        int ans=-INF;
        for(int i=0;i<n;i++) ans=max(ans,a[(i+n-1)%n]-a[i]);
        if(n>2)
        {
            int mini=INF,maxi=-INF;
            for(int i=1;i<n-1;i++) {mini=min(mini,a[i]); maxi=max(maxi,a[i]);}
            ans=max(ans,maxi-a[0]); ans=max(ans,a[n-1]-mini);
        }
        printf("%d\n",ans);
    }
    return 0;
}