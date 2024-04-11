#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int lc = 0, uc = 0, rc = 0, dc = 0;
	int n;
	cin >> n;
	string line;
	cin >> line;
	for (int i = 0; i < n; i++) {
		if (line[i] == 'U') uc++;
		if (line[i] == 'D') dc++;
		if (line[i] == 'R') rc++;
		if (line[i] == 'L') lc++;
	}
	int ans = min(uc, dc)*2 + min(rc, lc)*2;
	cout << ans << endl;
	cin >> ans;

}