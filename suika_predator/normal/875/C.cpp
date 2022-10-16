#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN=100010,Inf=0x3f3f3f3f;
int n,m;
vector<int> s[MAXN];
queue<int> q;
int ans;
int tmp[MAXN],flag[MAXN],ok[MAXN][2],vis[MAXN];
struct edge
{
	int v;
	edge *next;
}*h[MAXN],pool[MAXN];
int top;
inline void addedge(int u,int v)
{
	edge *tmp=&pool[top++];tmp->v=v;tmp->next=h[u];h[u]=tmp;
}
bool solve(int x,int l,int r)
{
	//cout<<"solve "<<x<<' '<<l<<' '<<r<<endl;
	bool flag=false;
	int last=l;
	for(int i=l;i<r;i++)
	{
		//cout<<"for "<<i<<' '<<s[i][x]<<' '<<s[i+1][x]<<endl;
		if(s[i][x]>s[i+1][x])
		{
			if(s[i+1][x]<0)return false;
			//cout<<s[i][x]<<endl;
			if(!flag)
			{
				for(int j=l;j<=i;j++)if(s[j][x]>=0)ok[s[j][x]][0]=0;
				for(int j=i+1;j<=r;j++)if(s[j][x]>=0)ok[s[j][x]][1]=0;
				flag=true;
			}
			else return false;
		}
		else if(s[i+1][x]>=0&&s[i][x]>=0)
		{
			addedge(s[i+1][x],s[i][x]);
		}
		if(s[i][x]!=s[i+1][x])
		{
			if(s[i][x]>=0)
			{
				if(!solve(x+1,last,i))return false;
				//cout<<"ret"<<endl;
			}
			last=i+1;
		}
	}
	if(s[r][x]>=0)if(!solve(x+1,last,r))return false;
	return true;
}
int main()
{
	memset(ok,0x3f,sizeof(ok));
	scanf("%d%d",&n,&m);
	int maxl,l,t;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&l);
		if(l<maxl)maxl=l;
		for(int j=1;j<=l;j++)
		{
			scanf("%d",&t);
			s[i].push_back(t);
		}
		s[i].push_back(-Inf);
	}
	ans=solve(0,1,n);
	if(!ans)
	{
		printf("No\n");
		return 0;
	}
	for(int i=1;i<=m;i++)
	{
		if(!ok[i][0])
		{
			q.push(i);
			vis[i]=1;
		}
	}
	while(!q.empty())
	{
		int u=q.front();q.pop();
		for(edge *tmp=h[u];tmp;tmp=tmp->next)
		{
			if(!vis[tmp->v])
			{
				ok[tmp->v][0]=0;
				vis[tmp->v]=1;
				q.push(tmp->v);
			}
		}
	}
	vector<int> v;
	for(int i=1;i<=m;i++)
	{
		if(!ok[i][0]&&!ok[i][1])return printf("No\n"),0;
		else if(!ok[i][0])v.push_back(i);
	}
	printf("Yes\n%d\n",v.size());
	for(auto x:v)
	{
		printf("%d ",x);
	}
	printf("\n");
	return 0;
}