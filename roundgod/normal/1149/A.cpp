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
int n,x,cnt1,cnt2;
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&x);
        if(x==1) cnt1++; else cnt2++;
    }
    if(cnt2==0)
    {
        for(int i=0;i<cnt1;i++) printf("%d ",1);
        return 0;
    }
    else if(cnt1==0)
    {
        for(int i=0;i<cnt2;i++) printf("%d ",2);
        return 0;
    }
    printf("%d ",2);
    cnt2--;
    printf("%d ",1); cnt1--;
    for(int i=0;i<cnt2;i++) printf("%d ",2);
    for(int i=0;i<cnt1;i++) printf("%d ",1);
    return 0;
}