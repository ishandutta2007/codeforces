#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

#define LL long long
#define maxlongint 2147483647

struct four
{
	double dis;
	int m,p,r;
} f[300000];

struct tree
{
	tree *lchild,*rchild;
	int left,right,min,where;
} *root;

int qleft,qright;
pair<int,int> qc;
int xf,yf,pq,rq,n,xc,yc,mi,pi,ri,rc,fc,nowp;
int u[300000];
double nowr;

bool cmp(const four &a,const four &b)
{
	return a.dis<b.dis;
}

void maketree(tree *&node,int left,int right)
{
	tree *p;
	p=new tree;
	p->lchild=0;
	p->rchild=0;
	p->left=left;
	p->right=right;
	node=p;
	if (left==right)
	{
		p->min=f[left].m;
		p->where=left;
	}
	else
	{
		maketree(node->lchild,left,(left+right)/2);
		maketree(node->rchild,(left+right)/2+1,right);
		if (p->lchild->min<p->rchild->min)
		{
			p->min=p->lchild->min;
			p->where=p->lchild->where;
		}
		else
		{
			p->min=p->rchild->min;
			p->where=p->rchild->where;
		}
	}
}

void search(tree *p)
{
	int l,r;
	l=p->left;r=p->right;
	if ((l>qright)||(r<qleft)) return;
	if ((l==qleft)&&(r<=qright))
	{
		if (p->min<qc.first)
			qc=make_pair(p->min,p->where);
		qleft=r+1;
	}
	else
	{
		search(p->lchild);
		search(p->rchild);
	}	
}
void getmin(int left,int right)
{
	qleft=left;qright=right;
	search(root);
}

void erase(tree *p,int place)
{
	int l,r;
	l=p->left;r=p->right;
	if ((l>place)||(r<place)) return;
	if (l==r)
	{
		p->min=maxlongint;
	}
	else
	{
		erase(p->lchild,place);
		erase(p->rchild,place);
		if (p->lchild->min<p->rchild->min)
		{
			p->min=p->lchild->min;
			p->where=p->lchild->where;
		}
		else
		{
			p->min=p->rchild->min;
			p->where=p->rchild->where;
		}
	}
}

int main()
{
	//freopen("E.in","r",stdin);
	scanf("%d %d %d %d %d",&xf,&yf,&pq,&rq,&n);
	f[0].p=pq;f[0].r=rq;
	for (int i=1;i<=n;i++)
	{
		scanf("%d %d %d %d %d",&xc,&yc,&mi,&pi,&ri);
		f[i].dis=sqrt((LL)(xc-xf)*(xc-xf)+(LL)(yc-yf)*(yc-yf));
		f[i].m=mi;f[i].p=pi;f[i].r=ri;
	}
	sort(f+1,f+n+1,cmp);
	maketree(root,1,n);
	rc=1;fc=1;u[rc]=0;
	while (rc<=fc)
	{
		nowr=f[u[rc]].r;
		nowp=f[u[rc]].p;
		//cout<<nowr<<" "<<nowp<<endl;
		while (true)
		{
			int left,right,mid;
			left=1;right=n;
			while (left<=right)
			{
				mid=(left+right)/2;
				if (f[mid].dis<=nowr) left=mid+1; else right=mid-1;
			}
			qc=make_pair(maxlongint,0);
			getmin(1,right);
			if (qc.first>nowp) break;
			++fc;
			u[fc]=qc.second;
			erase(root,qc.second);
		}
		++rc;
	}	
	cout<<fc-1<<endl;		
	
	return 0;
}