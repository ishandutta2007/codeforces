#include<bits/stdc++.h>
 
using namespace std;
void solve(){
	int n; cin >> n;
	vector<int> v(n);
	for(auto &x : v)cin >> x;
	int ans = 0;
	for(int i = 0; i < n; ++i){
		ans+=v[i]&1;
	}
	cout << min(ans,n-ans) << '\n';
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--)solve();
}