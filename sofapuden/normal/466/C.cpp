#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
	int n; cin >> n;
	vector<int> v(n); for(auto &x : v) cin >> x;
	ll su = accumulate(v.begin(),v.end(),0ll);
	if(su == 0){
		ll ans = 0;
		ll cu = 0;
		for(int i = 0; i < n; ++i){
			cu+=v[i];
			if(!cu)ans++;
		}
		ans--;
		cout << 1ll*ans*(ans-1)/2;
		return 0;
	}
	if(su%3){
		cout << 0 << '\n';
		return 0;
	}
	ll ans[3];
	ans[0] = 1;
	ans[1] = ans[2] = 0;
	ll cu = 0;
	for(int i = 0; i < n; ++i){
		cu+=v[i];
		if(!(cu%(su/3)) && (cu/(su/3)) >= 1 && (cu/(su/3)) <= 2){
			ans[cu/(su/3)] += ans[cu/(su/3)-1];
		}
	}
	cout << ans[2] << '\n';
}