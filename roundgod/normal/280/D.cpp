#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,q,a[MAXN];
struct node
{
    int lmax,rmax,maxi,sum;
    int lmaxpos,rmaxpos,lminpos,rminpos;
    int lmaxipos,rmaxipos,lminipos,rminipos;
    int lmin,rmin,mini;
    int lazy;
    void init(int pos,int val)
    {
        lazy=0;
        lmax=rmax=maxi=lmin=rmin=mini=sum=val;
        lmaxpos=rmaxpos=lminpos=rminpos=lmaxipos=rmaxipos=lminipos=rminipos=pos;
    }
    void merge(node &lhs,node &rhs)
    {
        sum=lhs.sum+rhs.sum;
        if(lhs.lmax>=lhs.sum+rhs.lmax)
        {
            lmax=lhs.lmax;
            lmaxpos=lhs.lmaxpos;
        }
        else
        {
            lmax=lhs.sum+rhs.lmax;
            lmaxpos=rhs.lmaxpos;
        }
        if(rhs.rmax>=rhs.sum+lhs.rmax)
        {
            rmax=rhs.rmax;
            rmaxpos=rhs.rmaxpos;
        }
        else
        {
            rmax=rhs.sum+lhs.rmax;
            rmaxpos=lhs.rmaxpos;
        }
        if(lhs.maxi>=rhs.maxi)
        {
            maxi=lhs.maxi;
            lmaxipos=lhs.lmaxipos; rmaxipos=lhs.rmaxipos;
        }
        else
        {
            maxi=rhs.maxi;
            lmaxipos=rhs.lmaxipos; rmaxipos=rhs.rmaxipos;
        }
        if(lhs.rmax+rhs.lmax>=maxi)
        {
            maxi=lhs.rmax+rhs.lmax;
            lmaxipos=lhs.rmaxpos; rmaxipos=rhs.lmaxpos;
        }
        if(lhs.lmin<=lhs.sum+rhs.lmin)
        {
            lmin=lhs.lmin;
            lminpos=lhs.lminpos;
        }
        else
        {
            lmin=lhs.sum+rhs.lmin;
            lminpos=rhs.lminpos;
        }
        if(rhs.rmin<=rhs.sum+lhs.rmin)
        {
            rmin=rhs.rmin;
            rminpos=rhs.rminpos;
        }
        else
        {
            rmin=rhs.sum+lhs.rmin;
            rminpos=lhs.rminpos;
        }
        if(lhs.mini<=rhs.mini)
        {
            mini=lhs.mini;
            lminipos=lhs.lminipos; rminipos=lhs.rminipos;
        }
        else
        {
            mini=rhs.mini;
            lminipos=rhs.lminipos; rminipos=rhs.rminipos;
        }
        if(lhs.rmin+rhs.lmin<=mini)
        {
            mini=lhs.rmin+rhs.lmin;
            lminipos=lhs.rminpos; rminipos=rhs.lminpos;
        }
    }
    void rev()
    {
        lazy^=1;
        swap(lmin,lmax); swap(rmin,rmax); swap(mini,maxi);
        swap(lmaxpos,lminpos); swap(rmaxpos,rminpos);
        swap(lmaxipos,lminipos); swap(rmaxipos,rminipos);
        lmin=-lmin; lmax=-lmax; rmin=-rmin; rmax=-rmax; mini=-mini; maxi=-maxi;
        sum=-sum;
    }
};
node noth;
struct segtree
{
    node p[4*MAXN];
    void pushup(int k)
    {
        p[k].merge(p[k*2],p[k*2+1]);
    }
    void pushdown(int k)
    {
        if(!p[k].lazy) return;
        for(int i=k*2;i<=k*2+1;i++) p[i].rev();
        p[k].lazy=0;
    }
    void build(int k,int l,int r)
    {
        if(l==r)
        {
            p[k].init(l,a[l]);
            return;
        }
        int mid=(l+r)/2;
        build(k*2,l,mid); build(k*2+1,mid+1,r);
        pushup(k);
    }
    void update(int k,int l,int r,int pos,int val)
    {
        if(l==r)
        {
            p[k].init(l,val);
            return;
        }
        pushdown(k);
        int mid=(l+r)/2;
        if(pos<=mid) update(k*2,l,mid,pos,val); else update(k*2+1,mid+1,r,pos,val);
        pushup(k);
    }
    void flip(int k,int l,int r,int x,int y)
    {
        if(x>r||l>y) return;
        if(l>=x&&r<=y)
        {
            p[k].rev();
            return;
        }
        pushdown(k);
        int mid=(l+r)/2;
        flip(k*2,l,mid,x,y); flip(k*2+1,mid+1,r,x,y);
        pushup(k);
    }
    node query(int k,int l,int r,int x,int y)
    {
        if(x>r||l>y) return noth;
        if(l>=x&&r<=y) return p[k];
        pushdown(k);
        int mid=(l+r)/2;
        node lhs=query(k*2,l,mid,x,y); node rhs=query(k*2+1,mid+1,r,x,y);
        node nnode; nnode.merge(lhs,rhs);
        return nnode;
    }
}seg;
vector<P> op;
int main()
{
    noth.lmax=noth.rmax=noth.maxi-INF; noth.sum=0;
    noth.lmin=noth.rmin=noth.mini=INF;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    seg.build(1,1,n);
    scanf("%d",&q);
    for(int i=0;i<q;i++)
    {
        int type,l,r,k,pos,val;
        scanf("%d",&type);
        if(type==0)
        {
            scanf("%d%d",&pos,&val);
            seg.update(1,1,n,pos,val);
        }
        else
        {
            scanf("%d%d%d",&l,&r,&k);
            op.clear();
            int ans=0;
            for(int j=0;j<k;j++)
            {
                node res=seg.query(1,1,n,l,r);
                if(res.maxi<=0) break;
                ans+=res.maxi;
                op.push_back(P(res.lmaxipos,res.rmaxipos));
                seg.flip(1,1,n,res.lmaxipos,res.rmaxipos);
            }
            printf("%d\n",ans);
            for(auto p:op) seg.flip(1,1,n,p.F,p.S);
        }
    }
    return 0;
}