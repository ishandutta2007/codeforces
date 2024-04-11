#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXLOGN 20
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
#define next sakoisad
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int,int> P;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef __gnu_pbds::priority_queue<int,greater<int>,pairing_heap_tag> pq;
int n,m,q;
int p[MAXN],a[MAXN];
int next[MAXLOGN][MAXN],nextp[MAXN],lastpos[MAXN];
int ans[MAXN];
int st[MAXN][MAXLOGN];
int pre[MAXN];
void init(int n,int *arr)
{
    pre[1]=0;
    for(int i=2;i<=n;i++)
    {
        pre[i]=pre[i-1];
        if ((1<<pre[i]+1)==i) ++pre[i];
    }
    for(int i=n;i>=1;--i)
    {
        st[i][0]=arr[i];
        for(int j=1;(i+(1<<j)-1)<=n;++j)
            st[i][j]=min(st[i][j-1],st[i+(1<<j-1)][j-1]);
    }
}
int query(int l,int r)
{
    int len=r-l+1,k=pre[len];
    return min(st[l][k],st[r-(1<<k)+1][k]);
}
int main()
{
    scanf("%d%d%d",&n,&m,&q);
    for(int i=1;i<=n;i++) scanf("%d",&p[i]);
    for(int i=1;i<=n;i++) lastpos[i]=m+1;
    for(int i=1;i<=n-1;i++) nextp[p[i]]=p[i+1];
    nextp[p[n]]=p[1];
    for(int i=1;i<=m;i++) scanf("%d",&a[i]);
    for(int i=m;i>=1;i--) 
    {
        next[0][i]=lastpos[nextp[a[i]]];
        lastpos[a[i]]=i;
    }
    for(int k=0;k+1<MAXLOGN;k++)
    {
        for(int i=1;i<=m;i++)
        {
            if(next[k][i]==m+1) next[k+1][i]=m+1;
            else next[k+1][i]=next[k][next[k][i]];
        }
    }
    for(int i=1;i<=m;i++)
    {
        int v=i;
        for(int k=0;k<MAXLOGN;k++)
            if(((n-1)>>k)&1)
                v=next[k][v];
        ans[i]=(v==0?m+1:v);
    }
    init(m,ans);
    for(int i=0;i<q;i++)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        if(query(l,r)<=r) printf("1");  else printf("0");
    }
    return 0;
}