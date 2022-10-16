#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
const int N=2e5+5;
int n,m,qr,o;
int u,v;
struct q
{
	priority_queue <int,vector<int>,greater<int> > q,dq;
	void ins(int v)
	{
		q.push(v);
	}
	void relax()
	{
		while ((!q.empty())&&(!dq.empty())&&q.top()==dq.top())
		{
			q.pop();
			dq.pop();
		}
	}
	void del(int v)
	{
		dq.push(v);
	}
	bool empty()
	{
		relax();
		return q.empty();
	}
	int top()
	{
		relax();
		return q.top();
	}
};
q f[N];
int ans;
bool c[N];
void ae(int u,int v)
{
	if (u>v)
		swap(u,v);
	f[u].ins(v);
	ans-=c[u];
	c[u]=f[u].top()<u;
	ans+=c[u];
}
void dae(int u,int v)
{
	if (u>v)
		swap(u,v);
	f[u].del(v);
	ans-=c[u];
	if (f[u].empty())
		c[u]=1;
	else
		c[u]=f[u].top()<u;
	ans+=c[u];
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
		c[i]=1;
	ans=n;
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d",&u,&v);
		ae(u,v);
	}
	scanf("%d",&qr);
	while (qr--)
	{
		scanf("%d",&o);
		if (o==3)
		{
			printf("%d\n",ans);
			continue;
		}
		scanf("%d%d",&u,&v);
		if (o==1)
			ae(u,v);
		else
			dae(u,v);
	}
	return 0;
}