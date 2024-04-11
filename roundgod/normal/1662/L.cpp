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
int n,v,t[MAXN],a[MAXN],disa[MAXN],dp[MAXN],bit[MAXN],sz;
int query(int i)
{
    int s=-INF;
    while(i>0)
    {
        s=max(s,bit[i]);
        i-=i&-i;
    }
    return s;
}
void update(int i,int x)
{
    assert(i);
    while(i<=sz)
    {
        bit[i]=max(bit[i],x);
        i+=i&-i;
    }
}
void clear(int i)
{
    assert(i);
    while(i<=sz)
    {
        bit[i]=-INF;
        i+=i&-i;
    }
}
void solve(int l,int r)
{
    if(l==r) 
    {
        if(max(a[l],-a[l])<=1LL*v*t[l]) dp[l]=max(dp[l],1);
        return;
    }
    int mid=(l+r)/2;
    solve(l,mid);
    //ti<=tj update iff v(tj-ti)>=abs(ai-aj)
    //case 1:ai<=aj ==> aj-vtj<=ai-vti
    vector<ll> dis;
    for(int i=l;i<=r;i++) dis.push_back(a[i]-1LL*v*t[i]);
    sort(dis.begin(),dis.end());
    dis.erase(unique(dis.begin(),dis.end()),dis.end());
    vector<P> left,right;
    for(int i=l;i<=r;i++) 
    {
        int id=lower_bound(dis.begin(),dis.end(),a[i]-1LL*v*t[i])-dis.begin()+1;
        if(i<=mid) left.push_back(P(id,i)); else right.push_back(P(id,i));
    }
    sort(left.begin(),left.end(),greater<P>()); sort(right.begin(),right.end(),greater<P>());
    int id=0;
    for(int i=0;i<(int)right.size();i++)
    {
        while(id<(int)left.size()&&left[id].F>=right[i].F)
        {
            update(disa[left[id].S],dp[left[id].S]);
            id++;
        }
        dp[right[i].S]=max(dp[right[i].S],query(disa[right[i].S])+1);
    }
    for(int i=0;i<id;i++) clear(disa[left[i].S]);
    //case 2:ai>=aj ==> aj+vtj>=ai+vti
    dis.clear();
    for(int i=l;i<=r;i++) dis.push_back(a[i]+1LL*v*t[i]);
    sort(dis.begin(),dis.end());
    dis.erase(unique(dis.begin(),dis.end()),dis.end());
    left.clear(); right.clear();
    for(int i=l;i<=r;i++) 
    {
        int id=lower_bound(dis.begin(),dis.end(),a[i]+1LL*v*t[i])-dis.begin()+1;
        if(i<=mid) left.push_back(P(id,i)); else right.push_back(P(id,i));
    }
    sort(left.begin(),left.end()); sort(right.begin(),right.end());
    id=0;
    for(int i=0;i<(int)right.size();i++)
    {
        while(id<(int)left.size()&&left[id].F<=right[i].F)
        {
            update(sz-disa[left[id].S]+1,dp[left[id].S]);
            id++;
        }
        dp[right[i].S]=max(dp[right[i].S],query(sz-disa[right[i].S]+1)+1);
    }
    for(int i=0;i<id;i++) clear(sz-disa[left[i].S]+1);
    solve(mid+1,r);
}
int main()
{
    scanf("%d%d",&n,&v);
    for(int i=1;i<=n;i++) dp[i]=-INF;
    for(int i=1;i<=n;i++) scanf("%d",&t[i]);
    vector<int> tmp;
    for(int i=1;i<=n;i++) {scanf("%d",&a[i]); tmp.push_back(a[i]);}
    sort(tmp.begin(),tmp.end()); tmp.erase(unique(tmp.begin(),tmp.end()),tmp.end());
    sz=(int)tmp.size();
    for(int i=1;i<=sz;i++) bit[i]=-INF;
    for(int i=1;i<=n;i++) disa[i]=lower_bound(tmp.begin(),tmp.end(),a[i])-tmp.begin()+1;
    solve(1,n);
    int ans=0;
    for(int i=1;i<=n;i++) ans=max(ans,dp[i]);
    printf("%d\n",ans);
    return 0;
}