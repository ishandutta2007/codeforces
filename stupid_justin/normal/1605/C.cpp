#include<bits/stdc++.h>
#define int long long
#define rd(x) x=read()
#define wt(x) write(x)
using namespace std;
const int N=2e6+5;
const int mod=1e9+7;
int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if (ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
void write(int x){if (x<0){putchar('-');x=-x;}if (x>=10)write(x/10);putchar(x%10+'0');}
int ksm(int x,int y=mod-2,int z=mod){int ret=1;while (y){if (y&1) ret=(ret*x)%z;x=(x*x)%z;y>>=1;}return ret;}
int inv[N],fac[N],ifc[N]; 
void Init(int n)
{
    inv[1]=1;for (int i=2;i<=n;i++) inv[i]=inv[mod%i]*(mod-mod/i)%mod;
    fac[0]=1;for (int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
    ifc[0]=1;for (int i=1;i<=n;i++) ifc[i]=ifc[i-1]*inv[i]%mod;
}
int C(int n,int m){if (m<0 || m>n) return 0;return fac[n]*ifc[m]%mod*ifc[n-m]%mod;}
void add(int &x,int y) {x+=y;if (x>=mod) x-=mod;}
char s[N];
int n,ans;
void DOIT()
{
	rd(n);scanf("%s",s+1);
	ans=1e9;
	for (int i=1;i<=n;i++)
	{
		int a=0,b=0,c=0,len=0;
		for (int j=i;j<=min(i+30,n);j++)
		{
			len++;
			if (s[j]=='a') a++;else if (s[j]=='b') b++;else if (s[j]=='c') c++;
			if (a>b && a>c && len>1) {ans=min(ans,len);break;}
		}
	}
	if (ans==1e9) puts("-1");else cout<<ans<<endl;

}
signed main()
{
	int JYZ;rd(JYZ);while (JYZ--) DOIT();
}
//qwq