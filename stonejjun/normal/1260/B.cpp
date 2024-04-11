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
		scanf("%lld %lld",&n,&m);
		 ll a=n*2-m;
		 ll b=m*2-n;
		 if(a>=0&&b>=0&&a%3==0&&b%3==0)
		 	printf("YES\n");
		 else printf("NO\n");
	}	
}