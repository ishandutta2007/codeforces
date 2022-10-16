#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[100001];
signed main()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	if(n==1)
	{
		cout<<1<<" "<<1<<endl<<1<<endl;
		cout<<1<<" "<<1<<endl<<1<<endl;
		cout<<1<<" "<<1<<endl<<0-2-a[1]<<endl; 
		return 0; 
	} 
	cout<<1<<" "<<n-1<<endl;
	for(int i=1;i<=n-1;i++)
	{
		cout<<a[i]*(n-1)<<" ";
		a[i]*=n;
	}
	cout<<endl<<n<<" "<<n<<endl<<0-a[n]<<endl<<1<<" "<<n<<endl;
	a[n]=0;
	for(int i=1;i<=n;i++)
		cout<<0-a[i]<<" ";
	return 0;
}