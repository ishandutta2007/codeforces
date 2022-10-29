#include<bits/stdc++.h>

using namespace std;

void solve(){
	int n;cin >> n;
	vector<int> a(n);
	for(auto &x : a)cin >> x;
	int m; cin >> m;
	vector<int> b(m);
	for(auto &x : b)cin >> x;
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	if(a.back() >= b.back()){
		cout << "Alice\n";
	}
	else{
		cout << "Bob\n";
	}
	if(b.back() >= a.back()){
		cout << "Bob\n";
	}
	else{
		cout << "Alice\n";
	}

}

int main(){
	int t; cin >> t;
	while(t--)solve();

}