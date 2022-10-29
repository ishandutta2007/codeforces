#include<bits/stdc++.h>

using namespace std;

void pr(vector<int> v){
	for(auto &x : v)cout << x << ' ';
	cout << '\n';
}

void solve(){
	int n; cin >> n;
	vector<int> v(n);
	iota(v.begin(),v.end(),1);
	cout << n << '\n';
	pr(v);
	for(int i = 1; i < n; ++i){
		swap(v[0],v[i]);
		pr(v);

	}
}

int main(){
	int t; cin >> t; while(t--){
		solve();
	}
}