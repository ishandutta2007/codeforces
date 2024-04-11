/*
after dusk passed,
there is a starry sky.
*/
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define m_k make_pair
#define len(a) (int)a.size()
using namespace std;
const int N=4*1e5+100;
int T,n,ans,b[N],w,sum[N];
int x[N],y[N];
struct node
{
	int a,b,m,id;
}sh[N];
struct inv
{
	int l,r,id;
}a[N];
bool cmp(node a,node b){return a.a+a.b-a.m<b.a+b.b-b.m;}
bool operator ==(node a,node b){return a.a+a.b-a.m==b.a+b.b-b.m;}
inline int read()
{
	int f=1,x=0;char s=getchar();
	while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
	while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
	return x*f;
}
void solve(int l,int r)
{
	int last=-1;
	sort(a+l,a+r+1,[](inv a,inv b){return a.r<b.r;});
	for (int i=l;i<=r;i++)
	{
		int now=a[i].id,id=sh[now].id;
		if (last>=a[i].l&&last<=a[i].r)
		{
			x[id]=sh[now].a-last;
			y[id]=sh[now].m-x[id];
			continue;
		}
		ans++;last=a[i].r;
		x[id]=sh[now].a-last;
		y[id]=sh[now].m-x[id];
	}
}
signed main()
{
	T=read();
	while (T--)
	{
		n=read();
		for (int i=1;i<=n;i++) sh[i]=(node){read(),read(),read(),i};
		sort(sh+1,sh+1+n,cmp);
		for (int i=1;i<=n;i++)
		{
			int l=max(0,sh[i].m-sh[i].b),r=min(sh[i].a,sh[i].m);
			a[i]=(inv){sh[i].a-r,sh[i].a-l,i};
		}
		ans=0;
		for (int i=1;i<=n;)
		{
			int j=i;
			while (j<=n&&sh[i]==sh[j]) j++;
			solve(i,j-1);
			i=j;
		}
		printf("%d\n",ans);
		for (int i=1;i<=n;i++) printf("%d %d\n",x[i],y[i]);
	}
}