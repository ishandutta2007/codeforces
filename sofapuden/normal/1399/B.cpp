#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
	int t; cin >> t;
	next:
	while(t--){
		ll n; cin >> n;
		vector<ll> a(n), b(n);
		for(auto &x : a)cin >> x;
		for(auto &x : b)cin >> x;
		int ma = *min_element(a.begin(),a.end());
		int mb = *min_element(b.begin(),b.end());
		ll ans = 0;
		for(int i = 0; i < n; ++i){
			ans+=max(a[i]-ma,b[i]-mb);
		}
		cout << ans << "\n";
			
	}
	
			
}