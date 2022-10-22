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
	
	ll t , n;
	cin>>t;
	while(t--){
		ll k , f;
		cin>>n>>k;
		for(int i = 2 ; i <= n ; i++){
			if(n % i == 0){
				f = i;
				break;
			}
		}
		n += f + (k - 1) * 2;
		cout<<n<<endl;
	}
	return 0;
}