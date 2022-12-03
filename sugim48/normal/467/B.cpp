#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cstring>
#include <climits>
#include <cmath>
#include <map>
#include <queue>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
typedef pair<double, int> d_i;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> d_d;
struct edge { int u, v; ll w; int rev; };

int main() {
	int n, m, k; cin >> n >> m >> k;
	vector<int> x(m + 1);
	for (int i = 0; i < m + 1; i++) cin >> x[i];
	int ans = 0;
	for (int i = 0; i < m; i++) {
		x[i] ^= x[m];
		int cnt = 0;
		for (int j = 0; j < n; j++)
			if (x[i] & (1 << j)) cnt++;
		if (cnt <= k) ans++;
	}
	cout << ans << endl;
}