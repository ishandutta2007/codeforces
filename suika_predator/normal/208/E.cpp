#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int L=1,R=100000,MAXN=111111;
struct node
{
	int cnt;
	node *lson,*rson;
}*root[MAXN],pool[MAXN<<6];
int top;
node *build(int l,int r,int pos)
{
	node *tmp=&pool[top++];
	tmp->cnt=1;
	if(l!=r)
	{
		int mid=(l+r)>>1;
		if(pos<=mid)tmp->lson=build(l,mid,pos);
		else tmp->rson=build(mid+1,r,pos);
	}
	return tmp;
}
node *merge(node *x,node *y,int l,int r)
{
	if(!x)return y;if(!y)return x;
//	cout<<"merge "<<l<<' '<<r<<' '<<x->cnt<<' '<<y->cnt<<endl;
	x->cnt+=y->cnt;
	if(l!=r)
	{
		int mid=(l+r)>>1;
		x->lson=merge(x->lson,y->lson,l,mid);
		x->rson=merge(x->rson,y->rson,mid+1,r);
	}
	return x;
}
int query(node *x,int l,int r,int pos)
{
//	cout<<"query "<<l<<' '<<r<<' '<<pos<<endl;
	if(l==r)return x->cnt;
	int mid=(l+r)>>1;
	if(pos<=mid)return query(x->lson,l,mid,pos);
	else return query(x->rson,mid+1,r,pos);
}
struct edge
{
	int v;
	edge *next;
}*h[MAXN],epool[MAXN];
int etop;
inline void addedge(int u,int v)
{
	edge *tmp=&epool[etop++];tmp->v=v;tmp->next=h[u];h[u]=tmp;
}
int n,m;
int j[17][MAXN],dep[MAXN];
void dfs(int u)
{
	for(edge *tmp=h[u];tmp;tmp=tmp->next)
		dep[tmp->v]=dep[u]+1,dfs(tmp->v);
}
inline bool cmp(const int &x,const int &y){return dep[x]==dep[y]?x<y:dep[x]>dep[y];}
int ord[MAXN];
struct qu
{
	int u,k,id;
	inline bool operator<(const qu &x)const{return dep[u]==dep[x.u]?u<x.u:dep[u]>dep[x.u];}
}q[MAXN];
int ans[MAXN];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&j[0][i]);
		if(j[0][i])addedge(j[0][i],i);
	}
	for(int l=1;l<=16;l++)
		for(int i=1;i<=n;i++)
			j[l][i]=j[l-1][j[l-1][i]];
	for(int i=1;i<=n;i++)if(!j[0][i])dep[i]=1,dfs(i);
	for(int i=1;i<=n;i++)root[i]=build(L,R,dep[i]),ord[i]=i;
	sort(ord+1,ord+n+1,cmp);
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		q[i].id=i;
		scanf("%d%d",&q[i].u,&q[i].k);
		for(int l=16;l>=0;l--)
			if(q[i].k&(1<<l))
				q[i].u=j[l][q[i].u];
	}
	sort(q+1,q+m+1);
	int cur=1;
	for(int i=1;i<=n;i++)
	{
		int u=ord[i];
		for(edge *tmp=h[u];tmp;tmp=tmp->next)
		{
//			cout<<"merge "<<u<<' '<<tmp->v<<endl;
			root[u]=merge(root[u],root[tmp->v],L,R);
		}
		while(q[cur].u==u)
		{
//			cout<<"query "<<u<<endl;
			ans[q[cur].id]=query(root[u],L,R,dep[u]+q[cur].k)-1;
			cur++;
		}
	}
	for(int i=1;i<=m;i++)printf("%d ",ans[i]);
	return 0;
}