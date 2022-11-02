#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <cmath>
#include <stack>
#include <ctime>
#include <unordered_map>
#include <unordered_set>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

int gcd(int a, int b) {
	if (a == 0 || b == 0) {
		return a + b;
	}
	if (a > b) {
		return gcd(a % b, b);
	}
	return gcd(b % a, a);
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;

	int g = 0, m = 0;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		g = gcd(g, x);
		m = max(x, m);
	}

	int k = m / g;
	int r = (n - k);
	if (r % 2 == 0) {
		cout << "Bob" << endl;
	} else {
		cout << "Alice" << endl;
	}

	return 0;
}