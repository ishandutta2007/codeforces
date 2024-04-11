#define _USE_MATH_DEFINES
#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cfloat>
#include <climits>
#include <complex>
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
struct edge { int v; ll w; };

int MOD = 1000000007;

void dfs(int u, set<int>& mada, set<i_i>& NG) {
	int v = -1;
	for (;;) {
		auto it = mada.upper_bound(v);
		if (it == mada.end()) return;
		v = *it;
		if (NG.count(i_i(u, v))) continue;
		mada.erase(v);
		dfs(v, mada, NG);
	}
}

int main() {
	int N, M, k; cin >> N >> M >> k;
	set<i_i> NG;
	while (M--) {
		int a, b; scanf("%d%d", &a, &b);
		NG.insert(i_i(a - 1, b - 1));
		NG.insert(i_i(b - 1, a - 1));
	}
	set<int> mada;
	for (int u = 1; u < N; u++)
		mada.insert(u);
	int deg = 0, cnt = 0;
	for (int s = 1; s < N; s++) {
		if (NG.count(i_i(0, s))) continue;
		deg++;
		if (!mada.count(s)) continue;
		cnt++;
		mada.erase(s);
		dfs(s, mada, NG);
	}
	if (mada.empty() && cnt <= k && k <= deg) cout << "possible" << endl;
	else cout << "impossible" << endl;
}