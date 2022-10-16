#include<bits/stdc++.h>
#define elif else if
#define ALL(x) x.begin(),x.end()
using namespace std;
void fileio(const string &s)
{
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
const int INF=1e9+7;
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
unsigned seed=std::chrono::system_clock::now().time_since_epoch().count();
mt19937 Rand(seed);
int n,k,ans,d[60],fa[60],deg[60],e[60][60],vis[60][60];
vector<pair<int,int> > v;
int find(int x)
{
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
signed main()
{
	n=read();
	k=read();
	for(int i=1;i<=k;i++)
		d[i]=read();
	for(int i=k+1;i<=n;i++)
		d[i]=INF;
	for(int i=1;i<=n;i++)
		for(int l=i+1;l<=n;l++)
			e[i][l]=read();
	for(int i=1;i<n;i++)
	{
		v.push_back({i,n});
		ans+=e[i][n];
		deg[i]++;
		deg[n]++;
	}
	for(double T=100000.0;T>=0.00001;T*=0.999996)
	{
		int x=Rand()%v.size();
		deg[v[x].first]--;
		deg[v[x].second]--;
		for(int i=1;i<=n;i++)
			fa[i]=i;
		for(int i=0;i<v.size();i++)
			if(i!=x)
				fa[find(v[i].first)]=find(v[i].second);
		int nxt=ans-e[v[x].first][v[x].second];
		int p=Rand()%(n-1)+1,q=Rand()%(n-p)+p+1;
		while(find(p)==find(q)||d[p]==deg[p]||d[q]==deg[q])
		{
			p=Rand()%(n-1)+1;
			q=Rand()%(n-p)+p+1;
		}
		nxt+=e[p][q];
		if(exp(-(double)(nxt-ans)/T)>=(double)(Rand()%1000000000)/1000000000)
		{
			ans=nxt;
			v.erase(v.begin()+x);
			deg[p]++;
			deg[q]++;
			v.push_back({p,q});
		}
		else
		{
			deg[v[x].first]++;
			deg[v[x].second]++;
		}
	}
	cout<<ans;
	return 0;
}