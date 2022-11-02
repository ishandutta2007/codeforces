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

const int inf = 1100000000;
const int maxN = 110000;
int n;
int h[maxN], l[maxN], r[maxN];

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d%d", &h[i], &l[i], &r[i]);
	}

	vector < pair < int, int > > events;
	for (int i = 0; i < n; ++i) {
		events.push_back(make_pair(l[i], h[i]));
		events.push_back(make_pair(r[i], -h[i]));
	}
	sort(events.begin(), events.end());
	vector < pair < int, int > > res;

	multiset < int > current;
	int y = 0, x = -inf;
	for (int i = 0; i < events.size(); ++i) {
		int x = events[i].first;
		int y = events[i].second;
		res.push_back(make_pair(x, (current.empty() ? 0 : *current.rbegin())));
		if (y > 0) {
			current.insert(y);
		} else {
			current.erase(current.find(-y));
		}

		int curY = (current.empty() ? 0 : *current.rbegin());
		res.push_back(make_pair(x, curY));
	}

	vector < pair < int, int > > ans;
	while (true) {
		ans.clear();
		ans.push_back(res[0]);
		for (int i = 1; i < res.size(); ++i) {
			if (i + 1 < res.size() && res[i + 1].first == res[i].first && res[i].first == ans.back().first) {
				continue;
			}
			if (i + 1 < res.size() && res[i + 1].second == res[i].second && res[i].second == ans.back().second) {
				continue;
			}
			ans.push_back(res[i]);
		}
		if (ans.size() == res.size()) {
			break;
		}
		res = ans;
	}
	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); ++i) {
		printf("%d %d\n", ans[i].first, ans[i].second);
	}
	return 0;
}