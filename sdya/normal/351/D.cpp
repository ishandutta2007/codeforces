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

const int maxN = 110000;
int n, a[maxN];
const int maxD = 350;
int l[maxN], r[maxN];

bool comp(int x, int y) {
	return make_pair(l[x] / maxD, r[x]) < make_pair(l[y] / maxD, r[y]);
}

int order[maxN];
int res[maxN];
int cnt[maxN];
int best[maxN];

deque < int > q[maxN];
unordered_map < int, int > dq[maxN];

void addElement(int value, int position, int &cnt) {
	bool wasOk = dq[value].size() <= 1;
	if (q[value].empty()) {
		q[value].push_back(position);
		++cnt;
	} else {
		int n = q[value].size();
		int diff = -1;
		if (position > q[value].back()) {
			q[value].push_back(position);
			diff = q[value][n] - q[value][n - 1];
		} else {
			q[value].push_front(position);
			diff = q[value][1] - q[value][0];
		}
		++dq[value][diff];
		if (wasOk && dq[value].size() > 1) {
			--cnt;
		}
	}
}

void removeElement(int value, int position, int &cnt) {
	bool wasOk = dq[value].size() <= 1;
	if (q[value].front() == position) {
		q[value].pop_front();
		if (!q[value].empty()) {
			int diff = q[value][0] - position;
			--dq[value][diff];
			if (dq[value][diff] == 0) {
				dq[value].erase(diff);
			}

			if (!wasOk && dq[value].size() <= 1) {
				++cnt;
			}
		} else {
			--cnt;
		}
	} else {
		q[value].pop_back();
		if (!q[value].empty()) {
			int diff = position - q[value].back();
			--dq[value][diff];
			if (dq[value][diff] == 0) {
				dq[value].erase(diff);
			}
			if (!wasOk && dq[value].size() <= 1) {
				++cnt;
			}
		} else {
			--cnt;
		}
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}

	int w;
	scanf("%d", &w);
	for (int i = 0; i < w; ++i) {
		order[i] = i;
		scanf("%d%d", &l[i], &r[i]);
	}
	sort(order, order + w, comp);
	int g = -1, diff = 0, oldl = -1, oldr = -1, p = 0, wq = 0;
	for (int i = 0; i < w; ++i) {
		int v = order[i];
		int curG = l[v] / maxD;
		if (curG != g) {
			memset(cnt, 0, sizeof(cnt));
			wq = 0;
			for (int j = 0; j < maxN; ++j) {
				q[j].clear();
				dq[j].clear();
			}
			diff = 0;
			for (int j = l[v]; j <= r[v]; ++j) {
				++cnt[a[j]];
				if (cnt[a[j]] == 1) {
					++diff;
				}
				addElement(a[j], j, wq);
			}
			g = curG;
		} else {
			for (int j = oldr + 1; j <= r[v]; ++j) {
				++cnt[a[j]];
				if (cnt[a[j]] == 1) {
					++diff;
				}
				addElement(a[j], j, wq);
			}
			if (l[v] < oldl) {
				for (int j = oldl - 1; j >= l[v]; --j) {
					++cnt[a[j]];
					if (cnt[a[j]] == 1) {
						++diff;
					}
					addElement(a[j], j, wq);
				}
			} else {
				for (int j = oldl; j < l[v]; ++j) {
					--cnt[a[j]];
					if (cnt[a[j]] == 0) {
						--diff;
					}
					removeElement(a[j], j, wq);
				}
			}
		}
		oldl = l[v];
		oldr = r[v];

		res[v] = diff + 1;
		if (wq > 0) {
			--res[v];
		}
	}
	for (int i = 0; i < w; ++i) {
		printf("%d\n", res[i]);
	}

	return 0;
}