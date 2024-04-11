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

const int N=2e5+5;
const int mod=1e9+7;
const int inf=3e18;
inline int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
int ksm(int x,int y=mod-2,int z=mod){int ret=1;while (y){if (y&1) ret=(ret*x)%z;x=(x*x)%z;y>>=1;}return ret;}

int n,k,ans,m;
int a[N],b[N];
void solve(int n,int k)
{
	
	if (k==3)
	{
		
		if (n%2==1) printf("%lld %lld 1\n",n/2,n/2);
		else if (n%4==2) printf("%lld %lld %lld\n",n/2-1,n/2-1,2);
		else printf("%lld %lld %lld\n",n/2,n/4,n/4);
		return;
	}

}
signed main()
{
	int T;cin>>T;while (T--)
	{
		rd(n);rd(k);
		for (int i=4;i<=k;i++) printf("1 ");
		solve(n-k+3,3);
		
	}
}