#include<bits/stdc++.h>

using namespace std;

int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<int> v(n);
		for(auto &x : v)cin >> x;
		bool ok = 0;
		int ans = 0;
		for(int i = 0; i < n; ++i){
			if(v[i] != i+1){
				if(ok)continue;
				ans++;
				ok = 1;
			}
			else{
				ok = 0;
			}
		}
		cout << min(ans,2) << '\n';
	}
}