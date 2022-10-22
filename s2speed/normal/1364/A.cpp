#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

ll tav(ll n , ll k){
	if(k == 0){
		return 1;
	}
	ll x = tav(n , k / 2);
	if(k % 2 == 0){
		return x * x;
	} else {
		return x * x * n;
	}
}

const ll z = 0;
ll a[100001];

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	ll t;
	cin>>t;
	while(t--){
		ll n , x , h , sum = 0 , ans = -1;
		cin>>n>>x;
		a[0] = 0;
		for(int i = 1 ; i <= n ; i++){
			cin>>h;
			sum += h;
			sum %= x;
			a[i] = sum;
		}
		for(int i = 0 ; i < n ; i++){
			if(a[n] != a[i]){
				ans = n - i;
				break;
			}
		}
		for(ll i = n ; i > 0 ; i--){
			if(a[0] != a[i]){
				ans = max(i , ans);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}