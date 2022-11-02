#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

ll t,n,p,f[50],sum[50],z[50];

inline ll logg(ll x){
	ll cnt = 0;
	while(x) cnt++ , x >>= 1;
	return cnt;
}

int main()
{
	f[1] = z[0] = sum[1] = 1;
	for(int i=1;i <= 30;i++) z[i] = z[i-1] << 1;
	scanf("%lld",&t);
	while(t--){
		scanf("%lld%lld",&n,&p);
		for(int i=2;i <= 30;i++) f[i] = (sum[i-1]+1)*z[i-1]%p , sum[i] = (sum[i-1]+f[i])%p;
		printf("%lld\n",(sum[logg(n)]-(z[logg(n)]-1-n)*(sum[logg(n)-1]+1)%p+p)%p);
	}
}