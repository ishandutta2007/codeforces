#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2005;
const int mod=1e9+7;
struct point
{
	int x,y;
	bool operator < (const point& o) const 
	{
		if (x==o.x) return y<o.y;
		return x<o.x;
	}
};
point P[N];
int n,m,k;
int dp[N],fac[N*N];
int ksm(int x,int y){int ret=1;while (y){if (y&1) ret=(ret*x)%mod;x=(x*x)%mod;y>>=1;}return ret;}
int inv(int x){return ksm(x,mod-2);}
int C(int x,int y)
{
	if (x<0 || y<0 || x<y) return 0;
	return (fac[x]*inv(fac[x-y])%mod)*inv(fac[y])%mod;
}
signed main()
{
	cin>>n>>m>>k;
	fac[0]=fac[1]=1;
	for (int i=2;i<=n+m;i++) fac[i]=(fac[i-1]*i)%mod;
	// for (int i=0;i<=10;i++) printf("%lld ",(fac[i]));printf("\n");
	//for (int i=0;i<=10;i++) printf("%lld ",inv(fac[i]));printf("\n");
	for (int i=1;i<=k;i++) cin>>P[i].x>>P[i].y;
	sort(P+1,P+k+1);
	if (P[k].x==n && P[k].y==m) cout<<0<<endl;
	else
	{
		k++;P[k].x=n;P[k].y=m;
		for (int i=1;i<=k;i++)
		{
			dp[i]=C(P[i].x+P[i].y-2,P[i].x-1);
			for (int j=1;j<i;j++)
				if (P[j].y<=P[i].y) 
					dp[i]=((dp[i]-dp[j]*(C(P[i].x-P[j].x+P[i].y-P[j].y,P[i].x-P[j].x)%mod))%mod+mod)%mod;
			
		}
		cout<<dp[k]<<endl;
	}
	
}