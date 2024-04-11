#include<bits/stdc++.h>
using namespace std;
struct node
{
    int f,s,ans1,ans2;
};
node tree[10000000];
int a[10000000];
char ss[2000000],q[100];
node Merge(node a, node b)
{
    node ret;
    ret.f=a.f+b.f;
    ret.s=a.s+b.s;
    ret.ans1=max(max(a.ans1+b.s,b.ans1+a.f),max(a.f+b.s,max(a.f+b.f,a.s+b.s)));
    ret.ans2=max(max(a.ans2+b.f,b.ans2+a.s),max(a.s+b.f,max(a.f+b.f,a.s+b.s)));
    return ret;
}
void build(int x,int l,int r)
{
    if (l==r)
    {
        if (ss[l]=='4')tree[x].f=1;
        else tree[x].s=1;
        tree[x].ans1=tree[x].ans2=1;;
    }
    else
    {
        build(x*2,l,(l+r)/2);
        build(x*2+1,(l+r)/2+1,r);
        tree[x]=Merge(tree[x*2],tree[x*2+1]);
    }
}
bool lazy[10000000];
inline void lzy(int x)
{
    if (lazy[x])
    {
        swap(tree[x].ans1,tree[x].ans2);
        swap(tree[x].f,tree[x].s);
        lazy[x*2]=1-lazy[x*2];
        lazy[x*2+1]=1-lazy[x*2+1];
        lazy[x]=0;
    }
}
void upd(int x,int l,int r,int s,int e)
{
    lzy(x);
    if (s>r || e<l)return;
    if (l>=s && r<=e)
    {
        lazy[x]=1-lazy[x];
        lzy(x);
    }
    else
    {
        upd(x*2,l,(l+r)/2,s,e);
        upd(x*2+1,(l+r)/2+1,r,s,e);
        tree[x]=Merge(tree[x*2],tree[x*2+1]);
    }
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    scanf("%s",ss);
    build(1,0,n-1);
    while(m--)
    {
        scanf("%s",q);
        if (q[0]=='c')
            printf("%d\n",tree[1].ans1);
        else
        {
            int l,r;
            scanf("%d%d",&l,&r);
            upd(1,0,n-1,l-1,r-1);
        }
    }
}