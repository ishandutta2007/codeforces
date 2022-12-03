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

int main() {
	int n; cin >> n;
	vector<int> p(n);
	for (int i = 0; i < n; i++) {
		cin >> p[i];
		p[i]--;
	}
	vector<int> si(n);
	for (int i = 0; i < n; i++) {
		int s; cin >> s;
		s--;
		si[s] = i;
	}
	for (int i = 0; i < n; i++)
		p[i] = si[p[i]];
	int ans = 0;
	vector<int> a, b;
	for (;;) {
		int i;
		for (i = 0; i < n && p[i] == i; i++);
		if (i == n) break;
		int j;
		for (j = 0; p[j] != i; j++);
		for (; p[i] < j; i = p[i]);
		swap(p[i], p[j]);
		ans += j - i;
		a.push_back(i);
		b.push_back(j);
	}
	int k = a.size();
	cout << ans << endl;
	cout << k << endl;
	for (int t = 0; t < k; t++)
		cout << a[t] + 1 << ' ' << b[t] + 1 << endl;
}