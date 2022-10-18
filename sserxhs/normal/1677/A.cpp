//114514min
#include "bits/stdc++.h"
using namespace std;
#if !defined(ONLINE_JUDGE)&&defined(LOCAL)
#include "my_header\debug.h"
#else
#define dbg(...) ;
#define dbgn(...) ;
#endif
typedef unsigned int ui;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int N=5e3+5;
int f[N][N],g[N][N];
int a[N];
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cout<<setiosflags(ios::fixed)<<setprecision(15);
	int T;cin>>T;
	while (T--)
	{
		int n,i,j;
		cin>>n;
		for (i=1;i<=n;i++) cin>>a[i];
		for (i=1;i<n;i++)
		{
			f[i][n]=0;
			for (j=n-1;j>i;j--) f[i][j]=f[i][j+1]+(a[j+1]<a[i]);
		}
		for (j=2;j<=n;j++)
		{
			g[1][j]=0;
			for (i=2;i<j;i++) g[i][j]=g[i-1][j]+(a[i-1]<a[j]);
		}
		ll r=0;
		for (i=2;i<=n;i++) for (j=i+1;j<n;j++) r+=(ll)f[i][j]*g[i][j];
		cout<<r<<endl;
	}
}