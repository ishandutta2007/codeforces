#include<bits/stdc++.h>

using namespace std;

void solve(){
	int n; cin >> n;
	vector<int> v(n);
	for(auto &x : v)cin >> x;
	int ze = 0;
	for(int i = 0; i < n; ++i){
		if(v[i] == 0)ze++;
	}
	int ans = 0;
	for(int i = 0; i < ze; ++i){
		ans+=v[i];
	}
	cout << ans << '\n';
}

int main(){
	int t; cin >> t;
	while(t--)solve();
}