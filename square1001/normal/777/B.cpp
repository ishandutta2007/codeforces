#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
int n, c1[12], c2[12]; string s, t;
void init() {
	fill(c1, c1 + 10, 0);
	fill(c2, c2 + 10, 0);
	for (char c : s) c1[c - 48]++;
	for (char c : t) c2[c - 48]++;
}
int main() {
	cin >> n >> s >> t;
	init();
	int ret1 = n;
	for (int i = 9; i >= 0; i--) {
		for (int j = i; j >= 0; j--) {
			int z = min(c1[j], c2[i]);
			c1[j] -= z; c2[i] -= z; ret1 -= z;
		}
	}
	init();
	int ret2 = 0;
	for (int i = 9; i >= 0; i--) {
		for (int j = i - 1; j >= 0; j--) {
			int z = min(c1[j], c2[i]);
			c1[j] -= z; c2[i] -= z; ret2 += z;
		}
	}
	cout << ret1 << endl;
	cout << ret2 << endl;
	return 0;
}