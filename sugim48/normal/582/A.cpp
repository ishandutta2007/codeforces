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
	priority_queue<int> pq;
	for (int i = 0; i < n * n; i++) {
		int x; scanf("%d", &x);
		pq.push(x);
	}
	vector<int> a;
	map<int, int> mp;
	while (!pq.empty()) {
		int x = pq.top(); pq.pop();
		if (mp[x] == 0) {
			for (int i = 0; i < a.size(); i++)
				mp[gcd(x, a[i])] += 2;
			a.push_back(x);
		}
		else mp[x]--;
	}
	for (int i = 0; i < n; i++)
		cout << a[i] << ' ';
	cout << endl;
}