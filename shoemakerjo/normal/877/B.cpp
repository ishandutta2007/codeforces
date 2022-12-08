#include <bits/stdc++.h>

using namespace std;

int main() {
	int ans = 0;
	string line;
	cin >> line;
	int n = line.length();
	int inb[n+1];
	int ina[n+1];
	int ina2[n+1];
	ina[0] = ina2[0] = inb[0] = 0;
	for (int i = 1; i <= n; i++) {
		if (line[i-1] == 'a') {
			ina[i] = inb[i] = ina2[i] = 0;
			for (int j = 0; j < i; j++) {
				ina[i] = max(ina[i], ina[j]+1);
				ina2[i] = max(ina2[i], max(ina2[j], inb[j])+1);
			}
		}
		else {
			ina[i] = ina2[i] = inb[i] = 0;
			for (int j = 0; j < i; j++) {
				inb[i] = max(inb[i], max(ina[j], inb[j])+1);
			}
		}
		ans = max(ans, ina[i]);
		ans = max(ans, ina2[i]);
		ans = max(ans, inb[i]);
	}
	cout << ans << endl;
	// cin >> ans;

}