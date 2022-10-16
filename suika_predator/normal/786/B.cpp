#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
const long long inf=0x3f3f3f3f3f3f3f3fll;
struct node
{
	int l,r,minp,del,used;
	long long minn,maxx;//maxx = qu jian qu min biao ji
	vector<int> cov;
	node *lson,*rson;
	inline void upd()
	{
		del=lson->del&&rson->del;
		if((!lson->del&&lson->minn<rson->minn)||rson->del)minn=lson->minn,minp=lson->minp;
		else minn=rson->minn,minp=rson->minp;
	}
	inline void mark(long long x){maxx=min(maxx,x);minn=min(minn,x);}
	inline void fa_lazy(){lson->mark(maxx);rson->mark(maxx);}
}*root,pool[233333];
int top;
int vis[233333];
node *build(int l,int r)
{
	node *tmp=&pool[top++];tmp->l=l;tmp->r=r;
	tmp->minp=l;tmp->minn=tmp->maxx=inf;
	if(l!=r)
	{
		int mid=(l+r)>>1;
		tmp->lson=build(l,mid);
		tmp->rson=build(mid+1,r);
	}
	return tmp;
}
void add(node *cur,int l,int r,int id)
{
	if(cur->l==l&&cur->r==r)
	{
		cur->cov.push_back(id);
		return;
	}
	if(cur->lson->r>=r)add(cur->lson,l,r,id);
	else if(cur->rson->l<=l)add(cur->rson,l,r,id);
	else add(cur->lson,l,cur->lson->r,id),add(cur->rson,cur->rson->l,r,id);
}
void change(node *cur,int l,int r,long long x)
{
//	cout<<"change "<<cur->l<<' '<<cur->r<<' '<<l<<' '<<r<<' '<<x<<endl;
	if(cur->del)return;
	if(cur->l==l&&cur->r==r)
	{
		cur->mark(x);
		return;
	}
	cur->fa_lazy();
	if(cur->lson->r>=r)change(cur->lson,l,r,x);
	else if(cur->rson->l<=l)change(cur->rson,l,r,x);
	else change(cur->lson,l,cur->lson->r,x),change(cur->rson,cur->rson->l,r,x);
	cur->upd();
}
long long query(node *cur,int pos)
{
	if(cur->l==cur->r)return cur->minn;
	cur->fa_lazy();
	if(pos<=cur->lson->r)return query(cur->lson,pos);
	else return query(cur->rson,pos);
}
struct edge2
{
	int l,r,x,w;
}e[233333];
long long dis[233333];
void del(node *cur,int pos)
{
//	cout<<"del "<<cur->l<<' '<<cur->r<<' '<<pos<<endl;
	if(!cur->used)
	{
		cur->used=1;
		for(auto x:cur->cov)
		{
			if(!vis[x])
			{
				vis[x]=1;
				change(root,e[x].x,e[x].x,dis[pos]+e[x].w);
			}
		}
	}
	if(cur->l==cur->r)
	{
		cur->del=1;
		return;
	}
	cur->fa_lazy();
	if(cur->lson->r>=pos)del(cur->lson,pos);
	else del(cur->rson,pos);
	cur->upd();
//	cout<<cur->l<<' '<<cur->r<<' '<<cur->minn<<endl;
}
struct edge
{
	int l,r,w;
	edge *next;
}*h[233333],epool[233333];
int etop;
inline void addedge(int u,int l,int r,int w)
{
	edge *tmp=&epool[etop++];tmp->l=l;tmp->r=r;tmp->w=w;tmp->next=h[u];h[u]=tmp;
}
int main()
{
	int n,m,s;
	scanf("%d%d%d",&n,&m,&s);
	root=build(1,n);
	memset(dis,0x3f,sizeof(dis));
	int ty,x,l,r,w;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&ty,&x);
		if(ty==1)
		{
			scanf("%d%d",&r,&w);
			addedge(x,r,r,w);
		}
		else if(ty==2)
		{
			scanf("%d%d%d",&l,&r,&w);
			addedge(x,l,r,w);
		}
		else
		{
			scanf("%d%d%d",&l,&r,&w);
			e[i].l=l;e[i].r=r;e[i].w=w;e[i].x=x;
			add(root,l,r,i);
		}
	}
	change(root,s,s,0);
	while(!root->del)
	{
		int u=root->minp;
//		cout<<u<<endl;
		dis[u]=query(root,u);
		if(dis[u]==inf)break;
		del(root,u);//also update interval->point edges
		for(edge *tmp=h[u];tmp;tmp=tmp->next)
		{
			change(root,tmp->l,tmp->r,dis[u]+tmp->w);
		}
	}
	for(int i=1;i<=n;i++)
	{
		printf("%lld ",dis[i]==inf?-1:dis[i]);
	}
	return 0;
}