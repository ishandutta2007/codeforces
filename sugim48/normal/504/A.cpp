#define _USE_MATH_DEFINES
#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cfloat>
#include <climits>
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
struct edge { int u, v, w; };

ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;
int INF = INT_MAX / 2;

int main() {
	int n; cin >> n;
	vector<int> d(n), s(n);
	for (int i = 0; i < n; i++)
		scanf("%d%d", &d[i], &s[i]);
	queue<int> q;
	for (int i = 0; i < n; i++)
		if (d[i] == 1) q.push(i);
	vector<int> a, b;
	while (!q.empty()) {
		int i = q.front(); q.pop();
		if (d[i] == 0) continue;
		int j = s[i];
		a.push_back(i); b.push_back(j);
		d[i] = 0; s[i] = 0;
		d[j]--; s[j] ^= i;
		if (d[j] == 1) q.push(j);
	}
	int m = a.size();
	cout << m << endl;
	for (int k = 0; k < m; k++)
		printf("%d %d\n", a[k], b[k]);
}