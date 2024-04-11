#define _CRT_SECURE_NO_WARNINGS
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

const int maxN = 210000;
int n, m;
map < int, vector < int > > M;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		if (x == n && y == n) {
			printf("-1\n");
			return 0;
		}
		M[x].push_back(y);
	}

	vector < int > a = M[1];
	set < pair < int, int > > S;
	if (M[1].size() == 0) {
		S.insert(make_pair(1, n));
	} else {
		S.insert(make_pair(1, a[0] - 1));
	}

	M.erase(1);
	int x = 1;
	for (map < int, vector < int > > ::iterator it = M.begin(); it != M.end() && S.size() > 0; ++it) {
		vector < int > current = it->second;
		sort(current.begin(), current.end());
		int curX = it->first;
		if (curX > x + 1) {
			pair < int, int > current = *S.begin();
			S.clear();
			current.second = n;
			S.insert(current);
		}
		current.push_back(n + 1);

		for (int i = 0; i < current.size(); ++i) {
			set < pair < int, int > > ::iterator it = S.lower_bound(make_pair(current[i], n + 1));
			set < pair < int, int > > ::iterator jt = S.end();
			if (it == S.end()) {
				jt = S.find(*S.rbegin());
			} else if (it != S.begin()) {
				jt = it;
				--jt;
			}
			if (jt != S.end()) {
				if ((i == 0 || current[i - 1] < jt->second) && current[i] - 1 > jt->second) {
					pair < int, int > added(jt->first, current[i] - 1);
					S.erase(jt);
					S.insert(added);

					set < pair < int, int > > ::iterator kt = S.find(added);
					++kt;
					if (kt != S.end() && kt->first <= added.second) {
						int bound = kt->second;
						S.erase(kt);
						S.erase(added);
						added.second = bound;
						S.insert(added);
					}
				}
			}
		}
		for (int i = 0; i < current.size() && S.size() > 0; ++i) {
			set < pair < int, int > > ::iterator it = S.lower_bound(make_pair(current[i], n + 1));
			set < pair < int, int > > ::iterator jt = S.end();
			if (it == S.end()) {
				jt = S.find(*S.rbegin());
			} else if (it != S.begin()) {
				jt = it;
				--jt;
			}
			if (jt != S.end() && jt->first <= current[i] && jt->second >= current[i]) {
				int l1 = jt->first;
				int r1 = current[i] - 1;
				int l2 = current[i] + 1;
				int r2 = jt->second;
				S.erase(jt);
				if (l1 <= r1) {
					S.insert(make_pair(l1, r1));
				}
				if (l2 <= r2) {
					S.insert(make_pair(l2, r2));
				}
			}
		}
		x = curX;
	}

	if (x < n && S.size() > 0) {
		pair < int, int > current = *S.begin();
		S.clear();
		current.second = n;
		S.insert(current);
	}

	if (S.size() > 0 && S.rbegin()->second == n) {
		printf("%d\n", n + n - 2);
	} else {
		printf("-1\n");
	}

	return 0;
}