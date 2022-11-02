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
		scanf("%lld %lld %lld",&n,&m,&k);
		if(n*(k-1)+2*__gcd(n,m)>m&&m*(k-1)+2*__gcd(n,m)>n) printf("OBEY\n");
		else printf("REBEL\n");
	}	
}