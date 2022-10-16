// #pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
//#define int long long
#define elif else if
using namespace std;
void fileio(const string &s)
{
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
const int INF=1e9;
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
	int to,cap,nxt;
	long double cost;
}e[400010];
int n,m,S,T,k,cnt=-1,tot,ans1,head[1009],pre[1009],from[1009],inq[1009];
long double dis[1001],ans2,sum;
array<long double,2> a[401];
inline void add(int u,int v,int flow,long double cost)
{
	e[++cnt]={v,flow,head[u],cost};
	head[u]=cnt;
	e[++cnt]={u,0,head[v],-cost};
	head[v]=cnt;
}
queue<int> q;
void solve(int s,int t)
{
	while(1)
	{
		fill(dis+1,dis+1+T,INF);
		memset(inq,0,sizeof(inq));
		dis[s]=0;
		while(!q.empty())
			q.pop();
		q.push(s);
		inq[s]=1;
		while(!q.empty())
		{
			int f=q.front();
			q.pop();
			inq[f]=0;
			// cout<<f<<endl;
			for(int i=head[f];~i;i=e[i].nxt)
			{
				int to=e[i].to;
				if(e[i].cap>0&&dis[to]>dis[f]+e[i].cost)
				{
					dis[to]=dis[f]+e[i].cost;
					pre[to]=i;
					from[to]=f;
					if(!inq[to])
					{
						inq[to]=1;
						q.push(to);
					}
				}
			}
		}
		// cout<<dis[t]<<endl;
		if(dis[t]==INF)
		{
			if(ans1!=n-1)
				puts("-1");
			else
				printf("%.9Lf\n", ans2);
			return ;
		}
		int d=INF;
		for(int i=t;i!=s;i=from[i])
			d=min(d,e[pre[i]].cap);
		ans1+=d;
		ans2+=dis[t]*d;
		for(int i=t;i!=s;i=from[i])
		{
			e[pre[i]].cap-=d;
			e[pre[i]^1].cap+=d;
		}
	}
}
long double D(int x,int y)
{
	return sqrt((a[x][0]-a[y][0])*(a[x][0]-a[y][0])+(a[x][1]-a[y][1])*(a[x][1]-a[y][1]));
}
signed main()
{
//	fileio("1");
	n=read();
	S=2*n+1;
	T=2*n+2;
	for(int i=1;i<=T;i++)
		head[i]=-1;
	for(int i=1;i<=n;i++)
	{
		double x=read(),y=read();
		a[i]={x,y};
		add(S,i*2-1,2,0);
		add(i*2,T,1,0);
	}
	for(int i=1;i<=n;i++)
		for(int l=1;l<=n;l++)
			if(a[i][1]>a[l][1])
				add(i*2-1,l*2,1,D(i,l));
	// cout<<S<<" "<<T<<endl;
	solve(S,T);
	return 0;
}