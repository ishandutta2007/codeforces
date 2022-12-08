#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int z = 0;
	bool poss = false;
	string s;
	cin >> s;
	for (int i = s.length()-1; i >= 0; i--) {
		if (s[i] == '0') z++;
		else {
			if (z >= 6) poss = true;
		}
	}
	if (poss) cout << "yes" << endl;
	else cout << "no" << endl;
	cin >> z;
}