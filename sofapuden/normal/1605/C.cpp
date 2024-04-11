#include<bits/stdc++.h>

using namespace std;

void solve(){
	int n; cin >> n;
	string s; cin >> s;
	for(int i = 0; i < n-1; ++i){
		if(s[i] == 'a' && s[i+1] == 'a'){
			cout << 2 << '\n';
			return;
		}
	}
	for(int i = 0; i < n-2; ++i){
		if(s[i] == 'a' && s[i+1] == 'b' && s[i+2] == 'a'){
			cout << 3 << '\n';
			return;
		}
	}
	for(int i = 0; i < n-2; ++i){
		if(s[i] == 'a' && s[i+1] == 'c' && s[i+2] == 'a'){
			cout << 3 << '\n';
			return;
		}
	}
	for(int i = 0; i < n-3; ++i){
		if(s[i] == 'a' && s[i+1] == 'b' && s[i+2] == 'c' && s[i+3] == 'a'){
			cout << 4 << '\n';
			return;
		}
	}
	for(int i = 0; i < n-3; ++i){
		if(s[i] == 'a' && s[i+1] == 'c' && s[i+2] == 'b' && s[i+3] == 'a'){
			cout << 4 << '\n';
			return;
		}
	}
	for(int i = 0; i < n-6; ++i){
		if(s[i] == 'a' && s[i+1] == 'b' && s[i+2] == 'b' && s[i+3] == 'a' && s[i+4] == 'c' && s[i+5] == 'c' && s[i+6] == 'a'){
			cout << 7 << '\n';
			return;
		}
	}
	for(int i = 0; i < n-6; ++i){
		if(s[i] == 'a' && s[i+1] == 'c' && s[i+2] == 'c' && s[i+3] == 'a' && s[i+4] == 'b' && s[i+5] == 'b' && s[i+6] == 'a'){
			cout << 7 << '\n';
			return;
		}
	}
	cout << "-1\n";

}

int main(){
	int t; cin >> t;
	while(t--){
		solve();
	}
}