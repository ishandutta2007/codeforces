#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(){
	int n; cin >> n;
	string s; cin >> s;
	string t; cin >> t;
	int nxt = 0;
	for(int i = 0; i < n; ++i){
		if(s[i] == t[i])continue;
		if(t[i] < s[i]){
			cout << "NO\n";
			return;
		}
		if(t[i]-s[i] == 2){
			cout << "NO\n";
			return;
		}
		for(int j = max(nxt,i+1); j < n; ++j){
			nxt = j;
			if(s[j] != s[i] && s[j] != t[i]){
				cout << "NO\n";
				return;
			}
			if(s[j] == t[i]){
				swap(s[i],s[j]);
				break;
			}
		}
		if(s[i] != t[i]){
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--)solve();
}