#include<bits/stdc++.h>
#define int long long
using namespace std; 
int n,a[200001],b[200001],c[200001];
bool cmp(int x,int y)
{
	return x<y;
}
int work(int x)
{
	int l=1,r=n;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(c[mid]+c[x]>0)
			r=mid-1;
		else
			l=mid+1;
	}
	return min(n-l+1,n-x);
}
signed main()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&b[i]);
		c[i]=a[i]-b[i];
	}
	sort(c+1,c+1+n,cmp);
	int ans=0;
	for(int i=1;i<=n;i++)
		ans+=work(i);
	cout<<ans;
	return 0;
}