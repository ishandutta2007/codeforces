#include <bits/stdc++.h>
using namespace std;
#if !defined(ONLINE_JUDGE)&&defined(LOCAL)
#include "my_header\debug.h"
#else
#define dbg(...) ;
#define dbgn(...) ;
#endif
typedef unsigned int ui;
typedef unsigned long long ll;
#define all(x) (x).begin(),(x).end()
const int N=5e3+5;
const ui p=998244353;
int a[N],pre[N],fir[N],ed[N],cnt[N];
ui f[N][N],s[N],ts[N],fac[N];
void inc(ui &x,ui y){if ((x+=y)>=p) x-=p;}
ui ksm(ll x,int y)
{
	ll r=1;
	while (y)
	{
		if (y&1) r=r*x%p;
		x=x*x%p;y>>=1;
	}
	return r;
}
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int T;cin>>T;
	fac[0]=1;
	for (int i=1;i<N;i++) fac[i]=(ll)fac[i-1]*i%p;
	while (T--)
	{
		int n,m,i,j,k;
		cin>>n;
		fill_n(cnt,n+1,0);
		int cur=0;
		for (i=1;i<=n;i++) cin>>a[i],cnt[a[i]]++;
		for (i=1,j=0;i<=n;i++)
		{
			while (j<=n&&a[j+1]<i) cur+=ed[++j];
			pre[i]=j;
		}
		i=2;
		for (j=1;j<=n;j++) f[2][j]=cnt[j]*pre[j];
		fill_n(s,n+1,0);
		for (j=1;j<=n;j++) s[j]=(s[j-1]+(ll)f[i][j]*max(0,pre[j]-(i-1)))%p;
		for (i=4;i<=n;i+=2)
		{
			for (j=1;j<=n;j++)
			{
				f[i][j]=(ll)cnt[j]*s[j-1]%p;
				//for (k=0;k<j;k++) if (pre[k]>i-3) f[i][j]=(f[i][j]+(ll)(pre[k]-(i-3))*f[i-2][k]*cnt[j])%p;
				//f[i][j]=(p+(ll)pre[j]*s[j-1]-ts[j-1])%p;
				//dbgn(i,j,f[i][j]);
			}
			fill_n(s,n+1,0);
			for (j=1;j<=n;j++) s[j]=(s[j-1]+(ll)f[i][j]*max(0,pre[j]-(i-1)))%p;
			
		}
		ui ans=0;
		for (i=0;i<=n;i++) inc(ans,f[n][i]);
		for (i=1;i<=n;i++) ans=(ll)ans*ksm(fac[cnt[i]],p-2)%p;
		cout<<ans<<'\n';
	}
}