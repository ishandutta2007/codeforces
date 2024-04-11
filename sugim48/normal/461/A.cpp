#define _USE_MATH_DEFINES
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
	int n; cin >> n;
	vector<ll> a(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a.begin(), a.end());
	ll ans = 0; int cnt = 1;
	for (int i = 0; i < n; i++) {
		cnt = min(cnt + 1, n);
		ans += cnt * a[i];
	}
	cout << ans << endl;
}