#include <bits/stdc++.h>

using namespace std;

void solve(){
	int a, b, c, d, k; cin >> a >> b >> c >> d >> k;
	int pen = (a+c-1)/c;
	int penc = (b+d-1)/d;
	cout << (pen+penc <= k ? to_string(pen) + " " + to_string(penc) : "-1") << "\n";					
}

int main(){
	int t; cin >> t;
	while(t--){
		solve();	
	}
}