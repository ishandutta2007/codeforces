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
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int,int> P;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef __gnu_pbds::priority_queue<int,greater<int>,pairing_heap_tag> pq;
int m,a,b;
ll ans;
bool vis[MAXN];
ll solve(ll x,ll g)
{
    ll ret=(x%g+1)*(x/g);
    ll num=x/g-1;
    return ret+(g+num*g)*num/2;
}
int main()
{
    scanf("%d%d%d",&m,&a,&b);
    ll pt=a+b-__gcd(a,b);
    ll ans=m+1;
    if(pt<=m) 
    {
        ll g=__gcd(a,b);
        ans+=solve(m,g)-solve(pt-1,g);
    }
    ll cnt=0;
    memset(vis,false,sizeof(vis));
    vis[0]=true;
    for(int i=1;i<=min(pt-1,(ll)m);i++)
    {
        if(i>=a&&vis[i-a])
        {
            vis[i]=true; cnt++;
            queue<int> que; que.push(i);
            while(que.size())
            {
                int v=que.front(); que.pop();
                if(v>=b&&!vis[v-b]) {vis[v-b]=true; cnt++; que.push(v-b);}
                if(v+a<=i&&!vis[v+a]) {vis[v+a]=true; cnt++; que.push(v+a);}
            }
        }
        ans+=cnt;
    }
    printf("%lld\n",ans);
    return 0;
}