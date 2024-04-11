#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int maxN = 110000;
char s[maxN];

int main() {
	cin >> s;
	int n = strlen(s);
	if (n == 1) {
		cout << 0 << endl;
		return 0;
	}
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		sum += s[i] - '0';
	}
	int res = 0;
	while (sum >= 10) {
		int t = 0;
		while (sum) {
			t += sum % 10;
			sum /= 10;
		}
		sum = t;
		++res;
	}
	cout << res + 1 << endl;
	return 0;
}