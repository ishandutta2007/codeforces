#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1000000007;
int n;
int qp(int power)
{
	if(power==0)
		return 1;
	if(power==1)
		return 2;
	int ans=qp(power/2);
	ans=ans*ans%mod;
	if(power&1)
		ans=ans*2%mod;
	return ans; 
}
signed main()
{
	scanf("%lld",&n);
	if(n==0)
		puts("1");
	else
		cout<<(qp(n-1)+qp(2*n-1))%mod<<endl;
	return 0;
}