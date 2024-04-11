#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cstring>
#include <climits>
#include <cmath>
#include <map>
#include <queue>
#include <set>
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
struct edge { int u, v; ll w; };

int main() {
	int n, w; cin >> n >> w;
	vector<ll> a(n), b(w);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	for (int j = 0; j < w; j++) scanf("%d", &b[j]);
	n--; w--;
	vector<ll> da(n), db(w);
	for (int i = 0; i < n; i++) da[i] = a[i + 1] - a[i] + 1000000000;
	for (int j = 0; j < w; j++) db[j] = b[j + 1] - b[j] + 1000000000;
	if (n < w) {
		cout << 0 << endl;
		return 0;
	}
	ll X = 1000000007;
	ll x = 1, xa = 0, xb = 0;
	for (int k = 0; k < w; k++) x = (x * X) % 2147483647;
	for (int i = 0; i < w; i++) xa = (xa * X + da[i]) % 2147483647;
	for (int j = 0; j < w; j++) xb = (xb * X + db[j]) % 2147483647;
	int ans = 0;
	for (int i = w; ; i++) {
		if (xa == xb) ans++;
		if (i == n) break;
		xa = (xa * X + da[i] - da[i - w] * x) % 2147483647;
		xa = (xa + 2147483647) % 2147483647;
	}
	cout << ans << endl;
}