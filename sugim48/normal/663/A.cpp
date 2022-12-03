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
struct edge { int u, v; ll w; };

ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;

int main() {
	int n;
	vector<char> op;
	op.push_back('+');
	for (;;) {
		string s; cin >> s;
		if (s == "+") op.push_back('+');
		if (s == "-") op.push_back('-');
		if (s == "=") {
			cin >> n;
			break;
		}
	}
	int plus = 0, minus = 0;
	for (char c: op) {
		if (c == '+') plus++;
		if (c == '-') minus++;
	}
	bool ok = false;
	int x, y;
	for (x = plus; x <= plus * n; x++) {
		y = x - n;
		if (minus <= y && y <= minus * n) {
			ok = true;
			break;
		}
	}
	if (!ok) {
		cout << "Impossible" << endl;
		return 0;
	}
	cout << "Possible" << endl;
	int i = 0, j = 0;
	vector<int> a;
	for (char c: op) {
		int z;
		if (c == '+') {
			z = x / plus + (i < x % plus);
			i++;
		}
		if (c == '-') {
			z = y / minus + (j < y % minus);
			j++;
		}
		a.push_back(z);
	}
	stringstream ss;
	for (int k = 0; k < op.size(); k++)
		ss << op[k] << ' ' << a[k] << ' ';
	ss << '=' << ' ' << n;
	cout << ss.str().substr(2) << endl;
}