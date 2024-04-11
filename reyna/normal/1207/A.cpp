
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
	int t;
	cin >> t;
	while (t--) {
		int b, p, f;
		cin >> b >> p >> f;
		int h, c, res = 0;
		cin >> h >> c;
		for (int chicken = 0; chicken <= f; ++chicken) {
			int make_chicken = min(chicken, b / 2);
			int left = b - 2 * make_chicken;
			int make_ham = min(p, left / 2);
			res = max(res, make_chicken * c + make_ham * h);
		}
		cout << res << '\n';
	}
}