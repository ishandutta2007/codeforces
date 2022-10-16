#include<bits/stdc++.h>//2
using namespace std;
struct node{
	int to,next;
} edge[199999];
double ans;
int n,cnt,dep[100001],head[100001];
void add(int x,int y)
{
	edge[++cnt].to=y;
	edge[cnt].next=head[x];
	head[x]=cnt;
}
void dfs(int x,int f)
{
    dep[x]=dep[f]+1;
    for(int i=head[x];i;i=edge[i].next)
	{
        if(edge[i].to==f)continue;
        dfs(edge[i].to,x);
    }
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		add(a,b);
		add(b,a);
	}
	dep[1]=1;
	dfs(1,0);
	for(int i=1;i<=n;i++)
		ans+=1.0/dep[i];
	cout.setf(ios::fixed);
	cout.precision(9);
	cout<<ans;
	return 0;
}