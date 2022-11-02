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

using namespace std;

const int maxN = 110000;

int n, m, x, y;
int a[maxN], b[maxN];
set < pair < int, int > > S;
vector < pair < int, int > > res;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d%d%d%d", &n, &m, &x, &y);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	for (int i = 0; i < m; ++i)
		scanf("%d", &b[i]), S.insert(make_pair(b[i], i));

	for (int i = 0; i < n; ++i) {
		int l = a[i] - x;
		set < pair < int, int > > :: iterator j = S.lower_bound(make_pair(l, -1));
		if (j != S.end()) {
			if (j->first <= a[i] + y) {
				res.push_back(make_pair(i, j->second));
				S.erase(j);
			}
		}
	}

	printf("%d\n", res.size());
	for (int i = 0; i < res.size(); ++i)
		printf("%d %d\n", res[i].first + 1, res[i].second + 1);
	return 0;
}