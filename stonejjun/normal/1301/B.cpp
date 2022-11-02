#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> pll;

ll arr[1010101];
ll brr[1010101];
ll dp[1010101];

string s1,s2,s3;

int main(){
	ll t;
	scanf("%lld",&t);
	while(t--){
		ll i,j,k,l,m,n,a,b,c,d,mini=1e10,maxi=-1e10,chamax=0;
		scanf("%lld",&n);
		for(i=1;i<=n;i++){
			scanf("%lld",&arr[i]);
		}
		arr[0]=arr[n+1]=-1;
		for(i=1;i<=n;i++){
			if(arr[i]==-1&&arr[i-1]!=-1){
				mini=min(mini,arr[i-1]);
				maxi=max(maxi,arr[i-1]);
			}
			if(arr[i]==-1&&arr[i+1]!=-1){
				mini=min(mini,arr[i+1]);
				maxi=max(maxi,arr[i+1]);
			}
			if(arr[i]!=-1&&arr[i-1]!=-1){
				chamax=max(chamax,abs(arr[i]-arr[i-1]));
			}
		}
		if(maxi==-1e10){
			printf("%lld 0\n",chamax);
			continue;
		}
		printf("%lld %lld\n",max(chamax,(maxi-mini+1)/2),(maxi+mini)/2);

	}
}