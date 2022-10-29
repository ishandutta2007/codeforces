#include <bits/stdc++.h>

using namespace std;

int main(){
	int k2,k3,k5,k6; cin >> k2 >> k3 >> k5 >> k6;
	int ans = 0;
	ans += min(k2,min(k5,k6))*256;
	ans += min(k3,k2-min(k2,min(k5,k6)))*32;
	cout << ans << "\n";	
}