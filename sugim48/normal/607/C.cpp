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
#include <random>
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
	int n; cin >> n; n--;
	string s, t; cin >> s >> t;
	for (int i = 0; i < n; i++) {
		char& c = t[i];
		if (c == 'N') c = 'S';
		else if (c == 'S') c = 'N';
		else if (c == 'W') c = 'E';
		else if (c == 'E') c = 'W';
	}
	reverse(t.begin(), t.end());
	vector<ll> a(n + 1), b(n + 1);
	ll x = 1;
	for (int i = 0; i < n; i++) {
		a[i + 1] = (a[i] + x * (s[i] - 'A')) % MOD;
		b[i + 1] = (b[i] + x * (t[i] - 'A')) % MOD;
		x = x * 37 % MOD;
	}
	x = 1;
	bool yes = true;
	for (int len = n; len >= 1; len--) {
		if ((a[n] - a[n - len] + MOD) % MOD == b[len] * x % MOD)
			yes = false;
		x = x * 37 % MOD;
	}
	cout << (yes ? "YES" : "NO") << endl;
}