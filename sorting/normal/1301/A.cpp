#include <bits/stdc++.h>

using namespace std;

void solve(){
	string a, b, c;
	cin >> a >> b >> c;

	int n = a.size();
	for(int i = 0; i < n; ++i){
		if(c[i] != a[i] && c[i] != b[i]){
			cout << "NO\n";
			return;
		}
	}

	cout << "YES\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	while(t--)
		solve();
}