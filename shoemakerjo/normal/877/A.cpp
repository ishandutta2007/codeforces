#include <bits/stdc++.h>

using namespace std;

int main() {
	string line;
	cin >> line;
	int ct = 0;
	int clen = line.length();
	for (int i = 0; i < clen-4; i++) {
		if (line.substr(i, 5) == "Danil") ct++;

	}
	for (int i = 0; i < clen-3; i++) {
		if (line.substr(i, 4) == "Olya") ct++;
	}
	for (int i = 0; i < clen-4; i++) {
		if (line.substr(i, 5) == "Slava") ct++;
	}
	for (int i = 0; i < clen-2; i++) {
		if (line.substr(i, 3) == "Ann") ct++;
	}
	for (int i = 0; i < clen-5; i++) {
		// cout << "i: " << i << endl;
		if (line.substr(i, 6) == "Nikita") ct++;
	}
	// cout << "here" << endl;
	if (ct == 1) cout << "YES\n";
	else cout << "NO\n";
	// cin >> ct;
}