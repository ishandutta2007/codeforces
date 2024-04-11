#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
#define elif else if
#define ALL(x) x.begin(),x.end()
#define lowbit(x) (x&(-x))
using namespace std;
void fileio(const string &s)
{
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
const int INF=4e18;
inline int read()
{
	int x=0;
	bool flag=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
			flag=0;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return (flag?x:~(x-1));
}
int n1,n2,m,q;
struct node{
	int to,nxt,cap;
}e[1200001];
int s,t,cnt=-1,res,sum,head[400003],lev[400003],iter[400003],con[400001];
std::vector<int> v;
array<int,2> eg[200001];
void add(int x,int y,int v)
{ 
	e[++cnt]={y,head[x],v};
	head[x]=cnt;
	e[++cnt]={x,head[y],0};
	head[y]=cnt;
}
void bfs(int s)
{
	queue<int> q;
	q.push(s);
	memset(lev,-1,sizeof(lev));
	lev[s]=0;
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		for(int i=head[x];~i;i=e[i].nxt)
			if(e[i].cap>0&&lev[e[i].to]<0)
			{
				lev[e[i].to]=lev[x]+1;
				q.push(e[i].to);
			}
	}
}
int dfs(int x,int y,int cnt)
{
	if(x==y)
		return cnt;
	for(int &i=iter[x];~i;i=e[i].nxt)
	{
		node &E=e[i];
		if(E.cap&&lev[x]<lev[E.to])
		{
			int d=dfs(E.to,y,min(cnt,E.cap));
			if(d)
			{
				E.cap-=d;
				e[i^1].cap+=d;
				return d;
			}
		}
	}
	return 0;
}
int dinic()
{
	int ans=0;
	while(1)
	{
		bfs(s);
		if(lev[t]<0)
			return ans;
		for(int i=1;i<=t;i++)//warning!!!
			iter[i]=head[i];
		int f=0;
		while(f=dfs(s,t,INF))
			ans+=f;
	}
}
signed main()
{
	n1=read();
	n2=read();
	m=read();
	q=read();
	s=n1+n2+1;
	t=n1+n2+2;
	for(int i=1;i<=t;i++)
		head[i]=-1;
	for(int i=1;i<=m;i++)
	{
		int x=read(),y=read();
		add(x,y+n1,1);
		eg[i]={x,y+n1};
	}
	for(int i=1;i<=n1;i++)
		add(s,i,1);
	for(int i=n1+1;i<=n1+n2;i++)
		add(i,t,1);
	res=dinic();
	for(int i=1;i<=m;i++)
		if(!e[(i<<1)-2].cap)
		{
			con[eg[i][0]]=con[eg[i][1]]=i;
			sum+=i;
		}
	for(int i=1;i<=n1+n2;i++)
		if(i<=n1&&lev[i]<0)
			v.push_back(i);
		elif(i>n1&&lev[i]>0)
			v.push_back(i);
	// for(int i=1;i<=n1;i++)
		// cout<<i<<" "<<con[i]<<endl;
	// for(int i:v)
		// cout<<i<<" ";
	// cout<<endl;
	while(q--)
	{
		int opt=read();
		if(opt&1)
		{
			int x=v.back();
			v.pop_back();
			puts("1");
			if(x<=n1)
				cout<<x<<'\n';
			else
				cout<<n1-x<<'\n';
			int y=con[x];
			con[eg[y][0]]=con[eg[y][1]]=0;
			sum-=y;
			cout<<sum<<endl;
			res--;
		}
		else
		{
			cout<<res<<'\n';
			for(int i=1;i<=n1;i++)
				if(con[i])
					cout<<con[i]<<" ";
			cout<<endl;
		}
	}
	return 0;
}
//????