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
#include <list>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 110000;
int h[maxN], n, m;
int d[maxN];

pair < int, int > s[maxN];

void solve(int l, int r) {
	--r;
	long long res = 0;
	int cnt = 0;
	if (l > r) {
		printf("0\n");
		return;
	}

	res = d[r];

	int m = 0;
	s[m++] = make_pair(d[r], 1);

	long long sum = d[r];
	for (int i = r - 1; i >= l; --i) {
		int cnt = 1;
		while (m > 0 && d[i] >= s[m - 1].first) {
			sum -= (long long)(s[m - 1].first) * (long long)(s[m - 1].second);
			cnt += s[m - 1].second;
			--m;
		}

		s[m++] = make_pair(d[i], cnt);
		sum += (long long)(cnt) * (long long)(d[i]);

		res += sum;
	}

	printf("%I64d\n", res);
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &h[i]);
	}

	for (int i = 0; i + 1 < n; ++i) {
		d[i] = abs(h[i + 1] - h[i]);
	}

	for (int i = 0; i < m; ++i) {
		int l, r;
		scanf("%d%d", &l, &r);
		--l;
		--r;
		solve(l, r);
	}


	return 0;
}