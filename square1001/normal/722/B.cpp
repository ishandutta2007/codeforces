#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <functional>
#pragma warning(disable : 4996)
using namespace std;
int n, p[109]; string s;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> p[i];
	bool f = true;
	for (int i = 0; i < n; i++) {
		s = "";
		while (s == "") getline(cin, s);
		for (char c : s) {
			if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y') p[i]--;
		}
		if (p[i] != 0) f = false;
	}
	cout << (f ? "YES" : "NO") << endl;
	return 0;
}