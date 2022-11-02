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
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 210000;
char s[maxN], t[maxN];
int n, m;

int l[maxN], r[maxN];
int cnt[26][maxN];

int get(int k, int l, int r) {
	if (l < 0) {
		l = 0;
	}
	if (r >= m) {
		r = m - 1;
	}
	if (l > r) {
		return 0;
	}
	return cnt[k][r] - (l <= 0 ? 0 : cnt[k][l - 1]);
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%s", &s);
	n = strlen(s);
	scanf("%s", &t);
	m = strlen(t);

	for (int i = 0; i < m; ++i) {
		++cnt[t[i] - 'a'][i];
		for (int j = 0; j < 26; ++j) {
			if (i > 0) {
				cnt[j][i] += cnt[j][i - 1];
			}
		}
	}

	{
		int v = 0;
		for (int i = 0; i < n; ++i) {
			if (v < m && s[i] == t[v]) {
				l[i] = v + 1;
				++v;
			}
			if (i > 0) {
				l[i] = max(l[i], l[i - 1]);
			}
		}
	}
	{
		int v = m - 1, len = 0;
		for (int i = n - 1; i >= 0; --i) {
			if (v >= 0 && s[i] == t[v]) {
				r[i] = len + 1;
				++len;
				--v;
			}
			if (i + 1 < n) {
				r[i] = max(r[i], r[i + 1]);
			}
		}
	}

	bool ok = true;
	for (int i = 0; i < n; ++i) {
		int x = (i == 0 ? 0 : l[i - 1]);
		int y = r[i + 1];
		if (x + y < m - 1) {
			ok = false;
			continue;
		}
		if (get(s[i] - 'a', m - y - 1, x) == 0) {
			ok = false;
		}
	}
	if (ok) {
		printf("Yes\n");
	} else {
		printf("No\n");
	}

	return 0;
}