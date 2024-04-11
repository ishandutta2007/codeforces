#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n, x, a, b; cin >> n >> x >> a >> b;
	cout << min(n-1,abs(a-b)+x) << "\n";
	return;
}

int main(){
	int t; cin >> t; while(t--){solve();}
	return 0;	
}