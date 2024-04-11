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
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	ll t;
	cin>>t;
	while(t--){
		ll n , x , y , d , m , p;
		cin>>n>>x>>y; p = n; d = y - x; n -= 2;
		for(int i = 1 ; i <= d ; i++){
			if(d % i == 0 && d / i - 1 <= n){
				m = i;
				break;
			}
		}
		n -= d / m - 1;
		n -= (x - 1) / m;
		ll h;
		if(n >= 1){
			h = x % m;
			if(h == 0) h = m;
			for(int i = 0 ; i < p ; i++){
				cout<<h<<" ";
				h += m;
			}
		} else {
			h = x % m; if(h == 0) h = m;
			h += (0 - n) * m;
			for(int i = 0 ; i < p ; i++){
				cout<<h<<" ";
				h += m;
			}
		}
		cout<<"\n";
	}
	return 0;
}