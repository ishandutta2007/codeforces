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
int n,m,q,dg[N],ans;
inline int read()
{
	int f=1,x=0;char s=getchar();
	while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
	while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
	return x*f;
}
void add(int x,int v)
{
	if (!dg[x]) ans--;
	dg[x]+=v;
	if (!dg[x]) ans++;
}
signed main()
{
	n=read();m=read();
	for (int i=1;i<=m;i++)
	{
		int u=read(),v=read();
		if (u<v) swap(u,v);
		dg[v]++;
	}
	for (int i=1;i<=n;i++) if (!dg[i]) ans++;
	q=read();
	while (q--)
	{
		int op=read();
		if (op==1)
		{
			int u=read(),v=read();
			if (u<v) swap(u,v);
			add(v,1);
		}
		if (op==2)
		{
			int u=read(),v=read();
			if (u<v) swap(u,v);
			add(v,-1);
		}
		if (op==3) printf("%d\n",ans);
	}
}