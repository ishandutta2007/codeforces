#include <cassert>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <bitset>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <stack>
#include <cmath>
#include <ctime>
#include <unordered_set>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 50;
const int maxL = 110000;
int n;
int cnt[maxN];

char res[maxL];

bool canbuild(int m) {
	vector < int > odd;
	int len = 0;
	for (int i = 0; i < n; ++i) {
		int t = cnt[i] / m;
		if (t % 2 == 1) {
			odd.push_back(i);
		}
		len += t;
	}

	if (odd.size() > 1) {
		return false;
	}
	int start = 0;
	for (int i = 0; i < m; ++i, start += len) {
		int x = start, y = start + len - 1;
		for (int j = 0; j < n; ++j) {
			int t = cnt[j] / m;
			if (t % 2 == 0) {
				for (int k = 0; k < t / 2; ++k) {
					res[x++] = 'a' + j;
					res[y--] = 'a' + j;
				}
			}
		}
		for (int j = 0; j < n; ++j) {
			int t = cnt[j] / m;
			if (t % 2 == 1) {
				for (int k = 0; k < t; ++k) {
					res[x++] = 'a' + j;
				}
			}
		}
	}
	return true;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	int s = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &cnt[i]);
		s += cnt[i];
	}

	for (int i = s; i >= 1; --i) {
		bool isok = true;
		for (int j = 0; j < n; ++j) {
			if (cnt[j] % i != 0) {
				isok = false;
			}
		}
		if (isok && canbuild(i)) {
			if ((s / i) % 2 == 0) {
				i *= 2;
			}
			printf("%d\n", i);
			puts(res);
			return 0;
		}
	}

	printf("0\n");
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < cnt[i]; ++j) {
			printf("%c", 'a' + i);
		}
	}
	printf("\n");

	return 0;
}