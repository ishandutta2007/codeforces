#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#define int long long
using namespace std;
int a[1000005],r[1000005],M,qwq[1000005];
inline int gcd(int x,int y)
{
	if(x>y) swap(x,y);
	while(x) y%=x,swap(x,y);
	return y; 
}
inline int ask(int x)
{
	int rtn=0;
	for(int i=1;i<=1000000;i++)
	{
		if(r[i]>=0)
			rtn+=x/M+(x%M>=r[i])-(r[i]==0);
	}
	//cout << x << " " << rtn <<"\n"; 
	return x-rtn;
}
signed main() {
	int n,m,k;
	scanf("%lld%lld%lld",&n,&m,&k),M=n*m/gcd(m,n);
	for(int i=0;i<=1000000;i++) qwq[i]=-1;
	for(int i=0;i<m;i++) qwq[i*n%m]=i%M;
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%lld",&x),a[x]=i;
	}
	for(int i=1;i<=1000000;i++) r[i]=-1;
	for(int i=1;i<=m;i++)
	{
		int x;
		scanf("%lld",&x);
		if(a[x])
		{
			int A=a[x],B=i;
		//	cout << A << " " << B << " " << qwq[B] << "\n";
			B=((B-A)%m+m)%m;
			if(qwq[B]>=0) r[x]=(qwq[B]*n+A)%M;
		//	cout << " " << r[x] << "\n";
		}
	}
//	for(int i=1;i<=n+m;i++) cout << r[i] << " ";
	//puts("");
	int l=0,r=1e18,ans=0;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(ask(mid)>=k) ans=mid,r=mid-1; 
		else l=mid+1;
	}
	cout << ans;
	return 0;
}