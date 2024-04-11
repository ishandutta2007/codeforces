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

int main() {
	int n; cin >> n;
	deque<int> a, b;
	int k1; cin >> k1;
	while (k1--) {
		int x; cin >> x;
		a.push_back(x);
	}
	int k2; cin >> k2;
	while (k2--) {
		int y; cin >> y;
		b.push_back(y);
	}
	for (int t = 0; t < 40000000; t++) {
		/*for (int i = 0; i < a.size(); i++)
			cout << a[i] << ' ';
		cout << '|' << ' ';
		for (int i = 0; i < b.size(); i++)
			cout << b[i] << ' ';
		cout << endl;*/
		if (b.empty()) {
			cout << t << ' ' << 1 << endl;
			return 0;
		}
		if (a.empty()) {
			cout << t << ' ' << 2 << endl;
			return 0;
		}
		int x = a.front(); a.pop_front();
		int y = b.front(); b.pop_front();
		if (x > y) {
			a.push_back(y);
			a.push_back(x);
		}
		if (x < y) {
			b.push_back(x);
			b.push_back(y);
		}
	}
	cout << -1 << endl;
}