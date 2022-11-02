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

struct tree
{
	tree *lchild,*rchild;
	int left,right;
	vector<PII> data; //pair<W,querynumber>
} *root1,*root2;

const int maxn=100005;
int N,Q,ll,rr,s;
int A[maxn],B[maxn],L[maxn],R[maxn],W[maxn],zuo[maxn],you[maxn],ans[maxn];
PII ec[maxn];

void maketree(tree *&node,int left,int right)
{
	tree *p=new tree;
	p->lchild=p->rchild=0;
	p->left=left,p->right=right;
	p->data.clear();
	node=p;
	if (left==right) return;
	maketree(node->lchild,left,(left+right)/2);
	maketree(node->rchild,(left+right)/2+1,right);
}

void pushall(tree *p,int gg,int bh,int L,int R)
{
	if (L>R) return;
	int l=p->left,r=p->right;
	if ((l==L)&&(r==R))
	{
		p->data.p_b(m_p(gg,bh));
		return;
	}
	pushall(p->lchild,gg,bh,L,min(R,p->lchild->right));
	pushall(p->rchild,gg,bh,max(p->rchild->left,L),R);
}

bool cmp(PII a,PII b)
{
	return a>b;
}
void sortall(tree *p)
{
	if (p==0) return;
	sort(p->data.begin(),p->data.end(),cmp);
	/*cout<<p->left<<" "<<p->right<<":";
	for (int i=0;i<(p->data.size());i++) cout<<(p->data[i].w2)<<" ";
	cout<<endl;*/
	sortall(p->lchild);
	sortall(p->rchild);
}

void checkans(tree *p,int place,int W,int nowans)
{
	int l=p->left,r=p->right,ec;
	if ((l>place)||(r<place)) return;
	while ((p->data.size()>0)&&(p->data[p->data.size()-1].w1<=W))
	{
		ec=p->data[p->data.size()-1].w2;
		if (ans[ec]==0) ans[ec]=nowans;
		p->data.erase(p->data.begin()+p->data.size()-1);
	}
	if (l==r) return;
	checkans(p->lchild,place,W,nowans);
	checkans(p->rchild,place,W,nowans);
}

int main()
{
	//freopen("E.in","r",stdin);
	scanf("%d",&N);
	for (int i=1;i<=N;i++) scanf("%d",&A[i]);
	maketree(root1,1,N);
	maketree(root2,1,N);
	scanf("%d",&Q);
	for (int i=1;i<=Q;i++)
	{
		scanf("%d %d %d",&L[i],&R[i],&W[i]);
		R[i]-=W[i]-1;
		pushall(root1,L[i]+W[i],i,1,L[i]);
		pushall(root2,W[i],i,L[i],R[i]);
	}
	sortall(root1);
	sortall(root2);

	memset(ans,0,sizeof(ans));
	memset(zuo,0,sizeof(zuo));
	memset(you,0,sizeof(you));
	memset(B,0,sizeof(B));
	for (int i=1;i<=N;i++) ec[i]=m_p(A[i],i);
	sort(ec+1,ec+N+1,cmp);
	for (int i=1;i<=N;i++)
	{
		s=ec[i].w2;
		ll=rr=0;
		if ((s!=1)&&(B[s-1]!=0)) ll=zuo[s-1]; else ll=s;
		if ((s!=N)&&(B[s+1]!=0)) rr=you[s+1]; else rr=s;
		zuo[rr]=ll,you[ll]=rr;
		checkans(root1,ll,rr+1,ec[i].w1);
		checkans(root2,ll,rr-ll+1,ec[i].w1);
		B[s]=1;
	}
	for (int i=1;i<=Q;i++) printf("%d\n",ans[i]);

    return 0;
}