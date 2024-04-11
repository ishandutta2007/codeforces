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
		ll a , b , c , d , ans;
		cin>>a>>b>>c>>d;
		if(b >= a){
			cout<<b<<"\n";
		} else {
			a -= b;
			if(d >= c){
				cout<<-1<<"\n";
			} else {
				ans = b;
				ans += (a + c - d - 1) / (c - d) * c;
				cout<<ans<<"\n";
			}
		}
	}
	return 0;
}