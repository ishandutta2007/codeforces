#include <stdio.h>
#include <algorithm>
#include <vector>
#include <iostream>
#include <ctime>
#include <memory.h>
#include <set>
#include <cmath>
#include <queue>

using namespace std;

#define forab(i, a, b) for (int i = a; i < (int)(b); i++)
#define fordab(i, a, b) for (int i = b - 1; i >= (int)(a); i--)
#define forn(i, n) forab (i, 0, n)
#define ford(i, n) fordab (i, 0, n)
#define forv(i, n) forn (i, n.size())
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

typedef long long int64;
typedef long double ld;

int main() {
	int r, g, b;
	cin >> r >> g >> b;
	int i = 0;
	while (r + g + b) {
		if (i % 3 == 0) {
			r = max(0, r - 2);
		} else if (i % 3 == 1) {
			g = max(0, g - 2);
		} else {
			b = max(0, b - 2);
		}
		i++;
	}
	cout << i + 29;
}