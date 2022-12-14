#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	for (int h = 0; h < t; ++h) {
		string s;
		cin >> s;
		int o = 0, z = 0, po = 0, pz = 0, a1 = s.size(), a2 = s.size();
		for (char c: s) {
			if (c == '0') ++z;
			else ++o;
		}
		for (int i = 0; i < s.size(); ++i) {
			a1 = min(a1, po + z - pz);
			a2 = min(a2, pz + o - po);
			if (s[i] == '0') ++pz;
			else ++po;
		}
		a1 = min(a1, po + z - pz);
		a2 = min(a2, pz + o - po);
		printf("%d\n", min(a1, a2));
	}
	return 0;
}