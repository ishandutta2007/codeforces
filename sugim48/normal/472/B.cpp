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
	int n, k; cin >> n >> k;
	vector<int> f(n);
	for (int i = 0; i < n; i++) cin >> f[i];
	sort(f.begin(), f.end(), greater<int>());
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		a[i / k] = max(a[i / k], (f[i] - 1) * 2);
	int ans = 0;
	for (int i = 0; i < n; i++) ans += a[i];
	cout << ans << endl;
}