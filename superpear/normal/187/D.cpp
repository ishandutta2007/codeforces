#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <iostream>

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

const int maxnc=100005;
const int maxlongint=2147483647;

int dis[maxnc];
LL need[maxnc],sum[maxnc];
int n,green,red,maxn,nowl,nowr,move,cs,ut,move1,tt,cc,eq,oo;
LL nowans;

struct tree
{
	int where;
	short flag;
	tree *lchild,*rchild;	
} *root,*null,*nc[7000001];

class segmenttree
{
	private:
	int left,right,place,ans;
	
	void makenew(tree *&node)
	{
		++oo;
		node=nc[oo];
		node->where=0;
		node->lchild=null;
		node->rchild=null;		
		++eq;
	}
	void downit(tree *p)
	{
		if (p->lchild==null) makenew(p->lchild);
		if (p->rchild==null) makenew(p->rchild);
		if (p->flag==1)
		{
			p->lchild->flag=1;
			p->rchild->flag=1;
			p->lchild->where=p->where;
			p->rchild->where=p->where;
			p->flag=0;
		}
	}
	void update(tree *p)
	{
		if (p->lchild->where<p->rchild->where)
			p->where=p->lchild->where;
		else
			p->where=p->rchild->where;
	}
	void doit1(tree *&node,int l,int r)
	{
		//cout<<l<<" "<<r<<" "<<left<<" "<<right<<endl;
		if ((l>right)||(r<left)) return;
		if (left>right) return;
		if (node==null) makenew(node);
		if (l!=r) downit(node);
		if ((l==left)&&(r<=right))
		{
			node->where=place;
			node->flag=1;
			if (l!=r) downit(node);
			left=r+1;
		}
		else
		{
			doit1(node->lchild,l,(l+r)/2);
			doit1(node->rchild,(l+r)/2+1,r);
			if (l!=r) update(node);
		}
	}
	void doit2(tree *p,int l,int r)
	{
		if (p==null) return;
		if ((l>place)||(r<place)) return;
		if ((p->lchild==null)&&(p->rchild==null))
		{
			ans=p->where;
			return;
		}
		if (l!=r) downit(p);
		if (l==r)
			ans=p->where;
		else
		{
			doit2(p->lchild,l,(l+r)/2);
			doit2(p->rchild,(l+r)/2+1,r);
			update(p);
		}
	}
	
	public:
	void insert(int l,int r,int inplace)
	{
		place=inplace;
		if (l<=r)
		{
			left=l;right=r;
			doit1(root,0,maxn);
		}
		else
		{
			left=0;right=r;
			doit1(root,0,maxn);
			left=l;right=maxn;
			doit1(root,0,maxn);
		}
	}
	int getmin(int inplace)
	{
		place=inplace;
		ans=0;
		doit2(root,0,maxn);
		return ans;
	}
} Q;

int main()
{
	for (int i=1;i<=7000000;i++) nc[i]=new tree;
	oo=1;
	
	null=new tree;
	null->lchild=null;null->rchild=null;
	null->where=maxlongint;
//	freopen("D.in","r",stdin);
//	freopen("D.out","w",stdout);
	eq=0;
	scanf("%d %d %d",&n,&green,&red);
	maxn=green+red-1;
	memset(sum,0,sizeof(sum));
	sum[0]=0;
	for (int i=0;i<=n;i++) scanf("%d",&dis[i]);
	for (int i=1;i<=n;i++) sum[i]=sum[i-1]+(LL)dis[i-1];
		
	root=new tree;
	root->lchild=null;root->rchild=null;
	root->where=maxlongint;
	
	need[n+1]=0;
	need[n]=dis[n];
	nowl=green;nowr=maxn;
	move=0;
	for (int i=n-1;i>=1;i--)
	{
		Q.insert(nowl,nowr,i+1);
		nowl=(nowl+dis[i])%(maxn+1);
		nowr=(nowr+dis[i])%(maxn+1);
		move=(move+dis[i])%(maxn+1);		
		cs=Q.getmin(move);
		if (cs==0) 
		{
			need[i]=need[n]+(sum[n]-sum[i]);
		}
		else
		{
			ut=(sum[cs]-sum[i])%(maxn+1);
			need[i]=(LL)need[cs]+(sum[cs]-sum[i])+(maxn+1-ut);
		}
	}
	Q.insert(nowl,nowr,1);
	move1=move;
	scanf("%d",&tt);
	for (int gb=1;gb<=tt;gb++)
	{
		scanf("%d",&cc);
		move=((move1+dis[0])%(maxn+1)+cc)%(maxn+1);
		cs=Q.getmin(move);
		if (cs==0) nowans=(LL)need[n]+sum[n]+cc;
		else
		{
			ut=(sum[cs]+cc)%(maxn+1);
			nowans=(LL)need[cs]+sum[cs]+cc+(maxn+1-ut);
		}
		cout<<nowans<<endl;
	}
	//cout<<eq<<endl;
	
	return 0;
}