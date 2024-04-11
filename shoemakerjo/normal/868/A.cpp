#include <bits/stdc++.h>

using namespace std;

int main(){
	string pass; cin >> pass;
	int n;
	cin >> n;
	string cur;
	bool front = false, back = false;
	bool ok = false;
	for (int i = 0; i < n; i++) {
		cin >> cur;
		// if  (cur[0] == pass[0]) front = true;
		if (cur[0] == pass[1]) back = true;
		if (cur[1] == pass[0]) front = true;
		if (cur == pass) ok = true;
	}
	if (front && back || ok) cout << "YES\n";
	else cout << "NO\n";
	cin >> n;
}