#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXN 300005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k;
priority_queue <int,vector<int>,greater<int> > pque;
P a[MAXN];
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) scanf("%d%d",&a[i].S,&a[i].F);
    sort(a+1,a+n+1,greater<P>());
    ll sum=0,ans=0;
    for(int i=1;i<=k;i++)
    {
        pque.push(a[i].S);
        sum+=a[i].S;
        ans=max(ans,sum*a[i].F);
    }
    ans=max(ans,sum*a[k].F);
    for(int i=k+1;i<=n;i++)
    {
        int p=pque.top();
        if(a[i].S<=p) continue;
        else
        {
            pque.pop();
            pque.push(a[i].S);
            sum-=p; sum+=a[i].S;
            ans=max(ans,sum*a[i].F);
        }
    }
    printf("%lld\n",ans);
    return 0;
}