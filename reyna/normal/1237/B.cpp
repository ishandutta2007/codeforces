
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

const int N = (int) 1e6 + 6, mod = (int) 0;
int a[N], b[N], pos[N];

int main() {
	int n;
	cin >> n;
	for (int j = 0; j < n; ++j) cin >> a[j], pos[--a[j]] = n - j - 1;
	int res = 0, mx = -1;
	for (int j = 0; j < n; ++j) {
		cin >> b[j];
		--b[j];
	}
	for (int j = n - 1; j >= 0; --j) {
		if (mx > pos[b[j]]) {
			++res;
		}
		mx = max(mx, pos[b[j]]);
	}
	cout << res << endl;
}