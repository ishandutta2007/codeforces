#include<bits/stdc++.h>
using namespace std;
struct edge
{
	int v;
	edge *next;
}*h[233333],pool[555555];
int top;
inline void addedge(int u,int v)
{
	edge *tmp=&pool[top++];tmp->v=v;tmp->next=h[u];h[u]=tmp;
	edge *pmt=&pool[top++];pmt->v=u;pmt->next=h[v];h[v]=pmt;
}
int n,m,k,x,y;
int dis[233333],dis2[233333],vis[233333];
queue<int> q;
struct node
{
	int l,r,maxx;
	node *lson,*rson;
}*root,npool[555555];
int ntop;
node *build(int l,int r)
{
	node *tmp=&npool[ntop++];
	tmp->l=l;tmp->r=r;
	tmp->maxx=-0x3f3f3f3f;
	if(l!=r)
	{
		int mid=(l+r)/2;
		tmp->lson=build(l,mid);
		tmp->rson=build(mid+1,r);
	}
	return tmp;
}
void change(node *cur,int pos,int w)
{
	cur->maxx=max(cur->maxx,w);
	if(cur->l==cur->r)
	{
		return;
	}
	if(pos<=cur->lson->r)change(cur->lson,pos,w);
	else change(cur->rson,pos,w);
}
int query(node *cur,int l,int r)
{
//	cerr<<"query "<<cur->l<<' '<<cur->r<<' '<<l<<' '<<r<<endl;
	if(cur->l>=l&&cur->r<=r)return cur->maxx;
	int ret=-0x3f3f3f3f;
	if(l<=cur->lson->r)ret=max(ret,query(cur->lson,l,r));
	if(r>=cur->rson->l)ret=max(ret,query(cur->rson,l,r));
	return ret;
}
int sp[233333];
inline bool chk(int w)
{
	w--;
	ntop=0;
	root=build(0,n);
	for(int i=1;i<=k;i++)
	{
		int qwq=query(root,max(w-dis2[sp[i]],0),n);
		if(qwq+dis[sp[i]]>=w)return true;;
		change(root,dis[sp[i]],dis2[sp[i]]);
	}
	return false;
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&sp[i]);
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		addedge(x,y);
	}
	q.push(1);vis[1]=1;
	while(!q.empty())
	{
		int u=q.front();q.pop();
		for(edge *tmp=h[u];tmp;tmp=tmp->next)
		{
			if(!vis[tmp->v])
			{
				dis[tmp->v]=dis[u]+1;
				q.push(tmp->v);vis[tmp->v]=1;
			}
		}
	}
	memset(vis,0,sizeof(vis));
	q.push(n);vis[n]=1;
	while(!q.empty())
	{
		int u=q.front();q.pop();
		for(edge *tmp=h[u];tmp;tmp=tmp->next)
		{
			if(!vis[tmp->v])
			{
				dis2[tmp->v]=dis2[u]+1;
				q.push(tmp->v);vis[tmp->v]=1;
			}
		}
	}
//	for(int i=1;i<=n;i++)cerr<<i<<' '<<dis[i]<<' '<<dis2[i]<<endl;
	int ans=dis[n];
	int l=1,r=ans;
	while(l<r)
	{
		int mid=(l+r+1)/2;
		if(chk(mid))l=mid;
		else r=mid-1;
	}
	cout<<l<<endl;
	return 0;
}