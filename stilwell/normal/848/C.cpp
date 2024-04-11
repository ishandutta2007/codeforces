#include <stdio.h>
#include <stdlib.h>
#include <set>
using namespace std;

bool st;

int n,m,i,j,k,w,aim,val,opt,ll,rr,u,v;
int A_[100005],B[100005],C[100005];
int a[200005],l[200005],r[200005];
long long ans;
bool use[100005];

set<int> S[100005];

struct node
{
	int l,r;
	long long sum;
}t[14000005];
int root[100005],tot;

bool en;

void A(int &x,int l,int r)
{
	if(!x)x=++tot;
	t[x].sum+=val;
	if(l==r)return;
	int mid=l+r>>1;
	if(aim<=mid)A(t[x].l,l,mid);
	else A(t[x].r,mid+1,r);
}

void Ins(int i,int op)
{
	if(r[i]>n||i==0)return;
	aim=r[i];val=(r[i]-i)*op;
	for(j=i;j<=n;j+=j&-j)A(root[j],1,n);
}

void Q(int x,int l,int r)
{
	if(!x)return;
	if(l>=ll&&r<=rr)
	{
		ans+=t[x].sum;
		return;
	}
	int mid=l+r>>1;
	if(rr<=mid)Q(t[x].l,l,mid);
	else if(ll>mid)Q(t[x].r,mid+1,r);
		else Q(t[x].l,l,mid),Q(t[x].r,mid+1,r);
}

int main()
{
	
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i)scanf("%d",&a[i]);
	for(i=1;i<=n;++i)S[i].insert(n+i);
	for(i=1;i<=n;++i)S[a[i]].insert(i);
	for(i=1;i<=n;++i)
	{
		k=*S[a[i]].lower_bound(i+1);
		r[i]=k;l[k]=i;
	}
	
	for(i=1;i<=m;++i)
	{
		scanf("%d%d%d",&A_[i],&B[i],&C[i]);
		if(A_[i]==2)
		{
			for(j=B[i]-1;j;j-=j&-j)use[j]=true;
			for(j=C[i];j;j-=j&-j)use[j]=true;
		}
	}
	for(i=1;i<=n;++i)Ins(i,1);
	
	for(w=1;w<=m;++w)
	{
		//scanf("%d",&opt);
		//scanf("%d%d",&u,&v);	
		opt=A_[w];u=B[w];v=C[w];
		if(opt==1)
		{
			Ins(u,-1);
			if(l[u]!=0)
			{
				Ins(l[u],-1);
				r[l[u]]=r[u];
				Ins(l[u],1);
			}
			l[r[u]]=l[u];
			
			S[a[u]].erase(u);
			a[u]=v;
			S[a[u]].insert(u);
			k=*S[a[u]].lower_bound(u+1);
			if(l[k]!=0)
			{
				Ins(l[k],-1);
				r[l[k]]=u;
				Ins(l[k],1);
			}
			l[u]=l[k];l[k]=u;r[u]=k;
			Ins(u,1);
		}
		else
		{
			ans=0;ll=1;rr=v;
			for(i=u-1;i;i-=i&-i)Q(root[i],1,n);
			ans=-ans;
			for(i=v;i;i-=i&-i)Q(root[i],1,n);
			printf("%I64d\n",ans);
		}
	}
}