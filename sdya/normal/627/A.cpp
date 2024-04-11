#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <bitset>
#include <set>
#include <map>
#include <queue>
#include <stack>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxL = 110;
long long s, x;
map < pair < int, int >, long long > M;
int ds[maxL], dx[maxL];

long long calc(int bits, int carry) {
	pair < int, int > current = make_pair(bits, carry);
	if (M.count(current)) {
		return M[current];
	}

	if (bits < 0) {
		return M[current] = (carry == 0 ? 1 : 0);
	}

	long long res = 0;
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 2; ++j) {
			for (int c = 0; c < 2; ++c) {
				if ((i + j + c) % 2 == ds[bits] && (i + j + c) / 2 == carry && (i ^ j) == dx[bits]) {
					res += calc(bits - 1, c);
				}
			}
		}
	}
	return M[current] = res;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> s >> x;
	long long res = 0;
	if (s == x) {
		res -= 2;
	}
	for (int i = 0; i < maxL; ++i) {
		ds[i] = s % 2;
		dx[i] = x % 2;
		s /= 2;
		x /= 2;
	}

	res += calc(maxL - 1, 0);
	cout << res << endl;

	return 0;
}