#include<bits/stdc++.h>
#define int long long 
#define ri register signed
#define rd(x) x=read()
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
using namespace std;
const int N=1e5+5;
const int M=350;
const int mod=998244353;
const double inf=1e18;
int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if (ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}


int n,m,k,a[N],p[N],id[N],L[M],R[M];
int f[N],ans;
 
struct block
{
	int l,r,q[M];
	int k,b;//
	int e(int i) {return f[i]+k*a[i]+b;}//
	double s(int i,int j)
	{
		if (a[i]==a[j]) return f[i]>f[j]?-inf:inf;
		return 1.0*(f[i]-f[j])/(a[i]-a[j]);
	}
	void build(int x)
	{
		for (int i=L[x];i<=R[x];i++) f[i]+=k*a[i]+b;
		k=b=l=r=0;
		for (int i=L[x];i<=R[x];i++){while (r-l>1 && s(q[r-2],q[r-1])< s(q[r-1],id[i]))r--;q[r++]=id[i];}
	}
	pii query(){while (r-l>1 && e(q[l])<=e(q[l+1]))l++;return mp(e(q[l]),q[l]);}
}B[M];//
 
signed main()
{
	rd(n);m=sqrt(n);
	for (int i=k=1;i<=n;k+=!(i%m),i++)
	{
		rd(a[i]);f[i]=a[i];id[i]=i;p[i]=k;
	}
	if (n%m==0) k--;
	for (int i=1;i<=k;i++)
	{
		L[i]=R[i-1]+1,R[i]=min(i*m,n);
		sort(id+L[i],id+R[i]+1,[&](int i,int j) {return a[i]<a[j];});
		B[i].build(i);
	}
	while (1)
	{
		pii mx=mp(0,0);
		for (int i=1;i<=k;i++) mx=max(mx,B[i].query());
		if (!mx.fi) {cout<<ans<<endl;return 0;}
		ans+=mx.fi;f[mx.se]=-inf;

		for (int i=1;i< p[mx.se];i++) B[i].b+=a[mx.se];
		for (int i=L[p[mx.se]];i< mx.se;i++) f[i]+=a[mx.se];
		for (int i=mx.se+1;i<=R[p[mx.se]];i++) f[i]+=a[i];
		for (int i=p[mx.se]+1;i<=k;i++) B[i].k++;
		
		B[p[mx.se]].build(p[mx.se]);
	}
}