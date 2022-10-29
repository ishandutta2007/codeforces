#include<bits/stdc++.h>

using namespace std;

int a, b, c, d, e;

void solve(){
	int n; cin >> n;
	vector<int> v(n); for(auto &x : v) cin >> x;
	int mn = *min_element(v.begin(),v.end());
	int ans = 0;
	for(int i = 0; i < n; ++i){
		ans += v[i]-mn;

	}
	cout << ans << '\n';

}

int main(){
	int t; cin >> t;
	while(t--)solve();

}