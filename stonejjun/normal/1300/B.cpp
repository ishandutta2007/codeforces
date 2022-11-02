#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
	ll t;
	scanf("%lld",&t);
	while(t--){
		ll arr[201010]={0,};
		ll i,j,k,l,m,n,cnt=0,sum=0,ans=0;
		scanf("%lld",&n);
		for(i=1;i<=2*n;i++)
			scanf("%lld",&arr[i]);
		sort(arr+1,arr+1+2*n);
		printf("%lld\n",arr[n+1]-arr[n]);
	}
}