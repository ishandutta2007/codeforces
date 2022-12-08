#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	int val0 = 0;
	int val1 = 1023;
	string type;
	int val;
	for (int i = 0; i < n; i++) {
		cin >> type >> val;
		if (type == "|") {
			val0 = val0 | val;
			val1 = val1 | val;
		}
		if (type == "^") {
			val0 = val0 ^ val;
			val1 = val1 ^ val;
		}
		if (type == "&") {
			val0 = val0 & val;
			val1 = val1 & val;
		}
	}
	int opand = 1023;
	int opor = 0;
	int opex = 0;
	for (int i = 0; i <= 9; i++) {
		bool g0 = val0 & (1 << i);
		bool g1 = val1 & (1 << i);
		if (g0 && g1) {
			opor += 1<<i;
		}
		if (!g0 && !g1) {
			opand -= 1<<i;
		}
		if (g0 && !g1) {
			opex += 1<<i;
		}
	}
	cout << 3 << endl;
	cout << "& " << opand << endl;
	cout << "| " << opor << endl;
	cout << "^ " << opex << endl;
	// cin  >> opex;
}