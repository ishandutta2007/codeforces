#include<bits/stdc++.h>

using namespace std;

void solve(){
	int n; cin >> n;
	deque<int> v(n);
	for(auto &x : v)cin >> x;
	int mn = 0;
	while(v.size() && mn <= v[0] && mn <= v.back()){
		mn = min(v[0],v.back());
		if(mn == v[0]){
			v.pop_front();
		}
		else{
			v.pop_back();

		}
	}
	cout << (v.size() ? "NO" : "YES") << '\n';
}
int main(){
	int t; cin >> t;
	while(t--)solve();
}