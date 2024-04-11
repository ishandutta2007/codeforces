#include <bits/stdc++.h>

using namespace std;

int main() {
	string line;
	cin >> line;
	int pt = 0;
	while (pt < line.length()) {
		if (line[pt] == '.') {
			cout << 0;
			pt++;
		}
		else {
			if (line[pt+1] == '.') {
				cout << 1;
			}
			else cout << 2;
			pt+=2;
		}
	}
	cout << endl;
	cin >> pt;
}