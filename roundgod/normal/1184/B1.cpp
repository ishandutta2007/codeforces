#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXN 200005
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
int n,m,a[MAXN],b[MAXN],g[MAXN];
int maxi[MAXN];
vector<int> v;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        v.push_back(a[i]);
    }
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&b[i],&g[i]);
        v.push_back(b[i]);
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    for(int i=1;i<=m;i++)
    {
        int id=lower_bound(v.begin(),v.end(),b[i])-v.begin();
        maxi[id]+=g[i];
    }
    for(int i=1;i<=200000;i++) maxi[i]=maxi[i]+maxi[i-1];
    for(int i=1;i<=n;i++)
    {
        int id=lower_bound(v.begin(),v.end(),a[i])-v.begin();
        printf("%d ",maxi[id]);
    }
    return 0;
}