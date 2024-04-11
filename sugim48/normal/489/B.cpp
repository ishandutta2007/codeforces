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
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a.begin(), a.end());
	vector<int> v(102);
	int m; cin >> m;
	while (m--) {
		int b; cin >> b;
		v[b]++;
	}
	int cnt = 0;
	for (int i = 0; i < n; i++)
		for (int j = -1; j <= 1; j++) {
			int k = a[i] + j;
			if (v[k] > 0) {
				v[k]--;
				cnt++;
				break;
			}
		}
	cout << cnt << endl;
}