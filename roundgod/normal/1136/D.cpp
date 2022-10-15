#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXN 300005
#define MAXM 500005
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
int n,m;
int p[MAXN];
set<P> s;
vector<int> v;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&p[i]);
    for(int i=0;i<m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        s.insert(P(u,v));
    }
    v.push_back(p[n]);
    int ans=0;
    for(int i=n-1;i>=1;i--)
    {
        bool f=true;
        for(auto x:v)
        {
            if(!s.count(P(p[i],x)))
            {
                f=false;
                break;
            }
        }
        if(f) ans++; else v.push_back(p[i]);
    }
    printf("%d\n",ans);
    return 0;
}