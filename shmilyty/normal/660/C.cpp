#include<bits/stdc++.h>
using namespace std;
int ans,ans_i,ans_j,n,k,a[300001],f[300001];
int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		f[i]=f[i-1]+(!a[i]);
	}
	for(int j=0,i=1;i<=n;i++)
	{
		while(f[i]-f[j]>k)
			j++;
		if(ans<i-j)
		{
			ans=i-j;
			ans_i=j+1;
			ans_j=i;
		}
	}
	cout<<ans<<endl; 
	for(int i=1;i<=n;i++)
		if(ans_i<=i&&i<=ans_j)
			cout<<1<<" ";
		else
			cout<<a[i]<<" ";
	return 0;
}