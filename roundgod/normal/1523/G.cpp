#include<bits/stdc++.h>
#define MAXN 50005
#define MAXLOGN 16
#define MAXM 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
#define x1 sakodsa
#define y1 dkoasad
#define x2 aksodas
#define y2 sadlapa
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,tot;
int root[MAXN],lson[200*MAXN],rson[200*MAXN],mini[200*MAXN];
int l[MAXM],r[MAXM],ans[MAXN];
vector<int> v[MAXN];
void update(int &k,int l,int r,int p,int v)
{
    if(!k)
    {
        k=++tot;
        mini[k]=INF;
    }
    mini[k]=min(mini[k],v);
    if(l==r) return;
    int mid=(l+r)/2;
    if(p<=mid) update(lson[k],l,mid,p,v); else update(rson[k],mid+1,r,p,v);
}
int query(int k,int l,int r,int x,int y)
{
    if(!k) return INF;
    if(l>y||x>r) return INF;
    if(l>=x&&r<=y) return mini[k];
    int mid=(l+r)/2;
    return min(query(lson[k],l,mid,x,y),query(rson[k],mid+1,r,x,y));
}
void outer_update(int l,int r,int x)
{
    for(int i=r;i<=n;i+=i&-i) update(root[i],1,n,l,x);
}
int outer_query(int l,int r)
{
    int res=INF;
    for(int i=r;i;i-=i&-i) res=min(res,query(root[i],1,n,l,n));
    return res;
}
int solve(int lb,int rb)
{
    if(lb>rb) return 0;
    int id=outer_query(lb,rb);
    if(id==INF) return 0;
    return r[id]-l[id]+1+solve(lb,l[id]-1)+solve(r[id]+1,rb);
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&l[i],&r[i]);
        v[r[i]-l[i]+1].push_back(i);
    }
    for(int i=n;i>=1;i--)
    {
        for(auto x:v[i]) outer_update(l[x],r[x],x);
        ans[i]=solve(1,n);
    }
    for(int i=1;i<=n;i++) printf("%d\n",ans[i]);
    return 0;
}