#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,m,d,w;
signed main()
{
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld%lld",&m,&d,&w);
		w=w/__gcd(w,d-1);
		int n=min(m,d);
		int num=n/w;
		int ans=(2*n-w*num-w)*num/2;
		cout<<ans<<endl;
	}
	return 0;
}