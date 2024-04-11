
#include<bits/stdc++.h>
#define int long long
#define rd(x) x=read()
#define wt(x) write(x)
#define pos(x) (((x)-1)/SZ+1)
#define endl "\n"
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
#define ls (rt<<1)
#define rs (rt<<1|1)
#define y1 _________
using namespace std;
const int N=55;
const int M=70;
const int SZ=450;
const int mod=1e9+7;
const int inf=0x3f3f3f3f3f3f3f3f;
int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if (ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
void write(int x){if(x<0){putchar('-');x=-x;}if(x>=10)write(x/10);putchar(x%10+'0');}
int ksm(int x,int y=mod-2,int z=mod){int ret=1;while (y){if (y&1) ret=(ret*x)%z;x=(x*x)%z;y>>=1;}return ret;}
int fac[N],C[N][N],tr[N][N];
int n,p[N],v[N],cnt[N];
int prod[N],sz[N*N*N];
int f[N*N*N],q[N*N*N],w[N*N*N];
void init(int n)
{
	fac[0]=1;for (int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
	for (int i=0;i<=n;i++) C[i][0]=1;for (int i=1;i<=n;i++) for (int j=1;j<=i;j++) C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
}
signed main()
{
	rd(n);for (int i=1;i<=n;i++) rd(p[i]);
	for (int i=1;i<=n;i++) if (!v[i]){int x=i,s=0;for (;!v[x];v[x]=1,x=p[x],++s);++cnt[s];}
	init(N-1);
    for (int i=0;i<n;i++)
    {
		tr[i][0]=1;
		for (int j=0;j<=i;j++) tr[i][1]=(tr[i][1]+C[i][j]*fac[j]%mod*fac[n-j-1])%mod;
		for (int j=1;j<N;j++) tr[i][j]=tr[i][j-1]*tr[i][1]%mod;
	}
	prod[0]=f[0]=1;
	for (int i=1;i<=n;i++) prod[i]=prod[i-1]*(cnt[i]+1);
	for (int S=0;S<=prod[n]-1;S++)
    {
		int t=1;
		q[1]=0;w[1]=mod-1;
		for (int i=1;i<=n;i++)
        {
			int tmp=t,v=(S/prod[i-1])%(cnt[i]+1);sz[S]+=i*v;
            for (int j=1;j<=v;j++) for (int h=1;h<=tmp;h++) q[++t]=q[h]+j*prod[i-1],w[t]=w[h]*(j&1?mod-1:1)%mod*C[v][j]%mod;
		}
		for (int i=2;i<=t;i++) f[S]=(f[S]+f[S-q[i]]*w[i]%mod*tr[sz[S]-sz[q[i]]][sz[q[i]]])%mod;
	}
	cout<<f[prod[n]-1]<<endl;
}