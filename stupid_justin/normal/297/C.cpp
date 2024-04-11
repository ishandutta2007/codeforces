#include<bits/stdc++.h>
#define int long long 
#define ri register signed
#define rd(x) x=read()
using namespace std;
const int N=2e6+5;
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
int f(int b,int n)
{
	if (b==0 || b==1) return -1;
	if (n<b) return n;
	return f(b,n/b)+n%b;
}
int n,m;
int a[N],b[N];
struct Node{int x,id;}s[N];
bool cmp(Node jyz,Node wzl){return jyz.x<wzl.x;}
signed main()
{
	rd(n);for (int i=1;i<=n;i++) rd(s[i].x),s[i].id=i;m=n;
	sort(s+1,s+n+1,cmp);
	if (n%3==1) s[++n].x=s[n-1].x+1;
	if (n%3==2) s[++n].x=s[n-1].x+1;
	int k=n/3;
	for (int i=1;i<=k;i++) b[s[i].id]=i-1,a[s[i].id]=s[i].x-b[s[i].id];
	for (int i=k+1;i<=2*k;i++) a[s[i].id]=i-1,b[s[i].id]=s[i].x-a[s[i].id];
	for (int i=2*k+1;i<=3*k;i++) a[s[i].id]=3*k-i,b[s[i].id]=s[i].x-a[s[i].id];
	puts("YES");
	for (int i=1;i<=m;i++) cout<<a[i]<<" ";cout<<endl;
	for (int i=1;i<=m;i++) cout<<b[i]<<" ";
}