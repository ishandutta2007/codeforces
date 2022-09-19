#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

#define forn(i,n) for (int i = 0; i < (int)(n); i++)

void wr(int n, int k) {
	if (k > 0) {
		wr(n / 10, k - 1);
		cout << n % 10;
	}
}

int main() {
//	freopen("input.txt", "rt", stdin);
//	freopen("output.txt", "wt", stdout);
	int a, b, m;
	cin >> a >> b >> m;
	if (b >= m - 1) {
		cout << 2;
		return 0;
	}
	forn (i, m) {
		if (i <= a) {
			int x = (((long long) i) * 1000000000ll) % m;
			x = (m - x) % m;
			if (x > b) {
				cout << "1 ";
				wr(i, 9);
				return 0;
			}
		}
	}
	cout << 2;
	return 0;
}