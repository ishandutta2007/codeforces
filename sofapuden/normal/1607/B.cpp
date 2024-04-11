#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(){
	ll x, n; cin >> x >> n;
	if(n % 4 == 0)cout << x << '\n';
	else if(n % 4 == 1){
		cout << x+(x&1 ? n : -n) << '\n';
	}
	else if(n%4 == 2){
		cout << x + (x&1 ? -1 : 1) << '\n';
	}
	else{
		cout << x + (x&1 ? -n-1 : n+1) << '\n';

	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1; cin >> t;
	while(t--){
		solve();
	}
}