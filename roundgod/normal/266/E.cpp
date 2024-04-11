#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,a[MAXN];
int comb[105][105];
int p[MAXN][6],sum[MAXN][6];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
struct node
{
    int a[6],len;
    void merge(node &lhs,node &rhs)
    {
        len=lhs.len+rhs.len;
        for(int i=0;i<=5;i++)
        {
            a[i]=lhs.a[i];
            for(int j=0;j<=i;j++) add(a[i],1LL*comb[i][j]*rhs.a[j]%MOD*p[lhs.len][i-j]%MOD);
        }
    }
};
node fake;
struct segtree
{
    node val[4*MAXN];
    int lazy[4*MAXN];
    void pushup(int k)
    {
        val[k].merge(val[k*2],val[k*2+1]);
    }
    void setval(int k,int x)
    {
        lazy[k]=x;
        for(int i=0;i<=5;i++) val[k].a[i]=1LL*x*sum[val[k].len][i]%MOD;
    }
    void pushdown(int k)
    {
        if(lazy[k]==-1) return;
        for(int i=k*2;i<=k*2+1;i++) setval(i,lazy[k]);
        lazy[k]=-1;
    }
    void build(int k,int l,int r)
    {
        lazy[k]=-1;
        val[k].len=r-l+1;
        if(l==r)
        {
            setval(k,a[l]);
            return;
        }
        int mid=(l+r)/2;
        build(k*2,l,mid); build(k*2+1,mid+1,r);
        pushup(k);
    }
    void update(int k,int l,int r,int x,int y,int v)
    {
        if(l>y||x>r) return;
        if(l>=x&&r<=y)
        {
            setval(k,v);
            return;
        }
        int mid=(l+r)/2;
        pushdown(k);
        update(k*2,l,mid,x,y,v); update(k*2+1,mid+1,r,x,y,v);
        pushup(k);
    }
    node query(int k,int l,int r,int x,int y)
    {
        if(l>y||x>r) return fake;
        if(l>=x&&r<=y) return val[k];
        pushdown(k);
        int mid=(l+r)/2;
        node newnode;
        node lhs=query(k*2,l,mid,x,y),rhs=query(k*2+1,mid+1,r,x,y);
        newnode.merge(lhs,rhs);
        return newnode;
    }
}seg;
char ch[5];
int main()
{
    fake.len=0;
    for(int i=0;i<=5;i++) fake.a[i]=0;
    comb[0][0]=1;
    for(int i=1;i<=100;i++)
    {
        comb[i][0]=comb[i][i]=1;
        for(int j=1;j<i;j++)
        {
            comb[i][j]=comb[i-1][j-1];
            add(comb[i][j],comb[i-1][j]);
        }
    }
    for(int i=0;i<=100000;i++)
    {
        p[i][0]=1;
        for(int j=1;j<=5;j++) p[i][j]=1LL*p[i][j-1]*i%MOD;
    }
    for(int i=0;i<=5;i++)
    {
        sum[1][i]=p[1][i];
        for(int j=2;j<=100000;j++)
        {
            sum[j][i]=sum[j-1][i];
            add(sum[j][i],p[j][i]);
        }
    }
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    seg.build(1,1,n);
    for(int i=0;i<m;i++)
    {
        int l,r,x;
        scanf("%s%d%d%d",ch,&l,&r,&x);
        if(ch[0]=='=') seg.update(1,1,n,l,r,x);
        else
        {
            node ret=seg.query(1,1,n,l,r);
            printf("%d\n",ret.a[x]);
        }
    }
    return 0;
}