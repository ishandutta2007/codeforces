#include <bits/stdc++.h>

using namespace std;

bool work[256];

void solve(){
	string s;

	cin >> s;
	int n = s.size();

	for(int i = 0; i < 256; ++i){
		work[i] = false;
	}

	int curr = 1;
	for(int i = 1; i < n; ++i){
		if(s[i] != s[i - 1]){
			if(curr & 1){
				work[s[i - 1]] = true;
			}
			curr = 0;
		}
		++curr;
	}
	if(curr & 1){
		work[s.back()] = true;
	}

	for(int i = 0; i < 256; ++i){
		if(work[i]){
			cout << (char)i;
		}
	}
	cout << "\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;

	cin >> t;

	while(t--){
		solve();
	}

	return 0;
}