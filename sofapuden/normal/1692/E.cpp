#include<bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
void solve(){
	int n; cin >> n;
	int s; cin >> s;
	vector<int> v(n);
	for(auto &x : v)cin >> x;
	vector<int> fi = {0}, se = {0};
	for(int i = 0; i < n; ++i){
		if(v[i])fi.push_back(i+1);
	}
	for(int i = n-1; ~i; --i){
		if(v[i])se.push_back(n-i);
	}
	if(fi.size() <= s){
		cout << "-1\n";
		return;
	}
	int mn = 1000000;
	int am = fi.size()-1;
	for(int i = 0; i <= am-s; ++i){
		mn = min(mn,fi[i]+se[am-s-i]);
	}
	cout << mn << '\n';
}
 
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t; while(t--)solve();
}