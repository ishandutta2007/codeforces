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
int a[maxN], b[maxN], c[maxN];
int n, m, p;

unordered_map < int, int > correct, current;

void addElement(int x, int &matched) {
	if (correct.count(x) && correct[x] == current[x]) {
		--matched;
	}
	++current[x];
	if (correct.count(x) && correct[x] == current[x]) {
		++matched;
	}
}

void removeElement(int x, int &matched) {
	if (correct.count(x) && correct[x] == current[x]) {
		--matched;
	}
	--current[x];
	if (correct.count(x) && correct[x] == current[x]) {
		++matched;
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d%d", &n, &m, &p);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < m; ++i) {
		scanf("%d", &b[i]);
		++correct[b[i]];
	}

	vector < int > res;
	for (int start = 0; start < p && start < n; ++start) {
		int k = 0;
		int index = start;
		while (index < n) {
			c[k++] = index;
			index += p;
		}

		if (k < m) {
			continue;
		}
		int matched = 0;
		current.clear();
		for (int i = 0; i < m; ++i) {
			addElement(a[c[i]], matched);
		}
		if (matched == correct.size()) {
			res.push_back(start);
		}
		for (int i = m; i < k; ++i) {
			addElement(a[c[i]], matched);
			removeElement(a[c[i - m]], matched);
			if (matched == correct.size()) {
				res.push_back(c[i - m + 1]);
			}
		}
	}
	sort(res.begin(), res.end());
	printf("%d\n", res.size());
	for (int i = 0; i < res.size(); ++i) {
		printf("%d ", res[i] + 1);
	}
	printf("\n");

	return 0;
}