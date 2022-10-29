#include <bits/stdc++.h>

using namespace std;

void solve(){
	int hh,dd; cin >> hh >> dd;
	cout << (24-hh-1)*60+(60-dd) << "\n";
	return;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}	
	return 0;	
}