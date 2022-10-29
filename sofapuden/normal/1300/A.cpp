#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n; cin >> n;
	int ans = 0;
	int sum = 0;
	for(int i = 0; i < n; ++i){
		int tmp; cin >> tmp;
		if(tmp == 0){
			tmp++;
			ans++;
		}
		sum+= tmp;
	}
	cout << (sum == 0 ? ans+1 : ans) << "\n";
}

int main(){
	int t; cin >> t;
	while(t--){
		solve();
	}
	return 0;	
}