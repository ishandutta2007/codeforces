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

const int maxN = 3100;
int a[maxN], n;
int s[maxN];

int get(vector < int > cnt) {
	for (int i = 0; i < cnt.size(); ++i) {
		s[i] = cnt[i];
		if (i > 0) {
			s[i] += s[i - 1];
		}
	}

	int n = cnt.size();
	const int inf = 1000000000;
	vector < vector < int > > dp(n, vector < int > (n, inf));

	dp[0][0] = 0;
	for (int i = 0; i + 1 < n; ++i) {
		for (int j = 0; j <= i; ++j) {
			if (dp[i][j] == inf) {
				continue;
			}

			dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + s[i] + (i - j));
			dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + s[n - 1] - s[i]);
		}
	}
	int res = inf;
	for (int i = 0; i < n; ++i) {
		res = min(res, dp[n - 1][i]);
	}
	return res;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	vector < int > d;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		d.push_back(abs(a[i]));
	}
	sort(d.begin(), d.end());
	d.resize(unique(d.begin(), d.end()) - d.begin());

	int res = 0;
	for (int t = d.size() - 1; t >= 0; --t) {
		vector < int > cnt;
		int buf = 0;
		for (int i = 0; i < n; ++i) {
			if (abs(a[i]) < d[t]) {
				++buf;
			} else if (abs(a[i]) == d[t]) {
				cnt.push_back(buf);
				buf = 0;
			}
		}
		cnt.push_back(buf);
		if (d[t] == 0) {
			continue;
		}
		res += get(cnt);
	}
	printf("%d\n", res);


	return 0;
}