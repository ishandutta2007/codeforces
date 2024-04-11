#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<int> v(n);
		for(auto &x : v)cin >> x;
		for(int i = n-1; i >= n/2; --i){
			cout << -v[i] << " ";
		}
		for(int i = n/2-1; i >= 0; --i){
			cout << v[i] << " ";
		}
		cout << "\n";	
	}
}