#include<algorithm>
#include<cstdio>
#include<cstring>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define mid (l+r>>1)
#define lch (rt<<1)
#define rch (rt<<1|1)
 
using namespace std;
int n,m,x,y,Ans,id,a[100005];
struct node{int tot,val;} tree[400040],ans;
 
inline int getint()
{
    int x=0; char ch;
    while(ch=getchar(),ch<'0'||ch>'9');
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x;
}
 
int cal(int l,int r,int rt,double val)
{
    if(tree[rt].val<val)
        return 0;
    if(l==r)
        return val<tree[rt].val;
    if(tree[lch].val>val)
        return tree[rt].tot-tree[lch].tot+cal(l,mid,lch,val);
    else return cal(mid+1,r,rch,val);       
}
 
node pushup(node t1,node t2,int l,int r,int rt)
{
    node t={t1.tot+cal(l,r,rt,t1.val),max(t1.val,t2.val)};
    return t;
}
 
void modify(int l,int r,int rt)
{
    if(l==r)
    {
        tree[rt].val=y,tree[rt].tot=1;
        return;
    }
    if(x<=mid) modify(l,mid,lch);
    if(x>mid) modify(mid+1,r,rch);
    tree[rt]=pushup(tree[lch],tree[rch],mid+1,r,rch);
}

void query(int l,int r,int rt,int ql,int qr)
{
	if(ql<=l && r<=qr)
	{
		ans=pushup(ans,tree[rt],l,r,rt);
		return;
	}
	if(ql<=mid) query(l,mid,lch,ql,qr);
	if(mid<qr) query(mid+1,r,rch,ql,qr);
}

int main()
{
    n=getint();
    if(n==1) return puts("1"),0;
    rep(i,1,n) x=i,a[i]=y=getint(),modify(1,n,1); 
    rep(i,1,n)
	{
		ans=(node){0,0};
		if(i==1) query(1,n,1,2,n);
		else if(i==n) query(1,n,1,1,n-1);
		else query(1,n,1,1,i-1),query(1,n,1,i+1,n);
		if(Ans<ans.tot+1) Ans=ans.tot+1,id=a[i];
		else if(Ans==ans.tot+1) id=min(id,a[i]);
	}
	printf("%d\n",id);
    return 0;
}