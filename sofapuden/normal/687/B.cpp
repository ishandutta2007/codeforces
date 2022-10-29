#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll n, k; cin >> n >> k;
	ll cu = 1;
	for(int i = 0; i < n; ++i){
		ll x; cin >> x;
		cu = lcm(x,cu);
		cu%=k;
	}
	if(cu == 0){
		cout << "Yes\n";
	}
	else{
		cout << "No\n";
	}
}