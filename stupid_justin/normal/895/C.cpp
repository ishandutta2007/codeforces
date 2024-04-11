#include<bits/stdc++.h>
#define int long long 
#define ri register signed
#define rd(x) x=read()
using namespace std;
const int N=3e5+5;
const int M=60;
const int maxn=5e6+5;
const int mod=1e9+7;
const int inv2=5e8+4;
const int inv4=2.5e8+2;
const int inf=0x3f3f3f3f3f3f3f3f;
inline int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
inline int ksm(int x,int y=mod-2,int z=mod){int ret=1;while (y){if (y&1) ret=(ret*x)%z;x=(x*x)%z;y>>=1;}return ret;}
int m;
struct LB
{
	int a[M+1],b[M+1];
	bool zero=0;
	void clear(){memset(a,0,sizeof(a));zero=0;}
	void insert(int x){for (int i=M;i>=0;i--) if (x&(1LL<<i)) if (!a[i]) {a[i]=x;return;}else x^=a[i];zero=1;m++;}
	bool chk(int x){for (int i=M;i>=0;i--)if(x&(1LL<<i))if(!a[i])return 0;else x^=a[i];return 1;}
	int Max(){int ret=0;for (int i=M;i>=0;i--)ret=max(ret,ret^a[i]);return ret;}
	int Min(){if (zero)return 0;for (int i=0;i<=M;i++)if (a[i])return a[i];}
	int kth(int k)
	{
		int ret=0,cnt=0;
		k-=zero;if (!k) return 0;
		for (int i=0;i<=M;i++) {for (int j=i-1;j>=0;j--) if (a[i]&(1LL<<j)) a[i]^=a[j];if (a[i]) b[cnt++]=a[i];}
		if (k>=(1LL<<cnt)) return -1;
		for (int i=0;i<cnt;i++) if (k&(1LL<<i)) ret^=b[i];
		return ret;
	}
}lb;
int n,cnt;
int p[N],v[N];
signed main()
{
	for (int i=2;i<=70;i++) if (!v[i]) for (int j=i+i;j<=70;j+=i) v[j]=1;
	for (int i=2;i<=70;i++) if (!v[i]) 
	{
		cnt++;
		for (int j=i;j<=70;j+=i){int x=j;while (x%i==0) p[j]^=1<<cnt-1,x/=i;}
	}
	
	rd(n);for (int i=1;i<=n;i++) lb.insert(p[read()]);
	cout<<ksm(2,m)-1<<endl;
}