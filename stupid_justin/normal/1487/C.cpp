#include<bits/stdc++.h>
#define int long long
#define rd(x) x=read()
using namespace std;
const int N=2e2+5;
const int M=5005;
const int mod=998244353;
inline int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}

int ans[N][N];
int n,k;
int f(int x){x=(x%n+n)%n;if (x==0) x=n;return x;}
signed main()
{
	int T;
	cin>>T;
	while (T--)
	{
		rd(n);
		for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) ans[i][j]=0;
		if (n%2==1)
		for (int i=1;i<=n;i++)
		
			for (int j=1;j<=n/2;j++) ans[i][f(i+j)]=1,ans[f(i+j)][i]=-1;
		
		else
			for (int i=1;i<=n/2;i++)
			for (int j=i+1;j<=n/2;j++)
			{
				int a=i*2-1,b=i*2,c=j*2-1,d=j*2;
				ans[a][b]=ans[c][d]=ans[b][a]=ans[d][c]=0;
				ans[a][d]=ans[b][c]=ans[d][b]=ans[c][a]=1;
				ans[d][a]=ans[c][b]=ans[b][d]=ans[a][c]=-1;
				
			}
		
		for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++) printf("%lld ",ans[i][j]);puts("");
	}
}