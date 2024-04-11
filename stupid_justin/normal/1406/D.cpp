#include<bits/stdc++.h>
#define int long long
#define rd(x) x=read()
using namespace std;
const int N=1e5+5;
const int M=5005;
const int mod=998244353;
inline int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
int ksm(int x,int y){int ret=1;while (y){if (y&1) ret=(ret*x)%mod;x=(x*x)%mod;y>>=1;}return ret;}
int Q;
int n,sum;
int a[N];
int d[N];
int div2(int x)
{
	if (x==0) return 0;
	if (x>0) return (x+1)/2;
	return x/2;
}
void query()
{
	//b_1,c_1
	//c_n
	//a_i
	//d_i=d_i-d_{i-1}
	//c_nd_isum+c_1
	//sum+c_1=b_1
	//c_n+b_1=sum+a_1
	//
	//
	//
	printf("%lld\n",div2(sum+a[1]));
}
void update(int l,int r,int x)
{
	//d[l]+=x,d[r+1]-=x
	if (l!=1)
	{
		if (d[l]>0) sum-=d[l];
		d[l]+=x;
		if (d[l]>0) sum+=d[l];
	}
	if (l==1) a[l]+=x;
	if (r!=n)
	{
		if (d[r+1]>0) sum-=d[r+1];
		d[r+1]-=x;
		if (d[r+1]>0) sum+=d[r+1];
	}
	//for (int i=1;i<=n;i++) printf("d[%lld]=%lld ",i,d[i]);puts("");
}
signed main()
{
	rd(n);
	for (int i=1;i<=n;i++) rd(a[i]);
	for (int i=2;i<=n;i++) d[i]=a[i]-a[i-1];
	for (int i=2;i<=n;i++) if (d[i]>0) sum+=d[i];
	query();
	rd(Q);
	while (Q--)
	{
		int l,r,x;
		rd(l);rd(r);rd(x);
		update(l,r,x);
		query();
	}
}