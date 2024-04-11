#include<bits/stdc++.h>

using namespace std;

void solve(){
	int n; cin >> n;
	vector<int> v(n);
	for(auto &x : v)cin >> x;
	if(n&1){
		cout << "NO\n";
		return;
	}
	vector<int> v2;
	sort(v.begin(),v.end());
	for(int i = 0; i < n/2; ++i){
		v2.push_back(v[i]);
		v2.push_back(v[i+n/2]);
	}
	for(int i = 0; i < n; ++i){
		if(v2[i] == v2[(i+1)%n]){
			cout  << "NO\n";
			return;
		}
	}
	cout << "YES\n";
	for(auto x : v2)cout << x << ' ';
	cout << '\n';
}

int main(){
	int t; cin >> t;
	while(t--)solve();


}