#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <cstdlib>

using namespace std;

const int maxn=100005;

char s[maxn],ch;
int n,k,ct,flag,csum,nowsum;
int xc[maxn],yc[maxn],ans[maxn],times[27],appear[27];

struct tree
{
	int left,right,sum,flag,len;
	tree *lchild,*rchild;
} *root[27];

class segmenttree
{
	private:
	int lc,rc,ff,sum;
	
	void downit(tree *p)
	{
		if (p->flag!=-1)
		{
			if (p->lchild!=0)
			{
				p->lchild->sum=p->lchild->len*p->flag;
				p->rchild->sum=p->rchild->len*p->flag;
				p->lchild->flag=p->flag;
				p->rchild->flag=p->flag;
			}
			p->flag=-1;
		}
	}
	
	void update(tree *p)
	{
		if (p->lchild!=0)
			p->sum=p->lchild->sum+p->rchild->sum;
	}
	
	void dfs1(tree *p)
	{
		downit(p);
		if ((p->left>rc)||(p->right<lc)) return;
		if ((p->left==lc)&&(p->right<=rc))
		{
			p->flag=ff;
			p->sum=ff*p->len;
			downit(p);
			lc=p->right+1;
		}
		else
		{
			dfs1(p->lchild);
			dfs1(p->rchild);
			update(p);
		}
	}
	
	void dfs2(tree *p)
	{
		if ((p->left>rc)||(p->right<lc)) return;
		downit(p);
		if ((p->left==lc)&&(p->right<=rc))
		{
			sum+=p->sum;
			lc=p->right+1;
		}
		else
		{
			dfs2(p->lchild);
			dfs2(p->rchild);
			update(p);
		}
	}
	
	void dfs3(tree *p)
	{
		downit(p);
		if (p->left==p->right)
		{
			if (p->sum==1) ans[p->left]=ff;
		}
		else
		{
			dfs3(p->lchild);
			dfs3(p->rchild);
		}
	}
	
	public:
	void maketree(tree *&node,int left,int right)
	{
		tree *p;
		p=new tree;
		p->lchild=0;p->rchild=0;
		p->left=left;p->right=right;
		p->sum=0;p->flag=-1;p->len=right-left+1;
		node=p;
		if (left==right) return;
		maketree(node->lchild,left,(left+right)/2);
		maketree(node->rchild,(left+right)/2+1,right);
	}
	
	void incert(tree *node,int left,int right,int num)
	{
		lc=left;rc=right;ff=num;
		dfs1(node);
	}
	
	int getsum(tree *node,int left,int right)
	{
		lc=left;rc=right;sum=0;
		dfs2(node);
		return sum;
	}
	
	void downall(tree *node,int num)
	{
		ff=num;
		dfs3(node);
	}
};

int main()
{
	//freopen("F.in","r",stdin);
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d %d",&n,&k);
	scanf("%c",&ch);
	for (int i=1;i<=n;i++) scanf("%c",&s[i]);
	for (int i=1;i<=k;i++)
		scanf("%d %d",&xc[i],&yc[i]);
	segmenttree Q[27];
	for (int i=1;i<=26;i++) Q[i].maketree(root[i],1,n);
	memset(appear,0,sizeof(appear));
	for (int i=1;i<=n;i++)
	{
		ct=s[i]-96;
		Q[ct].incert(root[ct],i,i,1);
		appear[ct]=1;
	}
	for (int i=1;i<=k;i++)
	{
		flag=0;
		memset(times,0,sizeof(times));
		for (int j=1;j<=26;j++)
		{
			if (appear[j]==0) continue;
			csum=Q[j].getsum(root[j],xc[i],yc[i]);
			if (csum%2==1)
			{
				if (flag==0) flag=j; else
				{
					flag=-1;break;
				}
				--csum;
			}
			times[j]=csum;
		}
		if (flag!=-1)
		{
			for (int j=1;j<=26;j++)
				if ((times[j]!=0)||(j==flag)) Q[j].incert(root[j],xc[i],yc[i],0);
			for (int j=1;j<=26;j++)
				if (times[j]!=0)
 				{
 					Q[j].incert(root[j],xc[i],xc[i]+times[j]/2-1,1);
 					Q[j].incert(root[j],yc[i]-times[j]/2+1,yc[i],1);
 					xc[i]+=times[j]/2;
 					yc[i]-=times[j]/2;
 					//cout<<xc[i]<<" "<<yc[i]<<endl;
				}
			if (xc[i]==yc[i]) Q[flag].incert(root[flag],xc[i],yc[i],1);
		}
	}
	
	memset(ans,0,sizeof(ans));
	for (int i=1;i<=26;i++) Q[i].downall(root[i],i);
	for (int i=1;i<=n;i++) printf("%c",ans[i]+96);
	printf("\n");
		
	return 0;
}