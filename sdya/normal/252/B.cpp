#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <cmath>
#include <stack>
#include <ctime>
#include <unordered_map>
#include <unordered_set>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

bool check(const vector < int > &a) {
	bool isUp = true;
	for (int i = 1; i < a.size(); ++i) {
		if (a[i] < a[i - 1]) {
			isUp = false;
		}
	}
	bool isDown = true;
	for (int i = 1; i < a.size(); ++i) {
		if (a[i] > a[i - 1]) {
			isDown = false;
		}
	}
	return !isUp && !isDown;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n;
	cin >> n;
	vector < int > a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	map < int, vector < int > > M;
	for (int i = 0; i < n; ++i) {
		if (M[a[i]].size() == 5) {
			M[a[i]].pop_back();
		}
		M[a[i]].push_back(i);
	}

	for (map < int, vector < int > > ::iterator it = M.begin(); it != M.end(); ++it) {
		for (map < int, vector < int > > ::iterator jt = M.begin(); jt != M.end(); ++jt) {
			for (int x = 0; x < it->second.size(); ++x) {
				for (int y = 0; y < jt->second.size(); ++y) {
					int u = it->second[x];
					int v = jt->second[y];
					if (it->first == jt->first) {
						continue;
					}
					swap(a[u], a[v]);
					if (check(a)) {
						cout << u + 1 << " " << v + 1 << endl;
						return 0;
					}
					swap(a[u], a[v]);
				}
			}
		}
	}
	cout << -1 << endl;

	return 0;
}