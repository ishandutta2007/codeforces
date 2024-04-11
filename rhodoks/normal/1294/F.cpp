#include <bits/stdc++.h>
#define DB double
#define LL long long

#define MST(a,b) memset((a),(b),sizeof(a))
#define MRK() cout<<"Mark"<<endl;
#define WRT(x) cout<<#x<<" = "<<(x)<<endl;

#define MAXN 210000
#define MAXM 10000
#define MOD 998244353
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

vector<int> g[MAXN];
int n;
int dis[MAXN];
int pa[MAXN];
int res,r;
int a,b,c;
int ans=0;

void init()
{
	int x,y;
	cin>>n;
	for (int i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	

}

void getmx(int pos,int f,int d)
{
	if (d>res)
	{
		res=d;
		r=pos;
	}
	for (auto p:g[pos])
		if (p!=f)
			getmx(p,pos,d+1);
}

void dfs(int pos,int f)
{
	pa[pos]=f;
	for (auto p:g[pos])
		if (p!=f)
			dfs(p,pos);
}

void work()
{
	getmx(1,1,0);
	a=r;
	res=0;
	getmx(a,a,0);
	b=r;
	dfs(a,a);
	queue<int> q;
	q.push(b);
	int tmp=b;
	dis[b]=1;
	while (tmp!=a)
	{
		tmp=pa[tmp];
		dis[tmp]=1;
		q.push(tmp);
		ans++;
	}
	int mx=0;
	while (!q.empty())
	{
		int pos=q.front();
		q.pop();
		if (dis[pos]>mx && pos!=a && pos!=b)
		{
			mx=dis[pos];
			c=pos;
		}
		for (auto p:g[pos])
			if (!dis[p])
			{
				dis[p]=dis[pos]+1;
				q.push(p);
			}
	}
	cout<<ans+mx-1<<endl<<a<<' '<<b<<' '<<c;
}

int main()
{
	init();
	work();
	return ~~(0^_^0);
}