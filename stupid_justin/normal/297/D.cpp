#include<bits/stdc++.h>
#define int long long 
#define ri register signed
#define rd(x) x=read()
using namespace std;
const int N=5000+5;
const int M=1e6+5;
const int maxn=5e6+5;
const int mod=1e9+7;
const int inf=0x3f3f3f3f3f3f3f3f;
inline int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
inline int ksm(int x,int y=mod-2,int z=mod){int ret=1;while (y){if (y&1) ret=(ret*x)%z;x=(x*x)%z;y>>=1;}return ret;}
int inv[N],fac[N],ifc[N]; 
void Init(int n)
{
    inv[1]=1;for (ri i=2;i<=n;i++)inv[i]=inv[mod%i]*(mod-mod/i)%mod;
    fac[0]=1;for (ri i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
    ifc[0]=1;for (ri i=1;i<=n;i++) ifc[i]=ifc[i-1]*inv[i]%mod;
}
int C(int n,int m){if (m>n || m<0) return 0;return fac[n]*ifc[m]%mod*ifc[n-m]%mod;}
int h,w,k,tot;
int a[N][N];
char b1[N][N],b2[N][N];
signed main()
{
	rd(h);rd(w);rd(k);
	for (int i=1;i<=h;i++)
	{
		scanf("%s",b1[i]+1);
		if (i!=h) scanf("%s",b2[i]+1);
	}
	if (k==1)
	{
		for (int i=1;i<=h;i++) for (int j=1;j<w;j++) if (b1[i][j]=='E') tot++;
		for (int i=1;i<h;i++) for (int j=1;j<=w;j++) if (b1[i][j]=='E') tot++;
		if (tot>=((w*(h-1)+(w-1)*h)*3+3)/4) 
		{
			puts("YES");
			for (int i=1;i<=h;i++) {for (int j=1;j<=w;j++) cout<<"1 ";cout<<endl;}
		}
		else puts("NO");
		return 0;
		
	} else 
	{
		if ((h-1)*w<=(w-1)*h)
		{
			for (int i=1;i<=h;i++)
			{
				a[i][1]=1;for (int j=2;j<=w;j++) if (b1[i][j-1]=='E') a[i][j]=a[i][j-1];else a[i][j]=3-a[i][j-1];
				tot=0;
				if (i!=1)
				{
					for (int j=1;j<=w;j++) 
					{
						if (b2[i-1][j]=='E' && a[i][j]==a[i-1][j]) tot++;
						if (b2[i-1][j]=='N' && a[i][j]!=a[i-1][j]) tot++;
					}
					if (tot<(w+1)/2) for (int j=1;j<=w;j++) a[i][j]=3-a[i][j];
				}
			}
		} else 
		{
			for (int j=1;j<=w;j++)
			{
				a[1][j]=1;for (int i=2;i<=h;i++) if (b2[i-1][j]=='E') a[i][j]=a[i-1][j];else a[i][j]=3-a[i-1][j];			
				tot=0;
				if (j!=1)
				{
					for (int i=1;i<=h;i++)
					{
						if (b1[i][j-1]=='E' && a[i][j]==a[i][j-1]) tot++;
						if (b1[i][j-1]=='N' && a[i][j]!=a[i][j-1]) tot++;
					}
					if (tot<(h+1)/2) for (int i=1;i<=h;i++) a[i][j]=3-a[i][j];
				}
			}
		}
		puts("YES");
		for (int i=1;i<=h;i++) {for (int j=1;j<=w;j++) cout<<a[i][j]<<" ";cout<<endl;}

	}
}