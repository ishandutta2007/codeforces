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
struct edge { int u, v, w; };

ll MOD = 134151353125325623LL;
ll _MOD = 1000000009;
double EPS = 1e-10;
int INF = INT_MAX / 2;

ll f(string& s, vector<ll>& a) {
	ll x = 0;
	for (int i = 0; i < s.length(); i++)
		x = (x + a[i] * (s[i] - 'a' + 1)) % MOD;
	return x;
}

int main() {
	vector<ll> a(1000000);
	a[0] = 1;
	for (int i = 1; i < 1000000; i++)
		a[i] = a[i - 1] * 4 % MOD;
	int n, m; cin >> n >> m;
	set<ll> st;
	while (n--) {
		string s; cin >> s;
		st.insert(f(s, a));
	}
	while (m--) {
		string s; cin >> s;
		ll x = f(s, a);
		bool yes = false;
		for (int i = 0; i < s.length(); i++)
			for (char c = 'a'; c <= 'c'; c++) {
				if (c == s[i]) continue;
				ll y = x + a[i] * (c - s[i]);
				y = (y % MOD + MOD) % MOD;
				if (st.count(y)) yes = true;
			}
		printf(yes ? "YES\n" : "NO\n");
	}
}