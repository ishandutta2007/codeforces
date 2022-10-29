#include <bits/stdc++.h>

using namespace std;

int main(){
	int t; cin >> t;
	next:
	while(t--){
		int n; cin >> n;
		vector<int> v(n);
		for(auto &x : v)cin >> x;
		sort(v.begin(), v.end());
		for(int i = 1; i < n; ++i){
			if(v[i]-v[i-1] > 1){
				cout << "NO\n";
				goto next;
			}
		}
		cout << "YES\n";
	}
	
			
}