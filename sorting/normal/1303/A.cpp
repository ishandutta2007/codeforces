#include <bits/stdc++.h>

using namespace std;

void solve(){
	string s;
	cin >> s;

	int first = -1, last = -1;
	for(int i = 0; i < s.size(); ++i){
		if(s[i] == '1'){
			if(first == -1)
				first = i;
			last = i;
		}
	}

	if(first == -1){
		cout << "0\n";
		return;
	}

	int ans = 0;
	for(int i = first; i <= last; ++i){
		if(s[i] == '0')
			++ans;
	}

	cout << ans << "\n";

	return;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	while(t--)
		solve();
}