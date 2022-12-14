#include<bits/stdc++.h>
using namespace std;
#define mid (l+r)/2
#define L x*2
#define R x*2+1
int a[1000000];
vector<int> pos[1000000];
vector<int> ans[1000000];
map<int,int> last;
int tree[4000001];
void upd(int x,int l,int r,int v)
{
    if (v>r || v<l)
        return;
    if (l==r)
        tree[x]=1-tree[x];
    else
    {
        if (v<=mid)
            upd(L,l,mid,v);
        else
            upd(R,mid+1,r,v);
        tree[x]=tree[x*2]+tree[x*2+1];
    }
}
int get(int x,int l,int r,int s,int e)
{
    if (l>e || r<s)
        return 0;
    if (l>=s && r<=e)
        return tree[x];
    return get(L,l,mid,s,e)+get(R,mid+1,r,s,e);
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
int vis[1000000];
int main()
{
    int n,m;
    scanf("%d%d",&n, &m);
    for (int i=n;i>=1;i--)a[n-i+1]=i, pos[i].push_back(n-i+1), vis[i]=i, ret[i]=i;
    for (int i=n+1;i<=n+m;i++)
        scanf("%d",&a[i]) , vis[a[i]]=1,  pos[a[i]].push_back(i);

    int tot=0;
    for (int i=1;i<=n;i++)
        pos[i].push_back(n+m+1);
    for (int i=1;i<=n;i++) {
        for (int j=1;j<pos[i].size();j++) {
            if (pos[i][j-1]+1<=pos[i][j]-1) {
                Q[tot].l = pos[i][j - 1] + 1;
                Q[tot].r = pos[i][j] - 1;
                Q[tot++].id = i;
            }
        }
    }
    sort(Q,Q+tot);
    int curR = 1;
    for (int i=0;i<tot;i++)
    {
        query x = Q[i];
        while(curR<=x.r)
        {
            upd(1,1,n+m,last[a[curR]]);
            upd(1,1,n+m,curR);
            last[a[curR]]=curR;
            curR++;
        }
        ret[x.id]=max(ret[x.id],get(1,1,n+m,x.l,x.r)+1);
    }
    for (int i=1;i<=n;i++)
        printf("%d %d\n",vis[i], ret[i]);
}