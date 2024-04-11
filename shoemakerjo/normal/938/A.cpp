#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	string line;
	bool isvow[n];
	cin >> line;
	for (int i = 0; i < n; i++) {
		isvow[i] = line[i] == 'a' || line[i] == 'e' || line[i] == 'i' || 
			line[i] == 'o' || line[i] == 'u' || line[i] == 'y';

	}
	for (int i = 0; i < n; i++) {
		if (i > 0 && isvow[i] && isvow[i-1]) continue;
		cout << line[i];
	}
	cout << endl;
	cin >> n;
}