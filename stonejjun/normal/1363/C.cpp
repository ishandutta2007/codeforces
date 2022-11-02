#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> pii;

#define ff first
#define ss second
#define ep emplace_back
#define eb emplace
#define pb push_back

ll arr[1010101];
string s;

int main(){
	ll t;
	scanf("%lld",&t);
	while(t--){
		ll i,j,k,l,m,n;
		scanf("%lld %lld",&n,&m);
		ll cnt1=0,cnt2=0;
		for(i=1;i<n;i++){
			scanf("%lld %lld",&k,&l);
			if(k==m) cnt1++;
			if(l==m) cnt1++;
		}
		if(cnt1<=1||n%2==0) printf("Ayush\n");
		else printf("Ashish\n"); 
	}
}