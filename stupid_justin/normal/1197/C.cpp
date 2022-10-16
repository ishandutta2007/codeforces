#include<bits/stdc++.h>
using namespace std;
const int N=300005;
const int MOD1=1e9+7;
const int MOD2=998244353;
int q,n,k,ans,max1,max2;
int a[N],b[N];
int main()
{
	cin>>n>>k;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for (int i=1;i<=n-1;i++)
	{
		b[i]=a[i+1]-a[i];
	}
//	for (int i=1;i<=n-1;i++) printf("%d ",b[i]);printf("\n");
	sort(b+1,b+n);
//	for (int i=1;i<=n-1;i++) printf("%d ",b[i]);printf("\n");
	for (int i=n-1;i>=n-k+1;i--)
	{
		ans+=b[i];
	}
	cout<<a[n]-a[1]-ans<<endl;
}