#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int to,next;
} edge[399999];
int n,k,ans,cnt,dep[200001],size[200001],head[200001];
vector<int> v;
void add(int x,int y)
{
	edge[++cnt].to=y;
	edge[cnt].next=head[x];
	head[x]=cnt;
}
int dfs(int x,int fa)
{
	size[x]=1;
	for(int i=head[x];i;i=edge[i].next)
		if(edge[i].to!=fa)
		{
			dep[edge[i].to]=dep[x]+1;
			size[x]+=dfs(edge[i].to,x);
		}
	return size[x];
}
bool cmp(int x,int y)
{
	return x>y;
}
signed main()
{
	scanf("%lld %lld",&n,&k);
	for(int i=1;i<n;i++)
	{
		int x,y;
		scanf("%lld %lld",&x,&y);
		add(x,y);
		add(y,x);
	}
	dep[1]=1;
	dfs(1,0);
	for(int i=1;i<=n;i++)
		v.push_back(dep[i]-size[i]);
	sort(v.begin(),v.end(),cmp);
	for(int i=0;i<k;i++)
		ans+=v[i];
	cout<<ans;
	return 0;	
}