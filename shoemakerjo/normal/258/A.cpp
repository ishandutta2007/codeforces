#include <bits/stdc++.h>

using namespace std;

int main() {
	string a; 
	cin >> a;
	bool flip = true;
	for (int i = 0; i < a.length(); i++) {
		if (flip && (i == a.length()-1 || a[i] == '0')) {
			flip = false;
			continue;
		}
		cout << a[i];
	}
	cout << endl;
	// cin >> a;
}