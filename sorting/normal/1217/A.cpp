#include <bits/stdc++.h>

using namespace std;

void solve(){
	int s, i, e;

	cin >> s >> i >> e;

	if(s + e <= i){
		cout << "0\n";

		return;
	}

	cout << min((s + e - i + 1) / 2, e + 1) << endl;

	return; 
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;

	cin >> t;

	while(t--){
		solve();
	}
}