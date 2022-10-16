#include <cstdio>
#include <algorithm>
using namespace std;
const int N=3e5+5;
const int M=2e6+5;
int n;
int b[N],bs[N],s[N],t[N];
long long v;
int p[N],o;
int f[M],g[M],h[M],cnt;
void append(int a,int b,int c)
{
	cnt++;
	f[cnt]=bs[a];
	g[cnt]=bs[b];
	h[cnt]=c;
}
bool cmp(int u,int v)
{
	return b[u]<b[v];
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&b[i]);
		bs[i]=i;
	}
	sort(bs+1,bs+n+1,cmp);
	for (int i=1;i<=n;i++)
		s[i]=b[bs[i]];
	for (int i=1;i<=n;i++)
		scanf("%d",&t[i]);
	sort(t+1,t+n+1);
	v=0;
	for (int i=1;i<=n;i++)
	{
		v+=t[i]-s[i];
		if (v<0)
		{
			printf("NO\n");
			return 0;
		}
	}
	if (v!=0)
	{
		printf("NO\n");
		return 0;
	}
	for (int i=1;i<=n;i++)
	{
		if (t[i]>s[i])
			p[++o]=i;
		else
		{
			int x=s[i]-t[i];
			while (x)
			{
				int y=min(x,t[p[o]]-s[p[o]]);
				append(p[o],i,y);
				s[p[o]]+=y;
				x-=y;
				if (t[p[o]]-s[p[o]]==0)
					o--;
			}
		}
	}
	printf("YES\n");
	printf("%d\n",cnt);
	for (int i=1;i<=cnt;i++)
		printf("%d %d %d\n",f[i],g[i],h[i]);
	return 0;
}