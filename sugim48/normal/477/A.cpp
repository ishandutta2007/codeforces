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

ll calc(ll x) {
	return x * (x + 1) / 2 % 1000000007;
}

int main() {
	ll a, b; cin >> a >> b;
	ll x = (a + b * calc(a)) % 1000000007;
	cout << x * calc(b - 1) % 1000000007 << endl;
}