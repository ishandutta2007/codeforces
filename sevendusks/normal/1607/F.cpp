/*
after dusk passed,
there is a starry sky.
*/
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define m_k make_pair
#define len(a) (int)a.size()
using namespace std;
const int N=2100,M=4*1e6+100;
int T,n,m,f[M],cir[M],vi[M],w,cnt[M];
int st[M],t;
char s[N][N];
int tot,first[M],nxt[M],point[M];
int id(int x,int y){return (x-1)*m+y;}
inline int read()
{
	int f=1,x=0;char s=getchar();
	while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
	while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
	return x*f;
}
inline void add_edge(int x,int y)
{
	nxt[++tot]=first[x];first[x]=tot;
	point[tot]=y;
}
signed main()
{
	T=read();
	while (T--)
	{
		n=read();m=read();
		for (int i=1;i<=n;i++) scanf("%s",s[i]+1);
		for (int i=1;i<=n;i++) for (int j=1;j<=m;j++)
		{
			char c=s[i][j];
			int x=i,y=j;
			if (c=='L') y--;
			if (c=='R') y++;
			if (c=='U') x--;
			if (c=='D') x++;
			if (x<=0||y<=0||x>n||y>m)
			{
				f[id(i,j)]=id(i,j);
				continue;
			}
			f[id(i,j)]=id(x,y);
		}
		int k=n*m;tot=-1;
		for (int i=1;i<=k;i++)
		{
			vi[i]=cir[i]=cnt[i]=0;
			first[i]=-1;
		}
		w=0;
		for (int i=1;i<=k;i++) if (!vi[i])
		{
			int x=i;t=0;vi[x]=i;st[++t]=x;
			while (1)
			{
				x=f[x];
				if (vi[x])
				{
					if (vi[x]!=i) break;
					w++;
					while (st[t]!=x) cir[st[t]]=w,cnt[w]++,t--;
					cir[x]=w;cnt[w]++;
					break;
				}
				vi[x]=i;st[++t]=x;
			}
		}
		for (int i=1;i<=k;i++) if (!cir[i]) add_edge(f[i],i);
		for (int i=1;i<=k;i++) vi[i]=f[i]=0;
		for (int i=1;i<=k;i++) if (!vi[i]&&cir[i])
		{
			f[i]=cnt[cir[i]];
			int h=0;t=-1;st[++t]=i;
			while (h<=t)
			{
				int x=st[h++];vi[x]=1;
				for (int i=first[x];i!=-1;i=nxt[i])
				{
					int u=point[i];
					f[u]=f[x]+1;
					st[++t]=u;
				}
			}
		}
		int pos=max_element(f+1,f+1+k)-f;
		for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) if (id(i,j)==pos)
		{
			printf("%d %d %d\n",i,j,f[pos]);
		}
	}
}