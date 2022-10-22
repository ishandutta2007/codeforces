#include<bits/stdc++.h>
 
using namespace std;

#define gcd __gcd 
typedef long long ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef double db;
 
const ll MAX_N = 2e5 + 20 , md = 1e9 + 7;
 
int tav(ll n , ll k){
	ll res = 1;
	while(k > 0){
		if(k & 1){
			res *= n;
		}
		n *= n;
		k /= 2;
	}
	return res;
}

vector<ll> a;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n , m , k = 0 , o;
	cin>>n>>m; a.resize(n);
	for(int i = 0 ; i < n ; i++){
		cin>>a[i];
	}
	sort(a.begin() , a.end());
	for(int i = 1 ; i < n ; i++){
		ll h = a[i] - a[i - 1];
		if(!h){
			continue;
		}
		k = gcd(k , h);
	}
	if(k == 0){
		for(int i = 0 ; i < m ; i++){
			ll b;
			cin>>b;
			cout<<a[0] + b<<' ';
		}
		return 0;
	}
	o = a[0] % k;
	for(int i = 0 ; i < m ; i++){
		ll b , p = o;
		cin>>b;
		p += b;
		p %= k;
		if(p == 0){
			cout<<k<<' ';
		} else {
			cout<<gcd(p , k)<<' ';
		}
	}
	return 0;
}