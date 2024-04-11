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
struct edge { int v; ll w; };

ll MOD = 1000000007;
ll _MOD = 1000000009;
ll INF = LLONG_MAX / 3;
double EPS = 1e-10;

int f(char c) {
	if ('0' <= c && c <= '9') return c - '0';
	if ('A' <= c && c <= 'Z') return c - 'A' + 10;
	if ('a' <= c && c <= 'z') return c - 'a' + 36;
	if (c == '-') return 62;
	if (c == '_') return 63;
}

int main() {
	vector<int> a(64);
	for (int x = 0; x < 64; x++)
		for (int y = 0; y < 64; y++)
			a[x & y]++;
	string s; cin >> s;
	ll ans = 1;
	for (char c: s) {
		int x = f(c);
		ans = ans * a[x] % MOD;
	}
	cout << ans << endl;
}