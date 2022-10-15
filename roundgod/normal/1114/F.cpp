#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 400005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,q,a[MAXN];
int prime[305],inv[305];
bool is_prime[305];
int pow_mod(int a,int i)
{
    int s=1;
    while(i)
    {
        if(i&1) s=1LL*s*a%MOD;
        a=1LL*a*a%MOD;
        i>>=1;
    }
    return s;
}
int sieve(int n)
{
    int p=0;
    for(int i=0;i<=n;i++) is_prime[i]=true;
    is_prime[0]=is_prime[1]=false;
    for(int i=2;i<=n;i++)
    {
        if(is_prime[i]) prime[p++]=i;
        for(int j=0;j<p;j++)
        {
            if(prime[j]*i>n) break;
            is_prime[prime[j]*i]=false;
            if(i%prime[j]==0) break;
        }
    }
    return p;
}
struct segtree
{
    bitset<62> has[4*MAXN];
    bitset<62> laz[4*MAXN];
    int ans[4*MAXN];
    int lazy[4*MAXN];
    void pushup(int k)
    {
        ans[k]=1LL*ans[k*2]*ans[k*2+1]%MOD;
        has[k]=has[k*2]|has[k*2+1];
    }
    void pushdown1(int k,int l,int r)
    {
        if(lazy[k]==1) return;
        int mid=(l+r)/2,len1=mid-l+1,len2=r-mid;
        lazy[k*2]=1LL*lazy[k*2]*lazy[k]%MOD;
        ans[k*2]=1LL*ans[k*2]*pow_mod(lazy[k],len1)%MOD;
        lazy[k*2+1]=1LL*lazy[k*2+1]*lazy[k]%MOD;
        ans[k*2+1]=1LL*ans[k*2+1]*pow_mod(lazy[k],len2)%MOD;
        lazy[k]=1;
    }
    void pushdown2(int k)
    {
        for(int i=k*2;i<=k*2+1;i++) 
        {
            laz[i]|=laz[k];
            has[i]|=laz[k];
        }
        laz[k].reset();
    }
    void build(int k,int l,int r)
    {
        lazy[k]=1;has[k].reset();laz[k].reset();
        if(l==r)
        {
            ans[k]=a[l];
            for(int i=0;i<62;i++) if(a[l]%prime[i]==0) has[k].set(i);
            return;
        }
        int mid=(l+r)/2;
        build(k*2,l,mid);build(k*2+1,mid+1,r);
        pushup(k);
    }
    void update(int k,int l,int r,int x,int y,int v,bitset<62> &bit)
    {
        if(l>y||x>r) return;
        if(l>=x&&r<=y)
        {
            lazy[k]=1LL*lazy[k]*v%MOD;
            ans[k]=1LL*ans[k]*pow_mod(v,r-l+1)%MOD;
            laz[k]|=bit;has[k]|=bit;
            return;
        }
        pushdown1(k,l,r);
        pushdown2(k);
        int mid=(l+r)/2;
        update(k*2,l,mid,x,y,v,bit);update(k*2+1,mid+1,r,x,y,v,bit);
        pushup(k);
    }
    int query1(int k,int l,int r,int x,int y)
    {
        if(l>y||x>r) return 1;
        if(l>=x&&r<=y) return ans[k];
        pushdown1(k,l,r);
        int mid=(l+r)/2;
        return 1LL*query1(k*2,l,mid,x,y)*query1(k*2+1,mid+1,r,x,y)%MOD;
    }
    bitset<62> query2(int k,int l,int r,int x,int y)
    {
        if(l>y||x>r)
        {
            bitset<62> ret;
            ret.reset();
            return ret;
        }
        if(l>=x&&r<=y) return has[k];
        pushdown2(k);
        int mid=(l+r)/2;
        return query2(k*2,l,mid,x,y)|query2(k*2+1,mid+1,r,x,y);
    }
}seg;
char str[10];
int main()
{
    int p=sieve(300);
    for(int i=0;i<p;i++) inv[i]=pow_mod(prime[i],MOD-2);  
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    seg.build(1,1,n);
    for(int i=0;i<q;i++)
    {
        int l,r,x;
        scanf("%s",str);
        if(str[0]=='T')
        {
            scanf("%d%d",&l,&r);
            int res=seg.query1(1,1,n,l,r);
            bitset<62> bit=seg.query2(1,1,n,l,r);
            for(int j=0;j<62;j++) 
                if(bit[j]) 
                    res=1LL*res*inv[j]%MOD*(prime[j]-1)%MOD;
            printf("%d\n",res);
        }
        else
        {
            scanf("%d%d%d",&l,&r,&x);
            bitset<62> bit;bit.reset();
            for(int j=0;j<62;j++) if(x%prime[j]==0) bit.set(j);
            seg.update(1,1,n,l,r,x,bit);
        }
    }
    return 0;
}