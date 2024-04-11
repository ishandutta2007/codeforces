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

ll m(ll n){
	ll mi , ma;
	ma = n % 10;
	mi = ma;
	n /= 10;
	while(n > 0 && mi != 0){
		if(n % 10 > ma){
			ma = n % 10;
		} else if(n % 10 < mi){
			mi = n % 10;
		}
		n /= 10;
	}
	return mi * ma;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	ll t;
	cin>>t;
	while(t--){
		ll n , k;
		cin>>n>>k;
		while(m(n) != 0 && k > 1){
			n += m(n);
			k--;
		}
		cout<<n<<endl;
	}
	return 0;
}