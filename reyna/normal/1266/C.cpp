
#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <deque>
#include <assert.h>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <math.h>
#include <bitset>
#include <iomanip>
#include <complex>

using namespace std;

#define mp make_pair
#define x first
#define y second
#define pb push_back
#define ALL(x) (x).begin(), (x).end()

typedef long long LL;

const int N = (int) 0, mod = (int) 0;

int main() {
	int r, c;
	cin >> r >> c;
	if (r == 1 && c == 1) {
		cout << 0 << endl;
		return 0;
	}
	if (r < c) {
	for (int i = 1; i <= r; ++i) {
		for (int j = r + 1; j <= r + c; ++j) {
			cout << i * j << ' ';
		}
		cout << '\n';
	}
	} else {
		for (int i = c + 1; i <= r + c; ++i) {
			for (int j = 1; j <= c; ++j) {
				cout << i * j << ' ';
			}
			cout << '\n';
		}
	}
}