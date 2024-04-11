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
	int p1, p2, p3, p4, a, b;
	cin >> p1 >> p2 >> p3 >> p4 >> a >> b;
	p1 = min(min(p1, p2), min(p3, p4));
	cout << max(0, min(b, p1 - 1) - max(0, a) + 1);
}