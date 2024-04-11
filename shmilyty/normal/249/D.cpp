#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
#define elif else if
#define ALL(x) x.begin(),x.end()
#define lowbit(x) (x&(-x))
using namespace std;
void fileio(const string &s)
{
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
const int INF=4e18;
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
struct node{
	int x,y;
	bool operator<(const node&a)const
	{
		if(a.x==x)
			return y<a.y;
		return x<a.x;
	 } 
}a[100001];
bool cmp(node x,node y)
{
	if(x.x==y.x)
		return x.y>y.y;
	return x.x<y.x;
}
int f[100001],A,B,C,D,n,tot,ans;
signed main()
{
	n=read();
	scanf("%lld/%lld %lld/%lld",&A,&B,&C,&D);
	for(int i=1;i<=n;i++)
	{
		int x=read(),y=read();
		a[++tot]={A*x-B*y,D*y-C*x};
		if(a[tot].x>=0||a[tot].y>=0)
			tot--;
	}
	sort(a+1,a+1+tot,cmp);
	for(int i=1;i<=tot;i++)
	{
		if(!ans||f[ans]<a[i].y)
			f[++ans]=a[i].y;
		else
		{
			int x=lower_bound(f+1,f+1+ans,a[i].y)-f;
			f[x]=a[i].y;
		}
	}
	cout<<ans;
	return 0;
}