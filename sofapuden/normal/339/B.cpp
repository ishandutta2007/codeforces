#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
	ll n, m; cin >> n >> m;
	ll cu = 1;
	ll ans = 0;
	for(ll i = 0, tmp; i < m; ++i){
		cin >> tmp;
		if(tmp < cu){
			ans += n - cu + tmp;
		}
		else{
			ans += tmp - cu;
		}
		cu = tmp;
	}
	cout << ans << "\n";
	
}