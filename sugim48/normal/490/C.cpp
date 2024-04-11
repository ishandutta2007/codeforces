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

char s[1000001];

int main() {
	string s; int a, b; cin >> s >> a >> b;
	int n = s.length();
	if (n == 1) {
		cout << "NO" << endl;
		return 0;
	}
	vector<bool> l(n), r(n);
	ll x = 0;
	for (int i = 1; i <= n - 1; i++) {
		x = (x * 10 + s[i - 1] - '0') % a;
		l[i] = (x == 0);
	}
	x = 0; ll y = 1;
	for (int i = n - 1; i >= 1; i--) {
		x = (x + (s[i] - '0') * y) % b;
		y = (y * 10) % b;
		r[i] = (s[i] != '0' && x == 0);
	}
	for (int i = 1; i <= n - 1; i++)
		if (l[i] && r[i]) {
			cout << "YES" << endl;
			cout << s.substr(0, i) << endl;
			cout << s.substr(i) << endl;
			return 0;
		}
	cout << "NO" << endl;
}