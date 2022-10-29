#include<bits/stdc++.h>

using namespace std;

void solve(){
	int n; cin >> n;
	vector<int> v(n);
	for(auto &x : v)cin >> x;
	cout << v[n-1] << '\n';


}

int main(){
	int t; cin >> t;
	while(t--)solve();
}