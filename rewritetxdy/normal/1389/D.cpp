#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n,k,l1,r1,l2,r2,t;

int main()
{
	scanf("%lld",&t);
	while(t--){
		scanf("%lld%lld",&n,&k);
		scanf("%lld%lld%lld%lld",&l1,&r1,&l2,&r2);
		if(l1 > l2) swap(l1,l2) , swap(r1,r2);
		if(r1 >= l2){
			k = max(k-(min(r1,r2)-l2)*n,0ll);
			ll w = l2-l1+max(r2-r1,r1-r2);
			printf("%lld\n",w*n >= k ? k : 2*k-w*n);
		}
		else{
			ll v = l2-r1 , w = r2-l1;
			if(v > w)
				printf("%lld\n",v+2*k-min(k,w));
			else if(k/w+1 <= n)
				printf("%lld\n",k/w*(v+w)+(k >= w ? min(k%w*2,v+k%w) : v+k));
			else
				printf("%lld\n",n*(v+w)+(k-n*w)*2);
		}
	}
}