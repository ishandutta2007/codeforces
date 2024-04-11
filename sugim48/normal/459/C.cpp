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
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
typedef pair<double, int> d_i;
typedef pair<ll, ll> ll_ll;
struct edge { int u, v; ll w; };

int main() {
	int n, k, d; cin >> n >> k >> d;
	ll pow = 1;
	for (int i = 0; i < d; i++) {
		pow *= k;
		if (pow >= n) break;
	}
	if (pow < n) {
		cout << -1 << endl;
		return 0;
	}
	vector<int> v(n);
	for (int i = 0; i < n; i++) v[i] = i;
	for (; d > 0; d--) {
		for (int i = 0; i < n; i++) {
			printf("%d ", v[i] % k + 1);
			v[i] /= k;
		}
		printf("\n");
	}
}