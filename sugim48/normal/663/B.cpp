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

ll solve(string s) {
	if (s.empty()) return 1988;
	ll lb = solve(s.substr(1)) + 1;
	ll x = 0, ten = 1;
	for (char c: s) {
		x = x * 10 + (c - '0');
		ten *= 10;
	}
	for (; x < lb; x += ten);
	return x;
}

int main() {
	int N; cin >> N;
	while (N--) {
		string s; cin >> s;
		cout << solve(s.substr(4)) << endl;
	}
}