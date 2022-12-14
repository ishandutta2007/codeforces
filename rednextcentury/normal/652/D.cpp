
 #include<bits/stdc++.h>
using namespace std;
struct seg
{
    int l,r,id;
};
bool comp1(seg a,seg b)
{
    return a.l<b.l;
}

bool comp2(seg a,seg b)
{
    return a.r<b.r;
}
seg a[1000000];
map<int,int> mp;
int tree[1000000];
bool o[1000000];
void upd(int x,int l,int r,int v)
{
    if (v<l || v>r)return;
    if (v==l && v==r)
        tree[x]=1;
    else
    {
        upd(x*2,l,(l+r)/2,v);
        upd(x*2+1,(l+r)/2+1,r,v);
        tree[x]=tree[x*2]+tree[x*2+1];
    }
}
int query(int x,int l,int r,int s,int e)
{
    if (s>r || e<l)return 0;
    if(l>=s && r<=e)return tree[x];
    return query(x*2,l,(l+r)/2,s,e)+query(x*2+1,(l+r)/2+1,r,s,e);
}
int ans[1000000];
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%d%d",&a[i].l,&a[i].r);
        a[i].id=i;
    }
    sort(a+1,a+n+1,comp1);
    for (int i=1;i<=n;i++)
    {
        mp[a[i].l]=i;
    }

    sort(a+1,a+n+1,comp2);
    for (int i=1;i<=n;i++)
    {
        ans[a[i].id]=query(1,1,n,mp[a[i].l],n);
        upd(1,1,n,mp[a[i].l]);
    }
    for (int i=1;i<=n;i++)
        printf("%d\n",ans[i]);
}