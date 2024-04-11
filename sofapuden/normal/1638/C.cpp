#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		int x = 0;
		int ans = 0;
		for(int i = 0; i < n; ++i){
			int z; cin >> z;
			x = max(z,x);
			if(x == i+1){
				ans++;
			}
		}
		cout << ans << '\n';
	}
}