#include<bits/stdc++.h>
using namespace std;
struct node
{
	int l,r;
	unsigned long long val;
	node *lson,*rson;
	void upd(){val=lson->val^rson->val;}
}*root[333333],pool[23333333];
int top;
unsigned long long w[333333];
int a[333333];
node* copy(node *pre)
{
	node *ret=&pool[top++];
	ret->l=pre->l;ret->r=pre->r;
	ret->val=pre->val;
	ret->lson=pre->lson;ret->rson=pre->rson;
	return ret;
}
node *build(int l,int r)
{
	node *ret=&pool[top++];ret->l=l;ret->r=r;ret->val=0;
	if(l!=r)
	{
		int mid=(l+r)/2;
		ret->lson=build(l,mid);
		ret->rson=build(mid+1,r);
	}
	return ret;
}
node *change(node *pre,int pos,unsigned long long x)
{
	node *ret=copy(pre);
	if(ret->l==ret->r)
	{
		ret->val^=x;
		return ret;
	}
	if(ret->lson->r>=pos)ret->lson=change(pre->lson,pos,x);
	else ret->rson=change(pre->rson,pos,x);
	ret->upd();
	return ret;
}
int ans;
unsigned long long query(node *A,node *B,node *C,node *D,int l,int r)
{
	if(A->l==l&&A->r==r)
	{
		unsigned long long val=A->val^B->val^C->val^D->val;
		if(val==0)return val;
		else
		{
			if(l==r)
			{
				ans=l;
				return val;
			}
			val=query(A->lson,B->lson,C->lson,D->lson,l,A->lson->r);
			if(val!=0)return val;
			else return query(A->rson,B->rson,C->rson,D->rson,A->rson->l,r);
		}
	}
	if(A->lson->r>=r)return query(A->lson,B->lson,C->lson,D->lson,l,r);
	else if(A->rson->l<=l)return query(A->rson,B->rson,C->rson,D->rson,l,r);
	else
	{
		unsigned long long val=query(A->lson,B->lson,C->lson,D->lson,l,A->lson->r);
		if(val==0)return query(A->rson,B->rson,C->rson,D->rson,A->rson->l,r);
		else return val;
	}
}
struct edge
{
	int v;
	edge *next;
}*h[333333],epool[777777];
int etop;
inline void addedge(int u,int v)
{
	edge *tmp=&epool[etop++];tmp->v=v;tmp->next=h[u];h[u]=tmp;
	edge *pmt=&epool[etop++];pmt->v=u;pmt->next=h[v];h[v]=pmt;
}
int pa[333333],dep[333333];
void dfs(int u)
{
	root[u]=change(root[pa[u]],a[u],w[a[u]]);
	for(edge *tmp=h[u];tmp;tmp=tmp->next)
	{
		if(!dep[tmp->v])
		{
			dep[tmp->v]=dep[u]+1;
			pa[tmp->v]=u;
			dfs(tmp->v);
		}
	}
}
int T,n,q;
int jmp[333333][19];
void initlca()
{
	for(int i=1;i<=n;i++)jmp[i][0]=pa[i];
	for(int j=1;j<=18;j++)
	{
		for(int i=1;i<=n;i++)
		{
			jmp[i][j]=jmp[jmp[i][j-1]][j-1];
		}
	}
}
int lca(int u,int v)
{
	if(dep[u]>dep[v])swap(u,v);
	for(int j=18;j>=0;j--)
	{
		if(dep[v]-(1<<j)>=dep[u])
			v=jmp[v][j];
	}
	for(int j=18;j>=0;j--)
	{
		if(jmp[v][j]!=jmp[u][j])
			v=jmp[v][j],u=jmp[u][j];
	}
	while(u!=v)u=pa[u],v=pa[v];
	return u;
}
mt19937_64 ran;
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		w[i]=ran();
		cin>>a[i];
	}
	int x,y,l,r;
	for(int i=1;i<n;i++)
	{
		cin>>x>>y;
		addedge(x,y);
	}
	root[0]=build(1,n);
	dep[1]=1;
	dfs(1);
	initlca();
	for(int tt=1;tt<=q;tt++)
	{
		cin>>x>>y>>l>>r;
		int z=lca(x,y),p=pa[z];
		ans=-1;
		query(root[x],root[y],root[z],root[p],l,r);
		cout<<ans<<endl;
	}
	return 0;
}