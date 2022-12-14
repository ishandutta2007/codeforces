#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define mid (l+r)/2
#define L (x<<1)
#define R (L+1)
struct node
{
    int a[11][2];
};
node tree[4*201001];
int has[10];
void process(int x)
{
    for (int i=0;i<10;i++)
        has[i]=0;
    for (int i=0;i<10;i++)
    {
        has[i]=x%10;
        x/=10;
    }
}
int a[1000000];
node Merge(node A,node B)
{
    node ret = A;
    for (int i=0;i<10;i++)
    {
        if (B.a[i][0]<ret.a[i][0])
        {
            swap(ret.a[i][0],ret.a[i][1]);
            ret.a[i][0]=B.a[i][0];
        }
        else if (B.a[i][0]<ret.a[i][1])
            ret.a[i][1]=B.a[i][0];
        if (B.a[i][1]<ret.a[i][0])
        {
            swap(ret.a[i][0],ret.a[i][1]);
            ret.a[i][0]=B.a[i][1];
        }
        else if (B.a[i][1]<ret.a[i][1])
            ret.a[i][1]=B.a[i][1];
    }
    return ret;
}
void build(int x,int l,int r)
{
    if (l==r)
    {
        process(a[l]);
        for (int i=0;i<10;i++){
            tree[x].a[i][0]=2e9;
            tree[x].a[i][1]=2e9;
            if (has[i])
                tree[x].a[i][0]=a[l];
        }
    }
    else
    {
        build(L,l,mid);
        build(R,mid+1,r);
        tree[x]=Merge(tree[L],tree[R]);
    }
}
void upd(int x,int l,int r,int id)
{
    if (id>r || id<l)return;
    if (l==r)
    {
        process(a[l]);
        for (int i=0;i<10;i++){
            tree[x].a[i][0]=2e9;
            tree[x].a[i][1]=2e9;
            if (has[i])
                tree[x].a[i][0]=a[l];
        }
    }
    else
    {
        if (id<=mid)
            upd(L,l,mid,id);
        else
            upd(R,mid+1,r,id);
        tree[x]=Merge(tree[L],tree[R]);
    }
}
node bad;
node query(int x,int l,int r,int s,int e)
{
    if (l>e || r<s)
        return bad;
    if (l>=s && r<=e)return tree[x];
    return Merge(query(L,l,mid,s,e),query(R,mid+1,r,s,e));
}
int main()
{
    int n,q;
    scanf("%d%d",&n,&q);
    for (int i=0;i<n;i++)
        scanf("%d",&a[i]);
    build(1,0,n-1);
    for (int i=0;i<10;i++)for (int j=0;j<2;j++)bad.a[i][j]=2e9;
    while(q--)
    {
        int typ;
        scanf("%d",&typ);
        if (typ==1)
        {
            int x,nw;
            scanf("%d%d",&x,&nw);
            a[x-1]=nw;
            upd(1,0,n-1,x-1);
        }
        else
        {
            int l,r;
            scanf("%d%d",&l,&r);
            int ret=2e9;
            node nd = query(1,0,n-1,l-1,r-1);
            for (int i=0;i<10;i++)
            {
                if (nd.a[i][0]==2e9 || nd.a[i][1]==2e9)continue;
                ret=min(ret,nd.a[i][0]+nd.a[i][1]);
            }
            if (ret==2e9)ret=-1;
            printf("%d\n",ret);
        }
    }
}