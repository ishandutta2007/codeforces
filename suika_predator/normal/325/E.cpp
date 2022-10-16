#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
int n;
struct edge
{
	int v;
	edge *next;
}*h[233333],epool[233333];
int etop,cnt;
inline void addedge(int u,int v)
{
	edge *tmp=&epool[etop++];tmp->v=v;tmp->next=h[u];h[u]=tmp;cnt++;
}
struct node
{
	int id;
	node *next;
}*root,pool[233333];
int top;
node *pos[233333];
queue<int> q;
node* dfs(int r,int x)
{
//	cout<<"dfs "<<r<<' '<<x<<endl;
	node *ret=&pool[top++];
	if(!pos[x])
	{
		pos[x]=ret;
		q.push(x);
	}
	ret->id=x;
	if(x==r)return ret;
	edge *nx=h[x];h[x]=h[x]->next;
	cnt--;
	ret->next=dfs(r,nx->v);
	return ret;
}
int ord[233333];
inline void solve()
{
	root=&pool[top++];
	root->id=0;
	pos[0]=root;
	q.push(0);
	while(!q.empty())
	{
		int x=q.front();q.pop();
		while(h[x])
		{
			edge *nx=h[x];h[x]=h[x]->next;
			node *tmp=dfs(x,nx->v);
			node *ed=tmp;
			while(ed->next)ed=ed->next;
			ed->next=pos[x]->next;
			pos[x]->next=tmp;
		}
	}
	node *cur=root;
	int i=0;
	while(cur)
	{
//		cout<<cur->id<<endl;
		ord[i++]=cur->id;
		cur=cur->next;
	}
}
int main()
{
	scanf("%d",&n);
	if(n==1)
	{
		printf("0 0\n");
		return 0;
	}
	if(n==2)
	{
		printf("0 1 0\n");
		return 0;
	}
	if(n%2==1)
	{
		printf("-1\n");
		return 0;
	}
	n/=2;
	for(int i=0;i<n;i++)
	{
		addedge(i,i*2%n);
		addedge(i,(i*2+1)%n);
	}
	solve();
	ord[2*n+1]=0;
	for(int i=0;i<=2*n;i++)
	{
		if(ord[i+1]==(ord[i]*2)%n)printf("%d ",ord[i]*2);
		else printf("%d ",ord[i]*2+1);
	}
	return 0;
}