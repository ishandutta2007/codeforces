#include<bits/stdc++.h>

using namespace std;

int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		int z = 0;
		vector<int> v(n);
		for(auto &x : v)cin >> x;
		for(int i = 0; i < n; ++i){
			if(v[i] != i+1){
				z = i+1;
				break;
			}
		}
		for(int i = 0; i < n; ++i){
			if(v[i] == z){
				reverse(v.begin()+z-1,v.begin()+i+1);
			}
		}
		for(auto x : v)cout << x << ' ';
		cout << '\n';
	}
}