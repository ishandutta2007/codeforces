#include<bits/stdc++.h>
using namespace std;
struct node{
	int to,next;
} edge[2000];
int t,n,cnt,maxx,ans,head[1001],dep[1001];
vector<int> v,d[1001];
string s;
void add(int x,int y)
{
	edge[++cnt].to=y;
	edge[cnt].next=head[x];
	head[x]=cnt;
}
pair<int,int> query(vector<int> &x)
{
	cout<<"? "<<x.size()<<" "; 
	for(int i=0;i<x.size();i++)
		cout<<x[i]<<" ";
	cout<<endl;
	pair<int,int> p;
	scanf("%d%d",&p.first,&p.second);
	return p;
}
void dfs(int x,int fa)
{
    d[dep[x]].push_back(x);
    maxx=max(maxx,dep[x]);
	for(int i=head[x];i;i=edge[i].next)
		if(edge[i].to!=fa)
		{
			dep[edge[i].to]=dep[x]+1;
			dfs(edge[i].to,x);
		}
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		maxx=cnt=ans=0; 
		v.clear();
		d[0].clear();
		for(int i=1;i<=n;i++)
		{
			head[i]=0;
			v.push_back(i);
			d[i].clear();
		}
		for(int i=1;i<n;i++)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			add(a,b);
			add(b,a);
		}
		pair<int,int> p=query(v);
		int dis=p.second;
		dep[p.first]=0;
		dfs(p.first,0);
		int l=(dis-1)/2,r=min(maxx,dis);
		while(l<=r)
		{
			int mid=(l+r)>>1;
			p=query(d[mid]);
			if(p.second==dis)
			{
				ans=p.first;
				l=mid+1;
			}	
			else
				r=mid-1;
		}
		dep[ans]=0;
		v.clear();
		dfs(ans,0);
		for(int i=1;i<=n;i++)
			if(dep[i]==dis)
				v.push_back(i);
		cout<<"! "<<ans<<" "<<query(v).first<<endl;
		cin>>s;
		if(s!="Correct")
		{
			puts("MikeMirzayanov is an idiot!");
			return 0; 
		}
	}
	return 0;
}