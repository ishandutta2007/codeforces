#include <cstdio>
using namespace std;
const int N=505;
const int mod=998244353;
int n,m;
int c[N];
int f[N][N];
int g[N][N];
bool v[N][N],s[N][N];
int ans;
int dpg(int l,int r);
int dp(int l,int r)
{
	if (l>r)
		return 1;
	if (v[l][r])
		return f[l][r];
	v[l][r]=1;
	int mn=n+1,mp=0;
	for (int i=l;i<=r;i++)
		if (c[i]<mn)
		{
			mn=c[i];
			mp=i;
		}
	for (int i=mp;i<=r;i++)
		f[l][r]=(f[l][r]+1ll*dpg(l,mp-1)*dpg(mp+1,i)%mod*dpg(i+1,r))%mod;
	//printf("f %d %d : %d\n",l,r,f[l][r]);
	return f[l][r];
}
int dpg(int l,int r)
{
	if (l>r)
		return 1;
	if (s[l][r])
		return g[l][r];
	s[l][r]=1;
	int mn=n+1,mp=0;
	for (int i=l;i<=r;i++)
		if (c[i]<mn)
		{
			mn=c[i];
			mp=i;
		}
	for (int i=l;i<=mp;i++)
		g[l][r]=(g[l][r]+1ll*dpg(l,i-1)*dp(i,r))%mod;
	//printf("g %d %d : %d\n",l,r,g[l][r]);
	return g[l][r];
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
		scanf("%d",&c[i]);
	printf("%d\n",dpg(1,n));
	return 0;
}