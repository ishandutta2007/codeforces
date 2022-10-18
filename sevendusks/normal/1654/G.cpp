/*
after dusk passed,
there is a starry sky.
*/
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define m_k make_pair
#define len(a) (int)a.size()
using namespace std;
const int N=2*1e5+100;
int n,b[N],h[N],d[N],ans[N],ok[N],vi[N];
vector <int> e[N],p[N],r[N];
inline void ckmin(int &a,int b){a=((a<b)?a:b);}
inline void ckmax(int &a,int b){a=((a>b)?a:b);}
inline int read()
{
	int f=1,x=0;char s=getchar();
	while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
	while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
	return x*f;
}
signed main()
{
	n=read();
	for (int i=1;i<=n;i++) b[i]=read();
	for (int i=1;i<n;i++)
	{
		int u=read(),v=read();
		e[u].push_back(v);e[v].push_back(u);
	}
	memset(h,0x3f,sizeof(h));queue <int> q;
	for (int i=1;i<=n;i++) if (b[i]) h[i]=0,q.push(i);
	while (!q.empty())
	{
		int x=q.front();q.pop();
		for (int u:e[x])
		{
			if (h[u]>h[x]+1)
			{
				h[u]=h[x]+1;
				q.push(u);
			}
		}
	}
	for (int i=1;i<=n;i++)
	{
		p[h[i]].push_back(i);
		for (int j:e[i]) ok[i]|=(h[i]==h[j]);
		ans[i]=h[i];
	}
	for (int i=0;i<=n;i++)
	{
		if (p[i].empty()) break;
		if (none_of(p[i].begin(),p[i].end(),[](int x){return ok[x]==1;})) continue;
		memset(d,0x3f,sizeof(d));
		memset(vi,0,sizeof(vi));
		for (int x:p[i]) if (ok[x]) d[x]=0;
		for (int j=i+1;j<=n;j++)
		{
			if (p[j].empty()) break;
			for(int x:p[j])
			{
				for (int u:e[x]) if (h[u]==h[x]-1) ckmin(d[x],max(0,d[u]-1));
			}
			priority_queue <pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
			for (int x:p[j]) if (ok[x]) q.push(m_k(d[x],x));
			while (!q.empty())
			{
				int x=q.top().second;q.pop();
				if (vi[x]) continue;
				vi[x]=1;
				for (int u:e[x]) if (h[u]==h[x]&&d[u]>d[x]+1)
				{
					d[u]=d[x]+1;
					q.push(m_k(d[u],u));
				}
			}
			for (int x:p[j]) if (d[x]==0) ckmin(ans[x],i);
		}
	}
	for (int i=1;i<=n;i++) printf("%d ",2*h[i]-ans[i]);
	printf("\n");
}