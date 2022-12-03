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

int main() {
	int n; cin >> n;
	vector<int> h(n);
	for (int i = 0; i < n; i++)
		cin >> h[i];
	vector<int> mi(n + 1);
	mi[n] = INT_MAX;
	for (int i = n - 1; i >= 0; i--)
		mi[i] = min(h[i], mi[i + 1]);
	int cnt = 0;
	for (int i = 0; i < n;) {
		int ma = h[i];
		int j;
		for (j = i + 1; ma > mi[j]; j++)
			ma = max(ma, h[j]);
		i = j;
		cnt++;
	}
	cout << cnt << endl;
}