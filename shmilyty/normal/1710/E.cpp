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
int n,m,a[200010],b[200010],sx,sy,f[200010],px[200010],py[200010];
int query(int l,int r)
{
	return f[r]-f[l-1];
}
int calc(int x,int y,bool cut)
{
	bool rem=0;
	if(y<=px[x])
	{
		if(sx<=x&&sy<=y)
			rem=1;
		if(sx>x&&sy>y&&sy>px[sx])
			rem=1;
		return x*y+m*(py[y]-x)-query(x+1,py[y])+(m-y)*(n-py[y])-rem*cut;
	}
	if(sx>x&&sy>y)
		rem=1;
	if(sx<=x&&sy<=y&&sy<=px[sx])
		rem=1;
	return (n-x)*(m-y)+query(py[y]+1,x)+py[y]*y-rem*cut;
}
bool check(int x)
{
	px[0]=m;
	for(int i=1;i<=n;i++)
		for(px[i]=px[i-1];px[i]>0&&a[i]+b[px[i]]>x;px[i]--);
	py[0]=n;
	for(int i=1;i<=m;i++)
		for(py[i]=py[i-1];py[i]>0&&a[py[i]]+b[i]>x;py[i]--);
	for(int i=1;i<=n;i++)
		f[i]=f[i-1]+px[i];
	int ans1=max(query(1,n),n*m-query(1,n)),ans2=max(query(1,n)-(sy<=px[sx]),n*m-query(1,n)-(sy>px[sx]));
	// puts("ok");
	for(int i=1,l=1;i<=n;i++)
	{
		while(l<m&&calc(i,l,0)<=calc(i,l+1,0))
			l++;
		ans1=max(ans1,calc(i,l,0));
	}
	for(int i=1,l=1;i<=n;i++)
	{
		while(l<m&&calc(i,l,1)<=calc(i,l+1,1))
			l++;
		// cout<<i<<" "<<l<<" "<<calc(i,l,1)<<'\n';
		ans2=max(ans2,calc(i,l,1));
	}
	// if(n==10&&m==200000)
	// cout<<ans1<<" "<<ans2<<'\n';
	assert(ans2-ans1<=1);
	return ans1!=ans2;
}
signed main()
{
	n=read();
	m=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	for(int i=1;i<=m;i++)
		b[i]=read();
	sx=a[1];
	sy=b[1];
	sort(a+1,a+1+n);
	sort(b+1,b+1+m);
	sx=lower_bound(a+1,a+1+n,sx)-a;
	sy=lower_bound(b+1,b+1+m,sy)-b;
	// cout<<a[sx]<<" "<<b[sy]<<'\n';
	// cout<<check(531556170);
	// cout<<'\n';
	int l=a[1]+b[1],r=a[sx]+b[sy];
	// if(n==10&&m==200000)
	// {
		// cout<<l<<" "<<r<<'\n';
		// cout<<check(3)<<"\n"<<check(4)<<"\n"<<check(5)<<'\n';
	// }
	while(l<=r)
	{
		// if(n==10&&m==200000)
		// cout<<l<<" "<<r<<'\n';
		int mid=(l+r)>>1;
		if(check(mid))
			l=mid+1;
		else
			r=mid-1;
	}
	cout<<min(l,a[sx]+b[sy]);
	return 0;
}