#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n; cin >> n;
	string s1, s2; cin >> s1 >> s2;
	int ans = 0;
	for(int i = 0; i < 20; ++i){
		char mini = 'z';
		bool found = 0;
		for(int j = 0; j < (int)s1.size(); ++j){
			if(s1[j] == i+'a' && s1[j] != s2[j]){
				found = 1;
				mini = min(s2[j], mini);
			}
		}
		if(mini < i+'a'){
			cout << -1;
			return;
		}
		if(found){
			ans++;
			for(int j = 0; j < (int)s1.size(); ++j){
				if(s1[j] == i+'a' && s1[j] != s2[j]){
					s1[j] = mini;
				}
			}
		}
	}
	cout << ans;
}
	

int main(){
	int t; cin >> t;
	while(t--){
		solve();
		cout << "\n";
	}
	return 0;	
}