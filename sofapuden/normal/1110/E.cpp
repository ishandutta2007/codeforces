#include<bits/stdc++.h>

using namespace std;

void solve(){
	int n; cin >> n;
	vector<int> v(n);
	vector<int> v2(n);
	for(auto &x : v)cin >> x;
	for(auto &x : v2)cin >> x;
	map<int,int> M;
	for(int i = 0; i < n-1; ++i)M[v[i+1]-v[i]]++;
	if(v[0] != v2[0]){
		cout << "No\n";
		return;
	}
	for(int i = 0; i < n-1; ++i){
		if(!M[v2[i+1]-v2[i]]--){
			cout << "No\n";
			return;
		}
	}
	cout << "Yes\n";
}

int main(){
	solve();
}