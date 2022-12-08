#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	string s;
	cin >> n >> s;
	int sav = 0;
	for (int i = 0; i < n; i++) {
		bool ok = true;
		for (int j = i+1; j <= 2*i+1; j++) {
			if (j >= n) {
				ok = false;
				break;
			}
			if (s[j] != s[j-i-1]) ok = false;
		}
		if (ok) sav = i+1;
	}
	// cout << "sav   " << sav << endl;
	if (sav > 0) {
		n = n-sav+1;
	}
	cout << n << endl;
	cin >> n;
	
}