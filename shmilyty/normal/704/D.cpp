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
struct node{
	int to,nxt,cap;
}e[1000000];
int n,m,s,t,S,T,c1=-1,head[200010],lev[200010],iter[200010];
void add(int x,int y,int v)
{ 
	e[++c1]={y,head[x],v};
	head[x]=c1;
	e[++c1]={x,head[y],0};
	head[y]=c1;
	// cout<<x<<"-"<<y<<"-"<<v<<endl;
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
int dinic(int x,int y)
{
	int ans=0;
	while(1)
	{
		bfs(x);
		if(lev[y]<0)
			return ans;
		for(int i=0;i<=y;i++)//warning!!!
			iter[i]=head[i];
		int f=0;
		while(f=dfs(x,y,INF))
			ans+=f;
	}
}
int R,B,ok,cnt,ty[200001],p[200001],bri[100001],num[200001],minn[200001],ran[200003];
map<int,int> id1,id2;
signed main()
{
	n=read();
	m=read();
	R=read();
	B=read();
	if(R>B)
	{
		swap(R,B);
		ok=1;
	}
	//R<=B
	memset(head,-1,sizeof(head));
	memset(minn,0x3f,sizeof(minn));
	for(int i=1;i<=n;i++)
	{
		int x=read(),y=read();
		if(!id1[x])
			id1[x]=++cnt;
		p[id1[x]]=x;
		num[id1[x]]++;
		if(!id2[y])
			id2[y]=++cnt;
		p[id2[y]]=y;
		ty[id2[y]]=1;
		num[id2[y]]++;
		add(id1[x],id2[y],1);
		bri[i]=c1;
	}
	s=cnt+1;
	t=s+1;
	S=0;
	T=t+1;
	// cout<<T<<endl;
	while(m--)
	{
		int opt=read(),x=read(),y=read();
		if(opt&1)
			minn[id1[x]]=min(minn[id1[x]],y);
		else
			minn[id2[x]]=min(minn[id2[x]],y);
	}
	for(int i=1;i<=cnt;i++)
	{
		// cout<<num[i]<<endl;
		int x=num[i],y=min(x,minn[i]),l=(x-y+1)/2,r=(x+y)/2;
		if(l>r)
		{
			puts("-1");
			return 0;
		}
		if(ty[i])
		{
			add(i,t,r-l);
			ran[t]+=l;
			ran[i]-=l;
		}
		else
		{
			add(s,i,r-l);
			ran[i]+=l;
			ran[s]-=l;
		}
	}
	int tot=0;
	for(int i=1;i<=cnt+2;i++)
		if(ran[i]>0)
		{
			tot+=ran[i];
			add(S,i,ran[i]);
		}
		elif(ran[i]<0)
			add(i,T,-ran[i]);
	add(t,s,1e9);
	// cout<<tot<<endl;
	if(dinic(S,T)!=tot)
	{
		puts("-1");
		return 0;
	}
	// puts("ok");
	int ans=dinic(s,t);
	cout<<ans*R+(n-ans)*B<<'\n';
	for(int i=1;i<=n;i++)
		if(e[bri[i]].cap^ok)
			cout<<'r';
		else
			cout<<'b';
	return 0;
}