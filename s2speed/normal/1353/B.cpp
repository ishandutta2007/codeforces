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

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	ll t;
	cin>>t;
	while(t--){
		vector<ll> a , b;
		ll n , k , h , ans = 0;
		cin>>n>>k;
		for(int i = 0 ; i < n ; i++){
			cin>>h;
			ans += h;
			a.push_back(h);
		}
		for(int i = 0 ; i < n ; i++){
			cin>>h;
			b.push_back(h);
		}
		sort(a.begin() , a.end());
		sort(b.begin() , b.end());
		for(int x = 0 , y = n - 1 ; x < k ; x++ , y--){
			if(a[x] >= b[y]){
				break;
			}
			ans += b[y] - a[x];
		}
		cout<<ans<<"\n";
	}
	return 0;
}