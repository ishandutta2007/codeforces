#include<bits/stdc++.h>

using namespace std;

void solve(int testID){
	int n; cin >> n;
	int ls = -1000000005;
	int am = 0;
	vector<int> v(n);for(auto &x : v){cin >> x;if(x < 0)am++;}
	for(int i = 0; i < n; ++i){
		if(i < am)v[i] = -abs(v[i]);
		else v[i] = abs(v[i]);
	}
	for(int i = 1; i < n; ++i){
		if(v[i] < v[i-1]){
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
}

int main(){
	int t; cin >> t;
	int cn = 1;
	while(t--){
		solve(cn++);

	}

}