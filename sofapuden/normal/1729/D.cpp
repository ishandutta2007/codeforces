#include<bits/stdc++.h>

using namespace std;

void solve(){
	int n; cin >> n;
	vector<int> x(n), y(n);
	for(auto &z : x) cin >> z;
	for(auto &z : y) cin >> z;
	vector<int> v;
	for(int i = 0; i < n; ++i){
		v.push_back(y[i]-x[i]);
	}
	sort(v.rbegin(),v.rend());
	int ans = 0;
	int l = 0, r = n-1;
	while(l < r){
		if(v[l] + v[r] >= 0)ans++, r--, l++;
		else r--;
	}
	cout << ans << '\n';

}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--)solve();

}