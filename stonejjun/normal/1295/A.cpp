#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

deque<ll> dq;

int main(){
	ll t;
	scanf("%lld",&t);
	while(t--){
		ll i,j,k,l,m,n;
		scanf("%lld",&n);
		if(n%2==0){
			for(i=1;i<=n/2;i++)
				printf("1");
		}
		else{
			printf("7");
			for(i=1;i<n/2;i++)
				printf("1");
		}
	printf("\n");
	}
	
}