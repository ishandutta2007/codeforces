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
		ll n , ans , a[40] , h;
		cin>>n;
		for(int i = 1 ; i < 40 ; i++){
			if(n < tav(2 , i + 1)){
				ans = i;
				break;
			}
		}
		cout<<ans<<endl;
		if(ans == 1){
			cout<<n - 2<<endl;
		} else {
			for(int i = 0 ; i < ans - 2 ; i++){
				a[i] = tav(2 , i);
			}
			h = min(n - tav(2 , ans) + 1 , tav(2 , ans - 1));
			a[ans - 2] = h / 2;
			a[ans - 1] = (n - tav(2 , ans) + 1) - a[ans - 2] * 2;
			for(int i = 0 ; i < ans ; i++){
				cout<<a[i]<<" ";
			}
			cout<<endl;
		}
	}
	return 0;
}