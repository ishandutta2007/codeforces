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
ll a[200000];

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	ll t;
	cin>>t;
	while(t--){
		ll n , k , h = -1e10 , o = 1e10 , q;
		cin>>n>>k;
		for(int i = 0 ; i < n ; i++){
			cin>>a[i];
			h = max(h , a[i]);
			o = min(o , a[i]);
		}
		q = h - o;
		for(int i = 0 ; i < n ; i++){
			a[i] = h - a[i];
		}
		k--;
		if(k % 2 == 0){
			for(int i = 0 ; i < n ; i++){
				cout<<a[i]<<" ";
			}
			cout<<"\n";
		} else {
			for(int i = 0 ; i < n ; i++){
				cout<<q - a[i]<<" ";
			}
			cout<<"\n";
		}
	}
	return 0;
}