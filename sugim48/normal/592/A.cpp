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
	vector<string> s(8);
	for (int y = 0; y < 8; y++)
		cin >> s[y];
	int a = INT_MAX, b = INT_MAX;
	for (int x = 0; x < 8; x++) {
		for (int y = 0; y < 8 && s[y][x] != 'B'; y++)
			if (s[y][x] == 'W')
				a = min(a, y);
		for (int y = 0; y < 8 && s[7 - y][x] != 'W'; y++)
			if (s[7 - y][x] == 'B')
				b = min(b, y);
	}
	cout << (a <= b ? "A" : "B") << endl;
}