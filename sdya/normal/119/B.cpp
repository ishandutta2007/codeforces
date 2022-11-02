#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <bitset>
#include <ctime>
#include <unordered_map>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 110;
int n, m, k;
int a[maxN], p[maxN];

map < vector < int >, int > M;
int cnt;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	m = n / k;
	memset(p, -1, sizeof(p));

	int q;
	cin >> q;
	int mn = 1000000000, mx = -1;
	for (int i = 1; i <= q; ++i) {
		vector < int > b(m);
		for (int j = 0; j < m; ++j) {
			cin >> b[j];
		}
		sort(b.begin(), b.end());
		if (M.count(b)) {
			continue;
		} else {
			M[b] = cnt;
			int s = 0;
			for (int j = 0; j < b.size(); ++j) {
				p[b[j]] = cnt;
				s += a[b[j]];
			}
			++cnt;
			mn = min(mn, s);
			mx = max(mx, s);
		}
	}

	vector < int > left;
	for (int i = 1; i <= n; ++i) {
		if (p[i] == -1) {
			left.push_back(a[i]);
		}
	}

	sort(left.begin(), left.end());
	if (left.size() >= m && M.size() < k) {
		int s = 0;
		for (int i = 0; i < m; ++i) {
			s += left[i];
		}
		mn = min(mn, s);

		reverse(left.begin(), left.end());
		s = 0;
		for (int i = 0; i < m; ++i) {
			s += left[i];
		}
		mx = max(mx, s);
	}

	printf("%.10lf %.10lf\n", (double)(mn) / (double)(m), (double)(mx) / (double)(m));

	return 0;
}