#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <iomanip>
#include <set>
#include <map>
#include <numeric>
#include <deque>
#include <unordered_set>
#include <unordered_map>
using namespace std;

int n, m;
int a[110][110];
int x[110], y[110];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> a[i][j];
	for (int i = 0; i < n; ++i)
		x[i] = 1;
	for (int j = 0; j < m; ++j)
		y[j] = 1;
	bool ok = 1;
	while (ok) {
		ok = 0;
		for (int i = 0; i < n; ++i) {
			int s = 0;
			for (int j = 0; j < m; ++j)
				s += a[i][j] * x[i] * y[j];
			if (s < 0) {
				ok = 1;
				x[i] *= -1;
			}
		}
		for (int j = 0; j < m; ++j) {
			int s = 0;
			for (int i = 0; i < n; ++i)
				s += a[i][j] * x[i] * y[j];
			if (s < 0) {
				ok = 1;
				y[j] *= -1;
			}
		}
	}
	vector<int> p, q;
	for (int i = 0; i < n; ++i)
		if (x[i] == -1)
			p.push_back(i + 1);
	for (int j = 0; j < m; ++j)
		if (y[j] == -1)
			q.push_back(j + 1);
	cout << p.size();
	for (int u : p)
		cout << " " << u;
	cout << '\n';
	cout << q.size();
	for (int u : q)
		cout << " " << u;
}