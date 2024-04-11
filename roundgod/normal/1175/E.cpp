#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXN 200005
#define MAXLOGN 20
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
int n,m,a[MAXN];
int l[MAXN],r[MAXN];
int x[MAXN],y[MAXN];
int go[MAXLOGN][MAXM];
vector<int> add[MAXM];
set<int> ms;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<=500001;i++) go[0][i]=i;
    for(int i=1;i<=n;i++) 
    {
        scanf("%d%d",&l[i],&r[i]);
        add[l[i]].push_back(r[i]);
    }
    int mx=-1;
    for(int i=0;i<=500000;i++)
    {
        for(auto x:add[i]) mx=max(mx,x);
        if(mx>=i) go[0][i]=mx;
    }
    for(int k=0;k+1<MAXLOGN;k++)
        for(int i=0;i<=500000;i++)
            go[k+1][i]=go[k][go[k][i]];
    for(int i=0;i<m;i++)
    {
        scanf("%d%d",&x[i],&y[i]);
        int ans=0,now=x[i];
        if(go[MAXLOGN-1][now]<y[i]) {puts("-1"); continue;}
        for(int k=MAXLOGN-1;k>=0;k--)
        {
            if(go[k][now]<y[i])
            {
                now=go[k][now];
                ans+=(1<<k);
            }
        }
        if(now<y[i]) ans++;
        printf("%d\n",ans);
    }
    return 0;
}