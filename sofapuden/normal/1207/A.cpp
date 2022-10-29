#include <bits/stdc++.h>

using namespace std;

void solve(){
	int b, p, f, h, c; cin >> b >> p >> f >> h >> c;
	b /= 2;
	if(c > h){
		cout << min(b,f)*c + min(b-min(b,f),p)*h << "\n";
	}
	else{
		cout << min(b,p)*h + min(b-min(b,p),f)*c << "\n";
	}
}

int main(){
	int t; cin >> t;
	while(t--){
		solve();
	}
}