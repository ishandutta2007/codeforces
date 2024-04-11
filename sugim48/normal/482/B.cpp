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
 
int MOD = 1000000007;

int main() {
	int n, m; cin >> n >> m;
	vector<int> l(m), r(m), q(m);
	for (int j = 0; j < m; j++) scanf("%d%d%d", &l[j], &r[j], &q[j]);
	vector< vector<int> > a(30, vector<int>(n + 1));
	for (int j = 0; j < m; j++) {
		for (int k = 0; k < 30; k++)
			if (q[j] & (1 << k)) {
				a[k][l[j] - 1]++;
				a[k][r[j]]--;
			}
	}
	vector< vector<int> > sum(30, vector<int>(n + 1));
	for (int k = 0; k < 30; k++)
		for (int i = 1; i <= n; i++)
			sum[k][i] = sum[k][i - 1] + a[k][i - 1];
	vector< vector<int> > b(30, vector<int>(n + 1));
	for (int k = 0; k < 30; k++)
		for (int i = 1; i <= n; i++)
			b[k][i] = b[k][i - 1] + (sum[k][i] > 0 ? 1 : 0);
	for (int j = 0; j < m; j++) {
		for (int k = 0; k < 30; k++) {
			if (q[j] & (1 << k)) continue;
			if (b[k][r[j]] - b[k][l[j] - 1] == r[j] - l[j] + 1) {
				cout << "NO" << endl;
				return 0;
			}
		}
	}
	cout << "YES" << endl;
	for (int i = 0; i < n; i++) {
		int x = 0;
		for (int k = 0; k < 30; k++)
			if (sum[k][i + 1] > 0) x += (1 << k);
		printf("%d ", x);
	}
	cout << endl;
}