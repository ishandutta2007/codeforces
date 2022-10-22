#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MAX_N = 2e5 + 20;

ll tav(ll n , ll k){
	ll res = 1;
	while(k > 0){
		if(k & 1){
			res *= n;
		}
		n *= n;
	}
	return res;
}

ll a[MAX_N] , cnt[30];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	ll n , h = 0;
	for(int i = 0 ; i < 30 ; i++){
		cnt[i] = 0;
	}
	cin>>n;
	for(int i = 0 ; i < n ; i++){
		cin>>a[i];
		for(int j = 29 , q = 1 << 29 ; j >= 0 ; j-- , q /= 2){
			if(a[i] & q){
				h = max(h , ++cnt[j]);
				break;
			}
		}
	}
	if(h >= 3){
		cout<<"1\n";
		return 0;
	}
	h = 100;
	for(int i = 2 ; i < n ; i++){
		ll x = 0 , y;
		for(int j = i ; j >= 0 ; j--){
			x = x ^ a[j];
			y = 0;
			for(int q = j - 1 ; q >= 0 ; q--){
				y = y ^ a[q];
				if(y > x){
					h = min(h , i - q - 1ll);
					break;
				}
			}
		}
	}
	if(h == 100){
		cout<<"-1\n";
		return 0;
	}
	cout<<h<<'\n';
	return 0;
}