#define _USE_MATH_DEFINES
#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cfloat>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <time.h>
#include <vector>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
typedef pair<double, int> d_i;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> d_d;
struct edge { int v, c; };

ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;

int main() {
	int t; cin >> t;
	while (t--) {
		int n, k; cin >> n >> k;
		vector<string> a(3);
		vector<bool> b(3);
		for (int y = 0; y < 3; y++) {
			cin >> a[y];
			for (; a[y].length() % 3 != 1; a[y].push_back('.'));
			if (a[y][0] == 's') {
				b[y] = true;
				a[y][0] = '.';
			}
		}
		n = a[0].length();
		for (int x = 0; x + 3 < n; x += 3) {
			vector<bool> _b(3);
			for (int y = 0; y < 3; y++) {
				if (!b[y]) continue;
				if (a[y][x + 1] != '.') continue;
				for (int dy = -1; dy <= 1; dy++) {
					int _y = y + dy;
					if (_y >= 0 && _y < 3 && a[_y][x + 1] == '.')
						_b[_y] = true;
				}
			}
			for (int y = 0; y < 3; y++)
				b[y] = (_b[y] && a[y][x + 2] == '.' && a[y][x + 3] == '.');
		}
		bool yes = false;
		for (int y = 0; y < 3; y++)
			if (b[y])
				yes = true;
		cout << (yes ? "YES" : "NO") << endl;
	}
}