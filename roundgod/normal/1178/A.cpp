#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int,int> P;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef __gnu_pbds::priority_queue<int,greater<int>,pairing_heap_tag> pq;
int n,k;
P a[MAXN];
int main()
{
    scanf("%d",&n);
    int sum=0;
    for(int i=1;i<=n;i++) 
    {
        scanf("%d",&a[i].F);
        a[i].S=i;
        sum+=a[i].F;
    }
    sort(a+2,a+n+1);
    int cur=a[1].F;
    vector<int> ans;
    ans.push_back(1);
    for(int i=2;i<=n;i++)
    {
        if(a[i].F*2<=a[1].F)
        {
            ans.push_back(a[i].S);
            cur+=a[i].F;
        }
    }
    if(cur*2<=sum) puts("0");
    else
    {
        printf("%d\n",(int)ans.size());
        for(auto x:ans) printf("%d ",x);
        puts("");
    }
    return 0;
}