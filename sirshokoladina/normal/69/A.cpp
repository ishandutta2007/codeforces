#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

#define forn(i,n) for (int i = 0; i < (int)(n); i++)

int main() {
//	freopen("input.txt", "rt", stdin);
//	freopen("output.txt", "wt", stdout);
	int n, a, b, c, sa = 0, sb = 0, sc = 0;
	cin >> n;
	forn (i, n) {
		cin >> a >> b >> c;
		sa += a;
		sb += b;
		sc += c;
	}
	if (sa == 0 && sb == 0 && sc == 0) {
		cout << "YES";
	} else {
		cout << "NO";
	}
}