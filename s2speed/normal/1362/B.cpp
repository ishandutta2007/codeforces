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

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	ll t;
	cin>>t;
	while(t--){
		bool ch = false;
		vector<ll> v , a;
		ll n , h , ans = -1;
		cin>>n;
		for(int i = 0 ; i < n ; i++){
			cin>>h;
			v.push_back(h);
		}
		sort(v.begin() , v.end());
		for(int i = 1 ; i <= 1024 && ch == false ; i++){
			a.clear();
			for(int j = 0 ; j < v.size() ; j++){
				h = v[j] ^ i;
				a.push_back(h);
			}
			sort(a.begin() , a.end());
			for(int j = 0 ; j < n ; j++){
				if(a[j] != v[j]){
					break;
				}
				if(j == n - 1){
					ch = true;
					ans = i;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}