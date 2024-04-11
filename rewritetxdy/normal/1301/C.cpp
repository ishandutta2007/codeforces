#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm> 

using namespace std;
typedef long long ll;

//l=i:0 -> 1 3 6 10 ... = n*(n+1)/2
ll t,n,m,ans;

int main()
{
	scanf("%lld",&t);
	while(t--){
		scanf("%lld%lld",&n,&m);
		ll l = (n-m)/(m+1);
		ll cnt = (n-m)%(m+1);
		ans = n*(n+1)/2;
		ans -= cnt*(l+1)*(l+2)/2;
		ans -= (m+1-cnt)*l*(l+1)/2;
		printf("%lld\n",ans);
	}
}