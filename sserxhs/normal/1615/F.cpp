#include <bits/stdc++.h>
using namespace std;
typedef unsigned int ui;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int N=2e3+20,p=1e9+7;
int F[N][N*2],*f[N],G[N][N*2],*g[N];
int a[N],b[N];
void inc(int &x,int y){if ((x+=y)>=p) x-=p;}
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int T;
	cin>>T;
	while (T--)
	{
		int n,i,j;
		{
			string s,t;
			cin>>n>>s>>t;
			for (i=0;i<n;i++) a[i+1]=s[i]=='?'?2:s[i]-'0';
			for (i=0;i<n;i++) b[i+1]=t[i]=='?'?2:t[i]-'0';
		}
		for (i=0;i<=n;i++) f[i]=F[i]+N;
		for (i=0;i<=n;i++) memset(F[i],0,sizeof F[i]);
		for (i=0;i<=n;i++) g[i]=G[i]+N;
		for (i=0;i<=n;i++) memset(G[i],0,sizeof G[i]);
		for (i=1;i<=n;i+=2) if (a[i]<2) a[i]^=1;
		for (i=1;i<=n;i+=2) if (b[i]<2) b[i]^=1;
		g[0][0]=1;
		for (i=1;i<=n;i++)
		{
			if (a[i]!=1&&b[i]!=1) for (j=-i;j<=i;j++) inc(f[i][j],f[i-1][j]),inc(g[i][j],g[i-1][j]);
			if (a[i]!=1&&b[i]!=0)
			{
				for (j=-i;j<0;j++) inc(g[i][j],g[i-1][j+1]),f[i][j]=(f[i][j]+f[i-1][j+1]+(ll)g[i-1][j+1]*(p-i))%p;
				for (j=0;j<=i;j++) inc(g[i][j],g[i-1][j+1]),f[i][j]=(f[i][j]+f[i-1][j+1]+(ll)g[i-1][j+1]*i)%p;
			}
			if (a[i]!=0&&b[i]!=1)
			{
				for (j=-i;j<=0;j++) inc(g[i][j],g[i-1][j-1]),f[i][j]=(f[i][j]+f[i-1][j-1]+(ll)g[i-1][j-1]*i)%p;
				for (j=1;j<=i;j++) inc(g[i][j],g[i-1][j-1]),f[i][j]=(f[i][j]+f[i-1][j-1]+(ll)g[i-1][j-1]*(p-i))%p;
			}
			if (a[i]!=0&&b[i]!=0) for (j=-i;j<=i;j++) inc(f[i][j],f[i-1][j]),inc(g[i][j],g[i-1][j]);
		}
		//for (i=1;i<=n;i++) for (j=-i;j<=i;j++) cout<<f[i][j]<<" \n"[i==j];cout<<endl;
		//for (i=1;i<=n;i++) for (j=-i;j<=i;j++) cout<<g[i][j]<<" \n"[i==j];cout<<endl;
		cout<<f[n][0]<<'\n';
	}
}