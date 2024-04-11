#include<bits/stdc++.h>
#define int long long
#define ri register signed
#define rd(x) x=read()
using namespace std;
const int N=5e5+5;
const int M=805;
const int mod=998244353;
inline int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
inline int ksm(int x,int y=mod-2,int z=mod){int ret=1;while (y){if (y&1) ret=(ret*x)%z;x=(x*x)%z;y>>=1;}return ret;}
int n,m,sum;
int a[N],v[N];
signed main()
{
	m=200000;
    rd(n);for (int i=1;i<=n;i++) rd(a[i]);
	for (int i=1;i<=n;i++) sum+=a[i];
	if (sum%2==1) {puts("0");return 0;}
	v[0]=1;
	for (int i=1;i<=n;i++)
	{
		for (int j=0;j<=m;j++) if (v[j]==1 && v[j+a[i]]==0) v[j+a[i]]=2;
		for (int j=0;j<=m;j++) if (v[j]==2) v[j]=1;
	}
	if (v[sum/2]==0) {puts("0");return 0;}
	int g=a[1];for (int i=2;i<=n;i++) g=__gcd(g,a[i]);
	for (int i=1;i<=n;i++) a[i]/=g;
	for (int i=1;i<=n;i++) if (a[i]%2==1)
	{
		printf("1\n%lld\n",i);return 0;
	}

}