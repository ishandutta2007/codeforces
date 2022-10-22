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
	
	ll n , s;
	cin>>n>>s;
	if(n <= s / 2){
		cout<<"YES\n";
		for(int i = 0 ; i < n - 1 ; i++){
			cout<<2<<" ";
		}
		cout<<s - (n - 1) * 2<<"\n";
		cout<<1<<"\n";
	} else {
		cout<<"NO\n";
	}
	return 0;
}