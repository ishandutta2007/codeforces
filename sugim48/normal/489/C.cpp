#define _USE_MATH_DEFINES
#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cfloat>
#include <climits>
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
struct edge { int u, v; ll w; };

ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;

bool check(int m, int s) {
	return s >= 0 && s <= m * 9;
}

void mini(int m, int s) {
	for (int i = 0; i < m; i++) {
		int j;
		for (j = 0; j <= 9; j++) {
			if (i == 0 && j == 0) continue;
			if (check(m - i - 1, s - j)) {
				s -= j;
				cout << j;
				break;
			}
		}
		if (j == 10) {
			cout << -1;
			return;
		}
	}
}

void maxi(int m, int s) {
	for (int i = 0; i < m; i++) {
		int j;
		for (j = 9; j >= 0; j--) {
			if (i == 0 && j == 0) continue;
			if (check(m - i - 1, s - j)) {
				s -= j;
				cout << j;
				break;
			}
		}
		if (j == -1) {
			cout << -1;
			return;
		}
	}
}

int main() {
	int m, s; cin >> m >> s;
	if (m == 1 && s == 0) {
		cout << 0 << ' ' << 0 << endl;
		return 0;
	}
	mini(m, s); cout << ' ';
	maxi(m, s); cout << endl;
}