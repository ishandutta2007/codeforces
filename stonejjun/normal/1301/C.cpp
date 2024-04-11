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
		scanf("%lld %lld",&n,&m);
		a=n-m;
		b=m+1;
		c=a/b;
		d=a%b;
		printf("%lld\n",(n*(n+1)/2)-(d*(c+1)*(c+2)/2+(b-d)*c*(c+1)/2));
	}
}