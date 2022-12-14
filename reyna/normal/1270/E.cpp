
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

const int N = (int) 1e3 + 3, mod = (int) 0;
int px[N], py[N];
int main() {
	int n;
	cin >> n;
	for (int j = 0; j < n; ++j) {
		cin >> px[j] >> py[j];
	}
	while (true) {
		int rx = px[0] - 1000 * 1000, ry = py[0] - 1000 * 1000;
		for (int j = 0; j < n; ++j) {
			px[j] -= rx;
			py[j] -= ry;
		}
		vector<int> p0, p1;
		for (int j = 0; j < n; ++j) {
			if ((px[j] & 1) ^ (py[j] & 1)) {
				p1.pb(j);
			} else {
				p0.pb(j);
			}
		}
		if (p1.size()) {
			cout << (int) p1.size() << '\n';
			for (int x : p1) cout << x + 1 << ' ';
			return 0;
		}
		p0.clear();
		for (int j = 0; j < n; ++j) {
			if (px[j] & 1) {
				p1.pb(j);
			} else {
				p0.pb(j);
			}
		}
		if (p1.size()) {
			cout << (int) p1.size() << '\n';
			for (int x : p1) cout << x + 1 << ' ';
			return 0;
		}
		for (int j = 0; j < n; ++j) {
			px[j] /= 2;
			py[j] /= 2;
		}
	}
	
	
}