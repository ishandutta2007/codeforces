#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <set>
#include <string>
#include <map>
#include <algorithm>
#include <bitset>
#include <queue>
#include <stack>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 1100;

int k, n;
vector < pair < int, int > > a;
vector < pair < int, int > > b;

vector < int > res[maxN];
long long cost[maxN];
int t[maxN];

bool comp(int x, int y) {
	return cost[x] < cost[y];
}

void print() {
	for (int i = 1; i <= k; ++i)
		sort(res[i].begin(), res[i].end(), comp);

	long long ans = 0;
	for (int i = 1; i <= k; ++i) {
		bool good = false;
		for (int j = 0; j < res[i].size(); ++j)
			if (t[res[i][j]] == 1) good = true;
		for (int j = 0; j < res[i].size(); ++j)
			ans += 2 * cost[res[i][j]];
		if (good) {
			ans -= cost[res[i][0]];
		}
	}

	cout << (ans / 2) << "." << (ans % 2 == 0 ? 0 : 5) << endl;
	for (int i = 1; i <= k; ++i) {
		printf("%d ", res[i].size());
		for (int j = 0; j < res[i].size(); ++j)
			printf("%d ", res[i][j]);
		printf("\n");
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; ++i) {
		int c;
		scanf("%d%d", &c, &t[i]);
		cost[i] = c;
		if (t[i] == 1) a.push_back(make_pair(c, i)); else
			b.push_back(make_pair(c, i));
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	if (a.size() >= k) {
		int l = a.size();
		for (int i = 0; i < l - (k - 1); ++i)
			res[1].push_back(a[i].second);
		for (int i = l - (k - 1); i < l; ++i)
			res[i - (l - (k - 1)) + 2].push_back(a[i].second);
		for (int i = 0; i < b.size(); ++i)
			res[1].push_back(b[i].second);
	} else {
		int l = a.size();
		for (int i = 0; i < l; ++i)
			res[i + 1].push_back(a[i].second);
		for (int i = 0; i < k - l; ++i)
			res[l + 1 + i].push_back(b[i].second);
		for (int i = k - l; i < b.size(); ++i)
			res[l + 1].push_back(b[i].second);
	}
	print();
	return 0;
}