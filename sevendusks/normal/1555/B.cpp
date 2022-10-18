/*
after dusk passed,
there is a starry sky.
*/
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define m_k make_pair
#define len(a) (int)a.size()
using namespace std;
int t,n,m,w,h;
struct node
{
	int x,y;
}a;
node b;
inline int read()
{
	int f=1,x=0;char s=getchar();
	while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
	while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
	return x*f;
}
signed main()
{
	t=read();
	while (t--)
	{
		n=read();m=read();
		a=(node){read(),read()};b=(node){read(),read()};
		w=read(),h=read();
		if (w+b.x-a.x>n&&h+b.y-a.y>m)
		{
			printf("-1\n");
			continue;
		}
		int ans=inf;
		if (w+b.x-a.x<=n)
		{
			if (a.x>=w) ans=min(ans,0);
			else ans=min(ans,w-a.x);
			if (b.x<=n-w) ans=min(ans,0);
			else ans=min(ans,b.x-n+w);
		}
		if (h+b.y-a.y<=m)
		{
			if (a.y>=h) ans=min(ans,0);
			else ans=min(ans,h-a.y);
			if (b.y<=m-h) ans=min(ans,0);
			else ans=min(ans,b.y-m+h);
		}
		printf("%d\n",ans);
	}
}