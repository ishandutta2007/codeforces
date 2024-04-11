#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	string s;
	cin >> n >> s;
	int zcount = 0, ocount = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '0') zcount++;
		else ocount++;
	}
	if (ocount == 0) {
		cout << 0 << endl;
	}
	else {
		cout << 1;
		for (int i = 0; i < zcount; i++) {
			cout << 0;
		}
		cout << endl;
	}
	cin >> n;
}