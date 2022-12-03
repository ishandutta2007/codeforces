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
struct edge { int u, v; ll w; int i; bool used; };
 
int MOD = 1000000007;

int main() {
	int n; cin >> n;
	vector<int> a(n), b(n);
	for (int i = 0; i < n; i++)
		cin >> a[i] >> b[i];
	vector<i_i> v(n);
	for (int i = 0; i < n; i++)
		v[i] = i_i(b[i], a[i]);
	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++) {
		a[i] = v[i].second;
		b[i] = v[i].first;
	}
	vector<int> _a = a;
	sort(_a.begin(), _a.end());
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (b[i] >= ans && a[i] == _a[i])
			ans = b[i];
		else
			ans = max(ans, _a[i]);
	}
	cout << ans << endl;
}