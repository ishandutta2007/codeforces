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

void foo(int x, map<int, int>& m) {
	for (int i = 2; i * i <= x; i++)
		while (x % i == 0) {
			m[i]++;
			x /= i;
		}
	if (x > 1) m[x]++;
}

bool check(map<int, int>& m1, map<int, int>& m2) {
	for (map<int, int>::iterator it = m1.begin(); it != m1.end(); it++) {
		int x = it->first, y = it->second;
		if (x == 2 || x == 3) continue;
		if (m2.count(x) == 0 || m2[x] != y)
			return false;
	}
	return true;
}

int main() {
	ll a1, b1, a2, b2;
	cin >> a1 >> b1 >> a2 >> b2;
	map<int, int> m1, m2;
	foo(a1, m1);
	foo(b1, m1);
	foo(a2, m2);
	foo(b2, m2);
	if (!check(m1, m2) || !check(m2, m1)) {
		cout << -1 << endl;
		return 0;
	}
	int cnt = 0;
	while (m1[3] != m2[3]) {
		if (m1[3] > m2[3]) {
			m1[3]--;
			m1[2]++;
			if (a1 % 3 == 0) {
				a1 /= 3;
				a1 *= 2;
			}
			else {
				b1 /= 3;
				b1 *= 2;
			}
		}
		else {
			m2[3]--;
			m2[2]++;
			if (a2 % 3 == 0) {
				a2 /= 3;
				a2 *= 2;
			}
			else {
				b2 /= 3;
				b2 *= 2;
			}
		}
		cnt++;
	}
	while (m1[2] != m2[2]) {
		if (m1[2] > m2[2]) {
			m1[2]--;
			if (a1 % 2 == 0) a1 /= 2;
			else b1 /= 2;
		}
		else {
			m2[2]--;
			if (a2 % 2 == 0) a2 /= 2;
			else b2 /= 2;
		}
		cnt++;
	}
	cout << cnt << endl;
	cout << a1 << ' ' << b1 << endl;
	cout << a2 << ' ' << b2 << endl;
}