#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

const ll md = 1e9 + 7;

ll tav(ll n , ll k){
	if(k == 0){
		return 1;
	}
	ll x = tav(n , k / 2);
	if(k % 2 == 0){
		return (x * x) % md;
	} else {
		return (((x * x) % md) * n) % md;
	}
}
ll f[1000001];

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	f[1] = 1;
	for(int i = 2 ; i <= 1e6 ; i++){
		f[i] = (f[i - 1] * i) % md;
	}
	ll n , ans;
	cin>>n;
	ans = (f[n] - tav(2 , n - 1) + md) % md;
	cout<<ans<<"\n";
	return 0;
}