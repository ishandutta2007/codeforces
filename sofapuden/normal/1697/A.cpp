#include<bits/stdc++.h>

using namespace std;

void solve(){
	int n, m; cin >> n >> m;
	vector<int> v(n);for(auto &x : v)cin >> x;
	cout << max(0,accumulate(v.begin(),v.end(),0)-m) << '\n';

}

int main(){
	int t; 
	cin >> t;
	while(t--)solve();
}