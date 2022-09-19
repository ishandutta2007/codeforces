#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <map>
#include <set>
#include <deque>
#include <queue>

using namespace std;

#define forn(i,n) for (int i = 0; i < (int)(n); i++)
#define ford(i,n) for (int i = (int)(n) - 1; i >= 0; i--)

int n, k, a;

int main() {
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	cin >> n >> k;
	int s = 0;
	forn (i, n) {
		cin >> a;
		if (a > 3 * k) {
			s += a - 3 * k;
		} else {
			s += a % k;
		}
	}
	cout << s;
}