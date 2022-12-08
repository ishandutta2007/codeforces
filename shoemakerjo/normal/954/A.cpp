#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int rep = 0;
	bool ch[n];
	for (int i = 0; i < n; i++) {
		ch[i] = false;
	}
	string line;
	cin >> line;
	for (int i = 1; i < n; i++) {
		if (ch[i-1]) continue;
		if (line[i] != line[i-1]) {
			ch[i] = true;
			ch[i-1] = true;
			rep++;
		}
	}
	cout << n-rep << endl;
	cin >> n;
}