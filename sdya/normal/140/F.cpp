#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <bitset>

using namespace std;

const int maxN = 210000;
pair < int, int > p[maxN];
int n, k;

set < pair < int, int > > candidates;
vector < pair < int, int > > res;

set < long long > S;

inline long long code(long long x, long long y) {
	return x * 4000000007LL + y;
}

bool check(pair < int, int > c) {
	c.first += c.first;
	c.second += c.second;
	int miss = 0;
	for (int i = 1; i <= n; ++i) {
		long long cur = code(c.first - p[i].first, c.second - p[i].second);
		if (S.find(cur) == S.end()) {
			++miss;
			if (miss > k) {
				return false;
			}
		}
	}
	return true;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	srand(987892);
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; ++i) {
		scanf("%d%d", &p[i].first, &p[i].second);
		p[i].first *= 2;
		p[i].second *= 2;
	}
	if (n <= k) {
		printf("-1\n");
		return 0;
	}
	sort(p + 1, p + n + 1);
	for (int i = 1; i <= n; ++i) {
		S.insert(code(p[i].first, p[i].second));
	}

	for (int i = 1; i <= min(n, 11); ++i)
		for (int j = n; j > max(0, n - 11); --j)
			if (i + n - j <= k + 1) {
				candidates.insert(make_pair((p[i].first + p[j].first) / 2, (p[i].second + p[j].second) / 2));
			}

	random_shuffle(p + 1, p + n + 1);
	for (set < pair < int, int > > :: iterator it = candidates.begin(); it != candidates.end(); ++it)
		if (check(* it)) {
			res.push_back(* it);
		}
	printf("%d\n", res.size());
	for (int i = 0; i < res.size(); ++i)
		printf("%.1lf %.1lf\n", (double)(res[i].first) / 2.0, (double)(res[i].second) / 2.0);
	return 0;
}