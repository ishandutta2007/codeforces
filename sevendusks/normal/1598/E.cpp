/*
after dusk passed,
there is a starry sky.
*/
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define m_k make_pair
#define int long long
#define len(a) (int)a.size()
using namespace std;
const int N=1100;
int n,m,q,sh[N][N],ans;
inline int read()
{
	int f=1,x=0;char s=getchar();
	while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
	while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
	return x*f;
}
int get(int x,int y)
{
	int a=1,b=1,ans=0;
	if (sh[x][y-1])
	{
		a++;
		for (int i=1;;i++)
		{
			int tx=x-i,ty=y-i;
			if (tx<=0||ty<=0) break;
			if (sh[tx][ty]) a++;
			else break;
			if (sh[tx][ty-1]) a++;
			else break;
		}
	}
	for (int i=1;;i++)
	{
		int tx=x+i,ty=y+i;
		if (sh[tx][ty-1]) b++;
		else break;
		if (sh[tx][ty]) b++;
		else break;
		if (tx>n||ty>m) break;
	}
	ans+=a*b;
	a=1,b=1;
	for (int i=1;;i++)
	{
		int tx=x-i,ty=y-i;
		if (sh[tx][ty+1]) a++;
		else break;
		if (sh[tx][ty]) a++;
		else break;
		if (tx<0||ty<0) break;
	}
	if (sh[x][y+1])
	{
		b++;
		for (int i=1;;i++)
		{
			int tx=x+i,ty=y+i;
			if (tx>n||ty>m) break;
			if (sh[tx][ty]) b++;
			else break;
			if (sh[tx][ty+1]) b++;
			else break;
		}
	}
	ans+=a*b;
	return ans-1;
}
signed main()
{
	n=read();m=read();q=read();
	for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) ans+=get(i,j),sh[i][j]=1;
	while (q--)
	{
		int x=read(),y=read();
		if (!sh[x][y]) ans+=get(x,y);
		else ans-=get(x,y);
		sh[x][y]^=1;
		printf("%lld\n",ans);
	}
}