#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,q,p[MAXN],ans;
P tmp[MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
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
P mult(P x,P y)
{
	if(x.F==-1) return y;
	if(y.F==-1) return x;
    int lhs=1LL*x.F*y.F%MOD;
    int rhs=1LL*x.F*y.S%MOD;
    add(rhs,x.S);
    return make_pair(lhs,rhs);
}
struct segtree
{
    P res[4*MAXN];
    void pushup(int k)
    {
        res[k]=mult(res[k*2+1],res[k*2]);
    }
    void build(int k,int l,int r)
    {
        if(l==r)
        {
            res[k]=tmp[l];
            return;
        }
        int mid=(l+r)/2;
        build(k*2,l,mid); build(k*2+1,mid+1,r);
        pushup(k);
    }
    void update(int k,int l,int r,int pos,int x,int y)
    {
        if(l==r)
        {
            res[k]=P(x,y);
            return;
        }
        int mid=(l+r)/2;
        if(pos<=mid) update(k*2,l,mid,pos,x,y); else update(k*2+1,mid+1,r,pos,x,y);
        pushup(k);
    }
    P query(int k,int l,int r,int x,int y)
    {
        if(l>y||x>r) return P(-1,-1);
        if(l>=x&&r<=y) return res[k];
        int mid=(l+r)/2;
        return mult(query(k*2+1,mid+1,r,x,y),query(k*2,l,mid,x,y));
    }
}seg;
set<int> cp;
int main()
{
    scanf("%d%d",&n,&q);
    int inv=pow_mod(100,MOD-2);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&p[i]);
        p[i]=1LL*p[i]*inv%MOD;
    }
    cp.insert(1); cp.insert(n+1);
    for(int i=1;i<=n;i++)
    {
        int x=pow_mod(p[i],MOD-2);
        tmp[i]=(i==1?P(0,x):P(x,x));
    }
    seg.build(1,1,n);
 
    ans=seg.query(1,1,n,1,n).S;
    for(int i=0;i<q;i++)
    {
        int x;
        scanf("%d",&x);
        if(cp.count(x))
        {
        	int nxt=*cp.upper_bound(x);
        	int last=*(--cp.lower_bound(x));
        	dec(ans,seg.query(1,1,n,last,x-1).S);
        	dec(ans,seg.query(1,1,n,x,nxt-1).S);
            int val=pow_mod(p[x],MOD-2);
            seg.update(1,1,n,x,val,val);
            add(ans,seg.query(1,1,n,last,nxt-1).S);
            cp.erase(cp.find(x));
        }
        else
        {
        	int nxt=*cp.upper_bound(x);
        	int last=*(--cp.lower_bound(x));
        	dec(ans,seg.query(1,1,n,last,nxt-1).S);
            int val=pow_mod(p[x],MOD-2);
            seg.update(1,1,n,x,0,val);
            add(ans,seg.query(1,1,n,last,x-1).S);
        	add(ans,seg.query(1,1,n,x,nxt-1).S);
            cp.insert(x);
        }
        printf("%d\n",ans);
    }
    return 0;
}