#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m;
P a[MAXN];
bool used[MAXN];
vector<int> G[MAXN];
int deg[MAXN],ans[MAXN];
int p[MAXN],r[MAXN];
vector<int> nums[MAXN];
void init(int n)
{
    for(int i=0;i<n;i++)
    {
        p[i]=i;
        r[i]=0;
        nums[i].clear();
        nums[i].push_back(i);
    }
}
int find(int x)
{
    if(p[x]==x) return x;
    else return p[x]=find(p[x]);
}
void unite(int x,int y)
{
    x=find(x);
    y=find(y);
    if(x==y) return;
    if(r[x]<r[y]) 
    {
    	p[x]=y;
    	nums[y].insert(nums[y].end(),nums[x].begin(),nums[x].end());
    }
    else
    {
        p[y]=x;
        nums[x].insert(nums[x].end(),nums[y].begin(),nums[y].end());
        if(r[x]==r[y]) r[x]++;
    }
}
bool same(int x,int y)
{
    return find(x)==find(y);
}
int main()
{
	scanf("%d%d",&n,&m);
	memset(deg,0,sizeof(deg));
	memset(used,false,sizeof(used));
	memset(ans,0,sizeof(ans));
	init(n*m);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			scanf("%d",&a[i*m+j].F);
			a[i*m+j].S=i*m+j;
		}
	}
	vector<P> srt;
	for(int i=0;i<n;i++)
	{
		srt.clear();
		for(int j=0;j<m;j++)
			srt.push_back(a[i*m+j]);
		sort(srt.begin(),srt.end());
		for(int j=0;j<m-1;j++) if(srt[j].F==srt[j+1].F) unite(srt[j].S,srt[j+1].S);
	}
	for(int i=0;i<m;i++)
	{
		srt.clear();
		for(int j=0;j<n;j++)
			srt.push_back(a[j*m+i]);
		sort(srt.begin(),srt.end());
		for(int j=0;j<n-1;j++) if(srt[j].F==srt[j+1].F) unite(srt[j].S,srt[j+1].S);
	}
	for(int i=0;i<n;i++)
	{
		srt.clear();
		for(int j=0;j<m;j++)
			srt.push_back(a[i*m+j]);
		sort(srt.begin(),srt.end());
		for(int j=0;j<m-1;j++)
		{
			if(srt[j].F==srt[j+1].F) continue;
			int x=find(srt[j].S),y=find(srt[j+1].S);
			G[x].push_back(y);
			G[y].push_back(x);
			deg[y]++;
		}
	}
	for(int i=0;i<m;i++)
	{
		srt.clear();
		for(int j=0;j<n;j++)
			srt.push_back(a[j*m+i]);
		sort(srt.begin(),srt.end());
		for(int j=0;j<n-1;j++)
		{
			if(srt[j].F==srt[j+1].F) continue;
			int x=find(srt[j].S),y=find(srt[j+1].S);
			G[x].push_back(y);
			G[y].push_back(x);
			deg[y]++;
		}
	}
	queue<P> que;
	for(int i=0;i<n*m;i++) 
		if(deg[find(i)]==0&&!used[find(i)]) 
		{
			que.push(P(find(i),1));
			used[find(i)]=true;
		}
	memset(used,false,sizeof(used));
	while(que.size())
	{
		P p=que.front();
		que.pop();
		for(int i=0;i<nums[p.F].size();i++)
			ans[nums[p.F][i]]=p.S;
		used[p.F]=true;
		for(int i=0;i<G[p.F].size();i++)
		{
			if(used[G[p.F][i]]) continue;
			deg[G[p.F][i]]--;
			if(deg[G[p.F][i]]==0) que.push(P(G[p.F][i],p.S+1));
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
			printf("%d ",ans[i*m+j]);
		puts("");
	}
	return 0;
}