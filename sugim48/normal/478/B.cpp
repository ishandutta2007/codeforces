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

ll calc(ll x) {
	return x * (x - 1) / 2;
}

int main() {
	int n, m; cin >> n >> m;
	cout << (m - n % m) * calc(n / m) + (n % m) * calc(n / m + 1) << ' ' << calc(n - m + 1) << ' ' << endl;
}