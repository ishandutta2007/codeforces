#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mid (l+r)/2
#define L x*2
#define R x*2+1
int a[2000001];
int b[2000001];
map<int,int> last;
int tree[4000001];
int pre[2000001];
void upd(int x,int l,int r,int v)
{
    if (v>r || v<l)
        return;
    if (l==r)
        tree[x]=b[v];
    else
    {
        if (v<=mid)
            upd(L,l,mid,v);
        else
            upd(R,mid+1,r,v);
        tree[x]=tree[x*2]^tree[x*2+1];
    }
}
int get(int x,int l,int r,int s,int e)
{
    if (l>e || r<s)
        return 0;
    if (l>=s && r<=e)
        return tree[x];
    return get(L,l,mid,s,e)^get(R,mid+1,r,s,e);
}
struct query
{
    int l,r,id;
};
bool operator<(query A,query B)
{
    return A.r<B.r;
}
query Q[2000000];
int ret[1000001];
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%d",&a[i]),pre[i]=pre[i-1]^a[i];
    int m;
    scanf("%d",&m);
    for (int i=1;i<=m;i++)
        scanf("%d%d",&Q[i].l,&Q[i].r),Q[i].id=i;
    sort(Q+1,Q+1+m);
    int curR = 1;
    for (int i=1;i<=m;i++)
    {
        query x = Q[i];
        while(curR<=x.r)
        {
            b[last[a[curR]]]=0;
            b[curR]=a[curR];
            upd(1,1,n,last[a[curR]]);
            upd(1,1,n,curR);
            last[a[curR]]=curR;
            curR++;
        }
        ret[x.id]=(pre[x.r]^pre[x.l-1])^get(1,1,n,x.l,x.r);
    }
    for (int i=1;i<=m;i++)
        printf("%d\n",ret[i]);
}