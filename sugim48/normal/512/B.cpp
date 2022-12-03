#define _USE_MATH_DEFINES
#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cfloat>
#include <climits>
#include <cstdlib>
#include <cstring>
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
struct edge { int u, v; ll w; };

ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;

ll gcd(ll a, ll b) {
	if (b == 0) return abs(a);
	else return gcd(b, a % b);
}

int main() {
	int n; cin >> n;
	vector<int> dist(n), cost(n);
	for (int k = 0; k < n; k++)
		cin >> dist[k];
	for (int k = 0; k < n; k++)
		cin >> cost[k];
	map<int, int> mp;
	mp[0] = 0;
	for (int k = 0; k < n; k++) {
		int l = dist[k], c = cost[k];
		vector<int> a, b;
		for (auto it = mp.begin(); it != mp.end(); it++) {
			int x = it->first, y = it->second;
			a.push_back(gcd(x, l));
			b.push_back(y + c);
		}
		for (int i = 0; i < a.size(); i++)
			if (mp.count(a[i])) mp[a[i]] = min(mp[a[i]], b[i]);
			else mp[a[i]] = b[i];
	}
	if (mp.count(1)) cout << mp[1] << endl;
	else cout << -1 << endl;
}