#include <bits/stdc++.h>
using namespace std;


int main() {
	int n;
	cin >> n;
	string line;
	getline(cin, line);
	getline(cin, line);
	// cin >> line;
	int ans = 0;
	int cur = 0;
	for (int i = 0; i < n; i++) {
		if (line[i]==' ') cur = 0;
		else {
			if (line[i] - 'A' >= 0 && line[i]-'A' < 26) {
				cur++;
			}
		}
		ans = max(ans, cur);
	}
	cout << ans << endl;
	cin >> n;
}