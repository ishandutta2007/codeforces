#include <cstdio>
#include <algorithm>
using namespace std;
const int N=1e3+5;
int vb[N];
int n,k,b[N],c[N];
int f[12*N];
void pre()
{
	vb[1]=0;
	for (int i=1;i<N;i++)
		for (int j=1;j<=i;j++)
		{
			int nx=i+i/j;
			if (nx==1||i+i/j>=N)
				continue;
			if (vb[nx]==0||vb[i]+1<vb[nx])
				vb[nx]=vb[i]+1;
		}
}
void solve()
{
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&b[i]);
		b[i]=vb[b[i]];
	}
	for (int i=1;i<=n;i++)
		scanf("%d",&c[i]);
	for (int i=1;i<=12*n;i++)
		f[i]=0;
	f[0]=0;
	int s=0;
	for (int i=1;i<=n;i++)
	{
		for (int j=s;j>=0;j--)
			f[j+b[i]]=max(f[j+b[i]],f[j]+c[i]);
		s+=b[i];
	}
	int ans=0;
	for (int i=0;i<=min(s,k);i++)
		ans=max(ans,f[i]);
	printf("%d\n",ans);
}
int main()
{
	pre();
	int T;
	scanf("%d",&T);
	while (T--)
		solve();
	return 0;
}