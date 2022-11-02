#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll brr[1010101];

int main(){
	ll t;
	scanf("%lld",&t);
	while(t--){
		ll i,j,k,l,m,n;
		ll arr[501]={0,};
		scanf("%lld %lld",&n,&m);
		for(i=1;i<=n;i++){
			scanf("%lld",&arr[i]);
		}
		ll ans=arr[1];
		for(i=2;i<=n;i++){
			if(m<=(i-1)*arr[i]){
				ans+=(m/(i-1));
				break;
			}
			ans+=arr[i];
			m-=(arr[i]*(i-1));
		}
		printf("%lld\n",ans);
	}


}