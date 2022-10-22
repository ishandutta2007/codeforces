#include<bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll , ll> pll;
 
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

ll a[MAX_N];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n , h , k , ans = 0 , o = 0;
	cin>>n>>h>>k;
	for(int i = 0 ; i < n ; i++){
		cin>>a[i];
		if(o + a[i] > h){
			ans += o / k;
			o %= k;
		}
		if(o + a[i] > h){
			ans++;
			o = 0;
		}
		o += a[i];
	}
	ans += (o + k - 1) / k;
	cout<<ans<<'\n';
	return 0;
}