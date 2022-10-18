#include <bits/stdc++.h>
using namespace std;
typedef unsigned int ui;
typedef unsigned long long ll;
#define all(x) (x).begin(),(x).end()
const int N=510;
ui *f[N],F[2][N*N],*g[N],G[2][N*N],*a[N],A[2][N*N],*b[N],B[2][N*N];
ui p;
void inc(ui &x,ui y){if ((x+=y)>=p) x-=p;}
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int n,i,j,k,l;
	cin>>n>>p;
	for (i=0;i<=n;i++) a[i]=A[i&1]+N*N/2-1;
	for (i=0;i<=n;i++) b[i]=B[i&1]+N*N/2-1;
	for (i=0;i<=n;i++) f[i]=F[i&1]+N*N/2-1;
	for (i=0;i<=n;i++) g[i]=G[i&1]+N*N/2-1;
	f[0][0]=1;
	for (i=0;i<N*N/2;i++) a[0][i]=1;
	for (i=1;i<=n;i++)
	{
		int l=(i+1)*(i+2)/2,r=i*(i-1)>>1;
		// memset(A[i&1],0,sizeof A[i&1]);
		// memset(B[i&1],0,sizeof B[i&1]);
		// memset(F[i&1],0,sizeof F[i&1]);
		// memset(G[i&1],0,sizeof G[i&1]);
		fill(a[i]-l,a[i]+l,0);
		fill(b[i]-l,b[i]+l,0);
		fill(g[i]-l,g[i]+l,0);
		fill(f[i]-l,f[i]+l,0);
		for (j=-r;j<=r;j++)
		{
			f[i][j]=(ll)f[i-1][j]*i%p;
			g[i][j]=(ll)g[i-1][j]*i%p;
			f[i][j]=(f[i][j]+(ll)(p+a[i-1][j+i-1]-a[i-1][j])*(p+i+j)+(p+b[i-1][j]-b[i-1][j+i-1]))%p;
			g[i][j]=(g[i][j]+(ll)(p+a[i-1][j-1]-a[i-1][j-i])*(p+i-j)+(p+b[i-1][j-1]-b[i-1][j-i]))%p;
			a[i][j]=(a[i][j-1]+f[i][j]+g[i][j])%p;
			b[i][j]=(b[i][j-1]+(ll)(f[i][j]+g[i][j])*(p+j))%p;
		}
		for (;j<l;j++) a[i][j]=a[i][j-1];
		for (;j<l;j++) b[i][j]=b[i][j-1];
	}
	ui ans=0;
	for (i=1;i<=n*(n-1)>>1;i++) inc(ans,f[n][i]);
	cout<<ans<<endl;
}