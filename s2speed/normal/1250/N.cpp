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

ll a[101];

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	ll t;
	cin>>t;
	while(t--){
		bool flag = false;
		ll n , ans = 0;
		cin>>n;
		for(int i = 0 ; i <= 100 ; i++){
			a[i] = 0;
		}
		ll h;
		for(int i = 0 ; i < n ; i++){
			cin>>h;
			a[h]++;
		}
		for(int i = 0 ; i <= 100 ; i++){
			if(flag == false && a[i] == 1){
				flag = true;
				ans += i;
			}
			if(a[i] == 0){
				if(flag == false){
					ans += i * 2;
				} else {
					ans += i;
				}
				break;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}