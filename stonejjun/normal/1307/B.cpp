#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll arr[1010101];
ll brr[1010101];

int main(){
	ll t;
	scanf("%lld",&t);
	while(t--){
		ll i,j,k,l,m,n,chk=0;
		scanf("%lld %ld",&n,&m);
		ll arr[101010]={0,};
		for(i=1;i<=n;i++){
			scanf("%lld",&arr[i]);
			if(arr[i]==m) chk=1;
		}
		sort(arr+1,arr+1+n);
		if(arr[n]>=m){
			if(chk) printf("1\n");
			else printf("2\n");
			continue;
		}
		if(m%arr[n]==0) printf("%lld\n",m/arr[n]);
		else printf("%lld\n",(m/arr[n])+1);
	}
	
}