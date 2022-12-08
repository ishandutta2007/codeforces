#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int ans = 0;
	string line;
	cin >> line;
	for (int i = 0; i < line.length(); i++) {
		if (line[i] == '0') {
			ans++;
			break;
		}
		else {
			ans++;
		}
	}
	cout << ans << endl;
	cin >> n;
}