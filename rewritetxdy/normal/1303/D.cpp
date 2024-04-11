#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
typedef long long ll;

ll t,n,m,c[70],f[70],sum[70]; 

inline ll cal(ll x){
	ll cnt = -1;
	while(x)
		x >>= 1 , cnt++;
	return cnt;
}

int main()
{
	scanf("%lld",&t);
	while(t--){
		memset(f,0,sizeof(f));
		memset(c,0,sizeof(c));
		scanf("%lld%lld",&n,&m);
		ll x = 0,cnt = 0,w = n;
		while(n){
			if(n&1) f[x] = 1;
			n >>= 1 , x++;
		}
		for(ll i=1;i <= m;i++)
			scanf("%lld",&x) , c[cal(x)]++;
		for(ll i=0;i <= 64;i++)
			if(f[i] && c[i])
				f[i] = 0 , c[i]-- , w -= (1ll<<i);
		sum[0] = c[0];
		for(ll i=1;i <= 64;i++)
			sum[i] = sum[i-1]+c[i]*(1ll<<i);
		ll flag = 0;
		for(ll i=64;i >= 0;i--)
			if(f[i]){
				if(sum[i] >= w){
					w -= (1ll<<i);
					continue;
				}
				ll x=i+1;
				while(!c[x] && x <= 64) x++;
				if(x > 64){
					puts("-1");
					flag = 1;
					break;
				}
				cnt += x-i;
				c[i]++;
				w -= (1ll<<i);
			}
		if(!flag)
			printf("%lld\n",cnt);
	}
}