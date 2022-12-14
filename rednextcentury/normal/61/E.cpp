/*# include <iostream>
# include <vector>
using namespace std;
struct ok
{
    long long y,z;
};
struct lady
{
    long long x,y,z;
};
bool operator<(ok a,ok b)
{
    return a.y<b.y;
}
bool operator<(lady a,lady b)
{
    return a.x<b.x;
}

set<ok> a[500001];
long long main()
{
    long long n;
    cin>>n;
    for (long long i=0;i<n-1;i++)
    {
        long long u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    solve(1);
    cout<<ans<<endl;
}
*/


# include <iostream>
# include <map>
# include <stdio.h>
# include <algorithm>
using namespace std;
int temp[1000001];
int a[1000001];
int b[2][1000001];
long long tree[2][5000001];
map<int,int> mp;
void update(int x,int l,int r,int v,int id)
{
    if (v<l || v>r)
        return;
    if (l==r && l==v)
        tree[id][x]=b[id][v];
    else
    {
        update(x*2,l,(l+r)/2,v,id);
        update(x*2+1,(l+r)/2 + 1, r, v, id);
        tree[id][x]=tree[id][x*2]+tree[id][x*2+1];
    }
}
long long query(int x,int l,int r,int s,int e,int id)
{
    if (e<l || s>r)
        return 0;
    if (l>=s && r<=e)
        return tree[id][x];
    else
        return query(x*2,l,(l+r)/2,s,e,id) + query(x*2+1,(l+r)/2 + 1, r, s,e, id);
}
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        temp[i]=a[i];
    }
    sort(temp,temp+n);
    for (int i=0;i<n;i++)
        mp[temp[i]]=i+1;
    for (int i=0;i<n;i++)
        a[i]=mp[a[i]];
    long long ans=0;
    for (int i=0;i<n;i++)
    {
        b[0][a[i]]++;
        int k=query(1,1,n,a[i]+1,n,0);
        b[1][a[i]]+=k;
        ans+=query(1,1,n,a[i]+1,n,1);
        update(1,1,n,a[i],0);
        update(1,1,n,a[i],1);
    }
    printf("%I64d\n",ans);
}