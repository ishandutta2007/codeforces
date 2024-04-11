#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	string line; cin >> line;
	bool ok = true;
	for (int i = 0; i < n-1; i++) {
		if (line[i] == '1' && line[i+1] == '1') ok = false;
	}
	for (int i = 0; i < n-2; i++) {
		if (line[i] == '0' && line[i+1] == '0' && line[i+2] == '0') ok = false;
	}
	if (line == "0") ok = false;
	if (line.length() > 1) {
		if (line[0] == '0' && line[1] == '0') ok = false;
		if (line[n-1] == '0' && line[n-2] == '0') ok = false;
	}
	if (ok) cout << "Yes" << endl;
	else cout << "No" << endl;
	cin >> n;



}