#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
const int mod=1e9+7;
long long a[N],sum[N];
bool cmp (int x,int y)
{
	return x>y;
}
int main()
{
	a[1]=a[2]=1;
	for (int i=3;i<=N-5;i++)
	{
		a[i]=2*a[i-2]+a[i-1];
		a[i]%=mod;
	}	
	sum[3]=sum[4]=4;
	for (int i=5;i<=N-5;i++)
	{
		sum[i]=a[i-2]*4+sum[i-3];
		sum[i]%=mod;
	}
	int T;
	cin>>T;while(T--)
	{
		int n;
		cin>>n;
		cout<<sum[n]<<endl;
	}
	
}