#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1000000007;
int n,muti[1000001],b[1000001];
signed main()
{
	scanf("%lld",&n);
	muti[0]=b[0]=1;
	for(int i=1;i<=n;i++)
	{
		muti[i]=(muti[i-1]*i)%mod;
		b[i]=(b[i-1]*2)%mod;
	}
	cout<<(muti[n]-b[n-1]+mod)%mod;
	return 0;
}//3