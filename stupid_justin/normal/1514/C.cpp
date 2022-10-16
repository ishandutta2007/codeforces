#include<bits/stdc++.h>
#define int long long
#define ls (rt<<1)
#define rs (rt<<1|1)
#define pii pair<int,int>
#define fi first
#define se second
#define rd(x) x=read()
#define endl '\n'
using namespace std;

const int N=1e6+5;
const int M=1e7+5;
const int mod=1e9+7;
const int inf=3e18;
inline int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
int ksm(int x,int y=mod-2,int z=mod){int ret=1;while (y){if (y&1) ret=(ret*x);x=(x*x);y>>=1;}return ret;}


int n,t,tmp=1;
int a[N];
signed main()
{
	rd(n);

		for (int i=1;i<=n-1;i++) if (__gcd(i,n)==1) a[++t]=i;
		for (int i=1;i<=t;i++) tmp=tmp*a[i]%n;
		if (tmp==1)
		{
			cout<<t<<endl;
			for (int i=1;i<=t;i++) cout<<a[i]<<" ";
		} else 
		{
			cout<<t-1<<endl;
			for (int i=1;i<=t;i++) if (a[i]!=tmp) cout<<a[i]<<" ";
		}

}