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
int ksm(int x,int y=mod-2,int z=mod){int ret=1;while (y){if (y&1) ret=(ret*x)%z;x=(x*x)%z;y>>=1;}return ret;}

int n,k,ans,m,tot;
int c[N];
int ABS(int x){return x<0?-x:x;}
signed main()
{
	int T;cin>>T;while (T--)
	{
		rd(n);for (int i=1;i<=n;i++) rd(c[i]);
		int mn1=inf,mn2=inf,sum1=0,sum2=0,ans=inf;
		for (int i=1;i<=n;i++)
		{
			if (i%2) mn1=min(mn1,c[i]);else mn2=min(mn2,c[i]);
			if (i%2) sum1+=c[i];else sum2+=c[i];
			if (i>=2) ans=min(ans,sum1+sum2+(n-(i+1)/2)*mn1+(n-i/2)*mn2);
		}
	
		cout<<ans<<endl;
	}
}