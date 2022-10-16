#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int to,next,val,popu;
} edge[199999];
struct que{
	int val,popu;
	bool operator<(const que &x)const
	{
		return (val-val/2)*popu<(x.val-x.val/2)*x.popu;
	}
};
int t,n,s,ans,cnt,sum,head[100001];
priority_queue<que> q;
void add(int x,int y,int z)
{
	edge[++cnt].to=y;
	edge[cnt].val=z;
	edge[cnt].next=head[x];
	edge[cnt].popu=0;
	head[x]=cnt;
}
int dfs(int x,int fa)
{
	int tot=0;
	for(int i=head[x];i;i=edge[i].next)
		if(edge[i].to!=fa)
		{
			edge[i].popu=dfs(edge[i].to,x);
			q.push((que){edge[i].val,edge[i].popu});
			sum+=edge[i].val*edge[i].popu;
			tot+=edge[i].popu;
		}
	tot=max(tot,1ll);
	return tot;
}
signed main()
{
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld %lld",&n,&s);
		ans=cnt=sum=0;
		while(!q.empty())
			q.pop();
		memset(head,0,sizeof(head));
		for(int i=1;i<n;i++)
		{
			int a,b,c;
			scanf("%lld %lld %lld",&a,&b,&c);
			add(a,b,c);
			add(b,a,c);
		}
		dfs(1,0);
		while(sum>s)
		{
			que f=q.top();
			q.pop();
			sum-=(f.val-f.val/2)*f.popu;
			f.val/=2;
			q.push(f);
			ans++;
		}
		cout<<ans<<endl;
	}
}