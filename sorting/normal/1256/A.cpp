#include <bits/stdc++.h>

using namespace std;

void solve(){
	int a, b, n, s;

	cin >> a >> b >> n >> s;

	if(b >= (s % n) && a >= (s / n)){
		cout << "YES\n";
	}
	else{
		if(a < (s / n) && b >= (s - a * n)){
			cout << "YES\n";
		}
		else{
			cout << "NO\n";
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int q;

	cin >> q;

	while(q--){
		solve();
	}

	return 0;
}