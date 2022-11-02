#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <bitset>
#include <ctime>
#include <unordered_map>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

int gcd(int a, int b) {
	if (a == 0 || b == 0) {
		return a + b;
	}
	if (a > b) {
		return gcd(a % b, b);
	} else {
		return gcd(b % a, a);
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int a, b, n;
	cin >> a >> b >> n;
	int move = 0;
	while (n) {
		if (move == 0) {
			n -= gcd(a, n);
		} else {
			n -= gcd(b, n);
		}
		move = 1 - move;
	}
	cout << 1 - move << endl;

	return 0;
}