
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
#define int long long
const int N = (int) 0, mod = (int) 0;
vector<int> all;
int go(int step, int n) {
	if (step == 0) return 0;
	if (n == 0) {
		cout << '1';
		for (int j = 1; j <= 50000; ++j) {
			if (all.size() == 0) break;
			cout << '3';
			while (all.back() == j) {
				cout << '7';
				all.pop_back();
			}
		}
		cout << '\n';
		return 1;
	}
	if (step * (step - 1) / 2 <= n) {
		all.push_back(step);
		if (go(step, n - (step * (step - 1) / 2))) return 1;
		all.pop_back();
	}
	return go(step - 1, n);
}
int32_t main() {
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		go(50000, n);
	}
}