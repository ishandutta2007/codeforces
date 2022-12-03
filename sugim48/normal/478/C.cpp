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
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
typedef pair<double, int> d_i;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> d_d;
struct edge { int u, v; ll w; };

int MOD = 1000000007;

int main() {
	vector<ll> v(3); cin >> v[0] >> v[1] >> v[2];
	sort(v.begin(), v.end());
	ll x = v[0] + v[1], y = v[2];
	if (x > y) swap(x, y);
	if (x * 2 < y) cout << x << endl;
	else cout << (x + y) / 3 << endl;
}