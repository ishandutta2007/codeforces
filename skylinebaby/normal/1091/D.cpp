#include<bits/stdc++.h>
const long long N = 998244353;
using namespace std;
long long lad[1010010];
long long rev[1010010];
long long pw(long long x,int n)
{
	if(n==0) return 1;
	if(n&1) return (x*pw(x,n-1))%N;
	long long ans = pw(x,n/2);
	return (ans*ans)%N;
}
int main()
{
	lad[0] = 1;
	for(int i = 1;i<1000123;i++) lad[i] = (lad[i-1]*i)%N;
	rev[1000000] = pw(lad[1000000],N-2);
	for(int i = 1000000;i>=1;i--) rev[i-1] = (rev[i]*i)%N;
	int n;
	scanf("%d",&n);
	if(n==1) 
	{
		printf("%d\n",1);
		return 0;
	}
	long long ans = lad[n];
	for(int i = 1;i<=n-2;i++)
	{
		ans += ((lad[n]*rev[n-i])%N)*(lad[n-i]-1);
		ans %= N;
	}
	ans += N;
	ans %= N;
	printf("%lld\n",ans);
	return 0;
}