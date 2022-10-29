#include<bits/stdc++.h>

using namespace std;

void solve(){
	int n, k; cin >> n >> k;
	vector<int> v(n);
	for(auto &x : v)cin >> x;
	if(k == 1){
		cout << (n-1)/2 << '\n';
	}
	else{
		int ans = 0;
		for(int i = 1; i < n-1; ++i){
			if(v[i] > v[i-1] + v[i+1])ans++;
		}
		cout << ans << '\n';

	}
}

int main(){
	int t; cin >> t;
	while(t--)solve();
}