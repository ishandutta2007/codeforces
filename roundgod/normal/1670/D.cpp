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
ll check(int a,int b,int c)
{
    return 2LL*a*b+2LL*b*c+2LL*a*c;
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int l=0,r=30000;
        while(r-l>1)
        {
            int mid=(l+r)/2;
            if(check(mid,mid,mid)>=n) r=mid; else l=mid;
        }
        int ans=3*r;
        if(check(r-1,r,r)>=n) ans=3*r-1;
        if(check(r-1,r-1,r)>=n) ans=3*r-2;
        printf("%d\n",ans);
    }
    return 0;
}