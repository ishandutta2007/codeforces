#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;

void solve(){
	int n;
	string s; cin >> n >> s;
	for(int i = 0; i < n; i++){
		if(s[i] == '8'){
			if(n-i >= 11){
				cout << "YES\n";
				return;
			}
		}
	}
	cout << "NO\n";
	return;
}

int main(){
	int t; cin >> t;
	while(t--){
		solve();
	}
}