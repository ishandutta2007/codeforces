#include <bits/stdc++.h>

using namespace std;

int main() {
	int k;
	cin >> k;
	string alph = "abcdefghijklmnopqrstuvwxyz";
	for (int i = 0; i < 26; i++) {
		int cur = 0;
		while (k - cur >= 0) {
			k-=cur;
			cur++;
			cout << alph[i];
		}
	}
	cout << endl;
	cin >> k;
}