#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

ll m,d,w,t;

inline ll gcd(ll x,ll y){
	if(x < y) swap(x,y);
	return !y ? x : gcd(y,x%y);
}

int main()
{
	scanf("%lld",&t);
	while(t--){
		scanf("%lld%lld%lld",&m,&d,&w);
		ll x = (d-1+w)%w , k = w/gcd(w,x) , n = min(m,d);
		printf("%lld\n",(n-k+n%k)*(n/k)/2);
	}
}