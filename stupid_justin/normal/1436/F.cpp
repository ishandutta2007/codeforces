#include<bits/stdc++.h>
#define int long long
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
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
const int N=2e5+5;
const int M=70;
const int SZ=450;
const int mod=998244353;
const int inf=0x3f3f3f3f3f3f3f3f;
int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if (ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
void write(int x){if(x<0){putchar('-');x=-x;}if(x>=10)write(x/10);putchar(x%10+'0');}
int ksm(int x,int y=mod-2,int z=mod){int ret=1;while (y){if (y&1) ret=(ret*x)%z;x=(x*x)%z;y>>=1;}return ret;}
void gmin(int &x,int y){x=min(x,y);}
int n,x,mu[N],c[N];
signed main()
{
    rd(n);while (n--) rd(x),rd(c[x]);
	mu[1]=1;for (int i=1;i<N;i++) for (int j=i*2;j<N;j+=i) mu[j]-=mu[i];
	int ans=0;
	for (int i=1;i<N;i++)
    {
		int A=0,B=0,C=0;
		for (int j=i;j<N;j+=i) A+=c[j],B=(B+c[j]*j)%mod,C=(C+c[j]*j%mod*j)%mod;
		if(A<2) continue;
		int a=C*ksm(2,A-2)%mod*((A-1)%mod)%mod;
		int b=ksm(2,A-2);
		if (A>=3) b=(b+((A-2)%mod)*ksm(2,A-3))%mod;
		b=(B*B-C)%mod*b%mod;
		ans=(ans+(a+b)*mu[i])%mod;
	}
	cout<<(ans+mod)%mod<<endl;
}