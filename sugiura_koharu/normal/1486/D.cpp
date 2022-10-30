#include <iostream>
using namespace std;
int a[200005],qzh[200005];
int n,k;
inline bool pd(int x)
{
	for(int i=1;i<=n;i++)
	{
		if(a[i]>=x) qzh[i]=qzh[i-1]+1;
		else qzh[i]=qzh[i-1]-1;
	}
	int mn=n;
	for(int i=k;i<=n;i++)
	{
		mn=min(mn,qzh[i-k]);
		if(qzh[i]>mn) return 1;
	}
	return 0;
}
int main(int argc, char** argv) {
	cin >> n >> k;
	for(int i=1;i<=n;i++) cin >> a[i];
	int l=1,r=n,ans=0;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(pd(mid)) ans=mid,l=mid+1;
		else r=mid-1;
	}
	cout << ans;
	return 0;
}