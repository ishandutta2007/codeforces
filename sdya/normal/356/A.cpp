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

const int maxN = 310000;
int n, m;
int p[maxN];
set < int > S;

vector < int > get(int l, int r) {
	set < int > ::iterator it = S.lower_bound(l);
	vector < int > res;
	while (it != S.end()) {
		if (*it <= r) {
			res.push_back(*it);
		} else {
			break;
		}
		++it;
	}
	return res;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		S.insert(i + 1);
	}

	for (int i = 0; i < m; ++i) {
		int l, r, x;
		scanf("%d%d%d", &l, &r, &x);
		vector < int > a = get(l, r);
		for (int j = 0; j < a.size(); ++j) {
			if (a[j] != x) {
				p[a[j]] = x;
				S.erase(a[j]);
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		printf("%d ", p[i]);
	}
	printf("\n");


	return 0;
}