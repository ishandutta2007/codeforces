#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	string line;
	cin >> line;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			int cx = 0, cy = 0;
			for (int k = i; k <= j; k++) {
				if (line[k] == 'U') cy++;
				if (line[k] == 'D') cy--;
				if (line[k] == 'L') cx--;
				if (line[k] == 'R') cx++;
			}
			if (cx == 0 && cy == 0) ans++;
		}
	}
	cout << ans << endl;
	cin >> n;
}