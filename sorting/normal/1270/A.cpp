#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n, k1, k2;
	cin >> n >> k1 >> k2;

	bool win = false;
	for(int i = 0; i < k1; ++i){
		int a;
		cin >> a;
		if(a == n)
			win = true;
	}
	for(int i = 0; i < k2; ++i){
		int a;
		cin >> a;
	}

	cout << (win ? "YES" : "NO") << endl;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	while(t--)
		solve();
}