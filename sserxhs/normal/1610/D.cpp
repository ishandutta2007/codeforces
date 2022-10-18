#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+2,p=1e9+7;
int a[N],b[N],s[32],sum[32];
int ksm(int x,int y)
{
	int r=1;
	while (y)
	{
		if (y&1) r=(ll)r*x%p;
		x=(ll)x*x%p;
		y>>=1;
	}
	return r;
}
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	int n,i,j,m=0,q=0,ans=0;
	cin>>n;
	for (i=1;i<=n;i++) cin>>b[i];
	for (i=1;i<=n;i++) if (b[i]&1) ++q; else a[++m]=b[i];
	n=m;ans=(ll)ksm(2,n)*(ksm(2,q)+p-1)%p;
	for (i=1;i<=n;i++) ++s[__builtin_ctz(a[i])];
	//cout<<ans<<endl;
	//for (i=1;i<=30;i++) cout<<s[i]<<" \n"[i==30];
	for (i=30;i>=1;i--) sum[i]=sum[i+1]+s[i];
	for (i=1;i<=30;i++) if (s[i]) ans=(ans+(ll)(ksm(2,s[i]-1)+p-1)*ksm(2,sum[i+1]))%p;
	cout<<ans<<endl;
}
/*
12391240
103904
1000000000
4142834
1032840
*/