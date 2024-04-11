#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <set>
#include <utility>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int,int> PII;
typedef pair<int,PII> PIII;

#define LL long long
#define ULL unsigned long long
#define m_p make_pair
#define l_b lower_bound
#define p_b push_back
#define w1 first
#define w2 second
#define maxlongint 2147483647
#define biglongint 2139062143

const int P1=1000000007,P2=1000000009,base=987654323;
const int maxn=100005;

struct tree
{
	tree *lchild,*rchild;
	int left,right,hash1,hash2,delta,len;
} *root;

int N,Q1,Q2,Q,flag,xc,yc,zc,qzl,qzr,hh1,hh2;
int powc1[maxn],powc2[maxn],F[10][maxn],G[10][maxn];
char st[maxn];

void update(tree *p)
{
	p->hash1=((LL)p->lchild->hash1*powc1[p->rchild->len]+p->rchild->hash1)%P1;
	p->hash2=((LL)p->lchild->hash2*powc2[p->rchild->len]+p->rchild->hash2)%P2;
}

void downit(tree *p)
{
	if (p->delta!=-1)
	{
		if (p->lchild!=0)
		{
			p->lchild->delta=p->rchild->delta=p->delta;
			p->lchild->hash1=F[p->delta][p->lchild->len];
			p->lchild->hash2=G[p->delta][p->lchild->len];
			p->rchild->hash1=F[p->delta][p->rchild->len];
			p->rchild->hash2=G[p->delta][p->rchild->len];
		}
		p->delta=-1;
	}
}

void maketree(tree *&node,int l,int r)
{
	tree *p=new tree;
	p->lchild=p->rchild=0;
	p->left=l,p->right=r,p->len=r-l+1;
	p->hash1=p->hash2=0;
	p->delta=-1;
	node=p;
	if (l==r)
		p->hash1=p->hash2=st[l]-48;
	else
	{
		maketree(node->lchild,l,(l+r)/2);
		maketree(node->rchild,(l+r)/2+1,r);
		update(node);
	}
}

void shua(tree *p)
{
	int l=p->left,r=p->right;
	if ((l>yc)||(r<xc)) return;
	downit(p);
	if ((l==xc)&&(r<=yc))
	{
		xc=r+1;
		p->delta=zc;
		p->hash1=F[zc][p->len];
		p->hash2=G[zc][p->len];
		downit(p);
	}
	else
	{
		shua(p->lchild);
		shua(p->rchild);
		update(p);
	}
}

void dfs2(tree *p)
{
	int l=p->left,r=p->right;
	if ((l>qzr)||(r<qzl)) return;
	downit(p);
	if ((l==qzl)&&(r<=qzr))
	{
		qzl=r+1;
		hh1=((LL)hh1*powc1[p->len]+p->hash1)%P1;
		hh2=((LL)hh2*powc2[p->len]+p->hash2)%P2;
	}
	else
	{
		dfs2(p->lchild);
		dfs2(p->rchild);
		update(p);
	}
}

PII getans(int L,int R)
{
	qzl=L,qzr=R,hh1=hh2=0;
	dfs2(root);
	return m_p(hh1,hh2);
}

int main()
{
	//freopen("E.in","r",stdin);

	powc1[0]=powc2[0]=1;
	for (int i=1;i<maxn;i++) powc1[i]=(LL)powc1[i-1]*base%P1,powc2[i]=(LL)powc2[i-1]*base%P2;
	memset(F,0,sizeof(F));
	memset(G,0,sizeof(G));
	for (int i=1;i<=9;i++)
	{
		F[i][1]=i;
		G[i][1]=i;
		for (int j=2;j<maxn;j++)
			F[i][j]=((LL)F[i][j-1]*base+i)%P1,
			G[i][j]=((LL)G[i][j-1]*base+i)%P2;
	}

	scanf("%d %d %d",&N,&Q1,&Q2);
	Q=Q1+Q2;
	scanf("%s",st+1);
	maketree(root,1,N);
	for (int i=1;i<=Q;i++)
	{
		scanf("%d %d %d %d",&flag,&xc,&yc,&zc);
		if (flag==1)
			shua(root);
		else
		{
			PII ans1=getans(xc,yc-zc),ans2=getans(xc+zc,yc);
			//cout<<ans1.w1<<" "<<ans1.w2<<"    "<<ans2.w1<<" "<<ans2.w2<<endl;
			if (ans1==ans2) printf("YES\n"); else printf("NO\n");
		}
		//cout<<root->hash1<<" "<<root->hash2<<endl;
	}

    return 0;
}