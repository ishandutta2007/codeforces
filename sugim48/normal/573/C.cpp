#define _USE_MATH_DEFINES
#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cfloat>
#include <climits>
#include <cstring>
#include <cmath>
#include <fstream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <time.h>
#include <unordered_set>
#include <vector>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
typedef pair<double, int> d_i;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> d_d;
struct edge { int v; ll w; };

ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-8;
int INF = INT_MAX / 2;

int main() {
	int n; cin >> n;
	vector<int> d(n);
	vector<unordered_set<int> > G(n);
	for (int i = 0; i < n - 1; i++) {
		int a, b; scanf("%d%d", &a, &b);
		a--; b--;
		d[a]++; d[b]++;
		G[a].insert(b);
		G[b].insert(a);
	}
	int N = n;
	vector<bool> a(n);
	queue<int> q;
	for (int u = 0; u < n; u++)
		if (G[u].size() == 1)
			q.push(u);
	while (N >= 3 && !q.empty()) {
		int u = q.front(); q.pop();
		int v = *G[u].begin();
		G[u].erase(v);
		G[v].erase(u);
		if (d[u] >= 3) a[v] = true;
		if (G[v].size() == 1 && d[v] <= 3 && !a[v])
			q.push(v);
		N--;
	}
	bool yes = true;
	for (int u = 0; u < n; u++)
		if (G[u].size() >= 3)
			yes = false;
	cout << (yes ? "Yes" : "No") << endl;
}