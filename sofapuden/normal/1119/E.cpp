#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	ll n; cin >> n;
	vector<ll> v(n); for(auto &x : v) cin >> x;
	reverse(v.begin(),v.end());
	ll ans = 0;
	ll cu = 0;
	for(int i = 0; i < n; ++i){
		cu+=v[i]/2;
		if(v[i]&1){
			if(cu){
				cu--, ans++;
			}
		}
	}
	ans+=(cu*2)/3;
	cout << ans << '\n';
}