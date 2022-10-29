#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(){
	int n; cin >> n;
	vector<int> v(n);
	for(auto &x : v)cin >> x;
	string s; cin >> s;
	vector<int> a, b;
	for(int i = 0; i < n; ++i){
		if(s[i] == 'B')a.push_back(v[i]);
		if(s[i] == 'R')b.push_back(v[i]);
	}
	sort(a.begin(),a.end());
	sort(b.rbegin(),b.rend());
	for(int i = 0; i < a.size(); ++i){
		if(a[i] <= i){
			cout << "NO\n";
			return;
		}
	}
	for(int i = 0; i < b.size(); ++i){
		if(b[i] > n-i){
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1; cin >> t;
	while(t--){
		solve();
	}
}