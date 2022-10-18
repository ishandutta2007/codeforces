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
int T,n,a[N],b[N],cnt[N],dg[N];
vector <int> e[N];
inline int read()
{
	int f=1,x=0;char s=getchar();
	while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
	while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
	return x*f;
}
signed main()
{
	T=read();
	while (T--)
	{
		n=read();
		for (int i=1;i<=n;i++) a[i]=read();
		for (int i=1;i<=n;i++) b[i]=read();
		for (int i=1;i<=n;i++) e[i].clear(),cnt[i]=dg[i]=0;
		for (int i=1;i<=n;i++) cnt[a[i]]++;
		int pos=max_element(cnt+1,cnt+1+n)-cnt;
		for (int i=1;i<=n;i++) if (a[i]!=pos&&b[i]!=pos)
		{
			e[a[i]].push_back(b[i]);
			dg[b[i]]++;
		}
		queue <int> q;
		for (int i=1;i<=n;i++) if (!dg[i]) q.push(i);
		while (!q.empty())
		{
			int x=q.front();q.pop();
			for (int u:e[x])
			{
				dg[u]--;
				if (!dg[u]) q.push(u);
			}
		}
		bool bl=1;
		for (int i=1;i<=n;i++) if (dg[i]) bl=0;
		if (bl) puts("AC");
		else puts("WA");
	}
}