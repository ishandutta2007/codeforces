#include <random>
#include <vector>
#include <iostream>
using namespace std;
const int limit = 1000000000;
mt19937 mt(1907152147);
int gcd(int x, int y) {
	if (y == 0) return x;
	return gcd(y, x % y);
}
int main() {
	int N;
	cin >> N;
	int L = -1, R = limit + 1;
	int cnt = 0;
	while (R - L > 1) {
		int M = (L + R) >> 1;
		cout << "> " << M << endl;
		++cnt;
		int x;
		cin >> x;
		if (x == 0) R = M;
		else L = M;
	}
	uniform_int_distribution<int> p(1, N);
	int g = -1;
	for (int i = cnt; i < 60; ++i) {
		int idx = p(mt);
		cout << "? " << idx << endl;
		int x;
		cin >> x;
		if (x != R) {
			if (g == -1) g = R - x;
			else g = gcd(g, R - x);
		}
	}
	cout << "! " << R - (N - 1) * g << ' ' << g << endl;
	return 0;
}