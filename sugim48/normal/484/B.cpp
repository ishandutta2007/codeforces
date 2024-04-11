#define _USE_MATH_DEFINES
#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstring>
#include <ctime>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
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
struct edge { int u, v; double w; };

ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;

int main() {
	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a.begin(), a.end());
	a.erase(unique(a.begin(), a.end()), a.end());
	n = a.size();
	vector<int> b(2000001);
	for (int i = 0; i < n; i++) b[a[i]] = a[i];
	for (int j = 1; j <= 2000000; j++)
		b[j] = max(b[j], b[j - 1]);
	int ans = 0;
	for (int i = 0; i < n; i++)
		for (int j = a[i] - 1; j <= 2000000; j += a[i])
			if (b[j] >= a[i])
				ans = max(ans, b[j] % a[i]);
	cout << ans << endl;
}