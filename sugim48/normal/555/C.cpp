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

void f(vector<i_i>& e, vector<int>& a) {
	sort(e.begin(), e.end());
	stack<int> I, X;
	I.push(-1); X.push(0);
	ll sum = 0;
	for (int k = 0; k < e.size(); k++) {
		int x = e[k].first, i = e[k].second;
		if (i >= 0) {
			I.push(i);
			X.push(x);
		}
		else {
			i = ~i;
			while (I.top() > i) {
				I.pop();
				X.pop();
			}
			a[i] = x - X.top();
		}
	}
}

int main() {
	int n, q; cin >> n >> q;
	vector<i_i> e(q), _e(q);
	set<int> s;
	for (int i = 0; i < q; i++) {
		int x, y; char c; scanf("%d%d %c", &x, &y, &c);
		if (s.count(x)) continue;
		s.insert(x);
		e[i] = i_i(x, c == 'U' ? i : ~i);
		_e[i] = i_i(y, c == 'L' ? i : ~i);
	}
	vector<int> a(q);
	f(e, a); f(_e, a);
	for (int i = 0; i < q; i++)
		cout << a[i] << endl;
}