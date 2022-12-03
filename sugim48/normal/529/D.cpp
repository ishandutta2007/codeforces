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

typedef pair<ll, i_i> P;

ll MOD = 1000000007;
ll _MOD = 1000000009;
int INF = INT_MAX / 2;
double EPS = 1e-10;

int main() {
	int n, M, T; cin >> n >> M >> T;
	vector<i_i> v;
	for (int i = 0; i < n; i++) {
		int h, m, s; scanf("%d:%d:%d", &h, &m, &s);
		int t = (h * 60 + m) * 60 + s;
		v.push_back(i_i(t, i));
		v.push_back(i_i(t + T, ~i));
	}
	sort(v.begin(), v.end());
	int x = 0, prev, hoge = 0;
	vector<bool> a(n);
	vector<int> ans(n);
	bool ok = false;
	for (int j = 0; j < n * 2; j++) {
		int t = v[j].first, i = v[j].second;
		if (i >= 0) {
			if (x + 1 <= M) {
				x++;
				ans[i] = ++hoge;
			}
			else {
				a[prev] = true;
				ans[i] = hoge;
			}
			prev = i;
		}
		else {
			i = ~i;
			if (!a[i]) x--;
		}
		if (x == M) ok = true;
	}
	if (!ok) {
		cout << "No solution" << endl;
		return 0;
	}
	cout << hoge << endl;
	for (int i = 0; i < n; i++)
		cout << ans[i] << endl;
}