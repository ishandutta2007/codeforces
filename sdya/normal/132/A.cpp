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
#include <ctime>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 110;
char s[maxN];

int rev(int n) {
	int res = 0;
	for (int i = 0; i < 8; ++i) {
		res = res * 2 + (n % 2);
		n /= 2;
	}
	return res;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	gets(s);
	int n = strlen(s);
	vector < int > a(n);

	for (int i = 0; i < n; ++i) {
		int x = rev(s[i]);
		int y = (i == 0 ? 0 : rev(s[i - 1]));
		a[i] = (y - x) % 256;
		if (a[i] < 0) {
			a[i] += 256;
		}
		cout << a[i] << endl;
	}

	return 0;
}