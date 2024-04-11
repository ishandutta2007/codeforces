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
int absd(int x,int y)
{
    return max(x-y,y-x);
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int mid=(n-4)/3;
        int ans=-INF;
        for(int i=mid-10;i<=mid+10;i++)
        {
            if(i>=1&&i<n-4)
            {
                ans=max(ans,min(absd(i,n-4-i),min(absd(1,i),absd(1,n-4-i))));
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}