#include<bits/stdc++.h>

using namespace std;

void solve(){
	int n; cin >> n;
	vector<int> v(n);
	for(auto &x : v)cin >> x;
	vector<pair<int,int>> in;
	for(int i = 0; i < n; ++i){
		if(i == 0)in.emplace_back(v[0],i+1);
		else in.emplace_back(v[i]-v[i-1],i+1);
	}
	sort(in.rbegin(),in.rend());
	for(auto x : in)cout << x.second << ' ';
	cout << '\n';

}

int main(){
	int t; cin >> t;
	while(t--)solve();
}