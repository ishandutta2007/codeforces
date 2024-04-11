#include<bits/stdc++.h>

using namespace std;

int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		map<int,int> M;
		for(int i = 0; i < n; ++i){
			int x; cin >> x;
			M[x]++;
		}
		int mx = 0;
		for(auto x : M){
			mx = max(mx,x.second);
		}
		int ans = n-mx;
		while(mx < n){
			ans++;
			mx*=2;
		}
		cout << ans << '\n';
	}


}