#include<cstdio>

using namespace std;

int tree[400010],lazy[400010],l[100010],r[100010],a[100010];
int now,n,m;

inline void down(int k)
{
    tree[k<<1]|=lazy[k];
    tree[k<<1|1]|=lazy[k];
    lazy[k<<1]|=lazy[k];
    lazy[k<<1|1]|=lazy[k];
}

void add(int k,int l,int r,int ll,int rr,int o)
{
    if(l>=ll&&r<=rr)
    {
        tree[k]|=o;
        lazy[k]|=o;
        return;
    }
    int mid=l+r>>1;
    down(k);
    if(mid>=ll)add(k<<1,l,mid,ll,rr,o);
    if(mid<rr)add(k<<1|1,mid+1,r,ll,rr,o);
    tree[k]=tree[k<<1]&tree[k<<1|1];
}

void ask(int k,int l,int r,int ll,int rr)
{
    if(l>=ll&&r<=rr)
    {
        now&=tree[k];
        return;
    }
    int mid=l+r>>1;
    down(k);
    if(mid>=ll)ask(k<<1,l,mid,ll,rr);
    if(mid<rr)ask(k<<1|1,mid+1,r,ll,rr);    
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&l[i],&r[i],&a[i]);
        add(1,1,n,l[i],r[i],a[i]);
    }
    for(int i=1;i<=m;i++)
    {
        now=(1<<31)-1;
        ask(1,1,n,l[i],r[i]);
        if(now!=a[i])return puts("NO"),0;
    }
    puts("YES");
    for(int i=1;i<=n;i++)
    {
        now=(1<<31)-1;
        ask(1,1,n,i,i);
        printf("%d ",now);
    }
}