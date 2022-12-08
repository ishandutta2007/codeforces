#include <iostream>
#include <string>
using namespace std;

int main() {
	int n;
	cin >>  n;
	string line;
	cin >> line;
	bool seen[26];
	for (int i = 0; i < 26; i++) {
		seen[i] = false;
	}
	int lets = 0;
	int bad = 0;
	for (int i = 0; i < n; i++) {
		if (!seen[line[i]-'a']) {
			lets++;
			seen[line[i]-'a'] = true;
		}
		else bad++;
	}
	if (bad + lets <= 26) {
		cout << bad << endl;
	}
	else cout << -1 << endl;
	cin >> n;
}