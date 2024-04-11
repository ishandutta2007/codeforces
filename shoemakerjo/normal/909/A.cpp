#include <bits/stdc++.h>

using namespace std;

int main() {
	string fi, se;
	cin >> fi >> se;
	cout << fi[0];
	for (int i = 1; i < fi.length(); i++) {
		if (fi[i] < se[0]) {
			cout << fi[i];
		}
		else break;
	}
	cout << se[0] << endl;
	int n;
	cin >> n;
}