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
int n,m;
bool gr[MAXN];
int t[MAXN],l[MAXN],r[MAXN];
int ans[MAXN];
int main()
{
    scanf("%d%d",&n,&m);
    memset(gr,false,sizeof(gr));
    for(int i=1;i<=m;i++) 
    {
        scanf("%d%d%d",&t[i],&l[i],&r[i]);
        if(t[i])
        {
            for(int j=l[i]+1;j<=r[i];j++) gr[j]=true;
        }
    }
    ans[1]=1000;
    for(int j=2;j<=n;j++)
    {
        if(gr[j]) ans[j]=ans[j-1];
        else ans[j]=ans[j-1]-1;
    }
    bool f=true;
    for(int i=1;i<=m;i++)
    {
        bool flag=true;
        if(!t[i])
        {
            for(int j=l[i]+1;j<=r[i];j++) if(ans[j]<ans[j-1]) flag=false;
            if(flag) f=false;
        }
    }
    if(!f) {puts("NO"); return 0;}
    puts("YES");
    for(int i=1;i<=n;i++) printf("%d%c",ans[i],i==n?'\n':' ');
    return 0;
}