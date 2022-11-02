#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> pii;
#define ff first 
#define ss second

ll arr[1010101];
int main(){
	ll i,j,k,l,m,n,t;
	scanf("%lld",&t);
	while(t--){
		ll ans=0;
		scanf("%lld %lld",&n,&m);
		for(i=1;i<=n;i++){
			arr[i]=m/n;
		}
		for(i=1;i<=m%n;i++)
			arr[i]++;
		for(i=1;i<=n;i++)
			ans+=arr[i]*arr[i];
		printf("%lld\n",ans);
	}	
}