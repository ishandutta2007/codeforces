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

vector<int> a;

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	if (n % 2 == 0 || m < n / 2 + 1) {
		forn (i, n) {
			int x;
			cin >> x;
		}
		cout << 0;
		return 0;
	}
	int ans = 1000000000;
	forn (i, n) {
		int x;
		cin >> x;
		if (i % 2 == 0) {
			ans = min(ans, x);
		}
	}
	cout << min(int64(ans), int64(k) * (int64(m) / (int64(n) / int64(2) + int64(1))));
}