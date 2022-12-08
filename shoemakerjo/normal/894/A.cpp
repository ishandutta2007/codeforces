#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	string line;
	cin >> line;
	n = line.length();
	int ans = 0;
	int q = 0;
	int qa = 0;
	for (int i = 0; i < n; i++) {
		if (line[i] == 'Q') {
			ans += qa;
			q++;
		}
		if (line[i] == 'A') {
			qa+=q;
		}
	}
	cout << ans << endl;
	// cin >> ans;
}