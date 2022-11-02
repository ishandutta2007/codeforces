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

const int maxN = 110000;
char s[maxN];
int p[maxN];

int r[maxN];
int cnt[maxN];

int get(int l, int r) {
	return cnt[r] - (l == 0 ? 0 : cnt[l - 1]);
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%s", &s);
	int n = strlen(s);
	for (int i = 0; i < n; ++i) {
		cnt[i] = (s[i] == '[');
		if (i > 0) {
			cnt[i] += cnt[i - 1];
		}
	}
	memset(p, -1, sizeof(p));
	stack<int> q;
	for (int i = 0; i < n; ++i) {
		if (s[i] == '(') {
			q.push(i);
		} else if (s[i] == '[') {
			q.push(i);
		} else if (s[i] == ')') {
			if (!q.empty() && s[q.top()] == '(') {
				int l = q.top();
				q.pop();
				p[l] = i;
				p[i] = l;
			} else {
				while (!q.empty()) {
					q.pop();
				}
			}
		} else if (s[i] == ']') {
			if (!q.empty() && s[q.top()] == '[') {
				int l = q.top();
				q.pop();
				p[l] = i;
				p[i] = l;
			} else {
				while (!q.empty()) {
					q.pop();
				}
			}
		}
	}

	memset(r, -1, sizeof(r));
	for (int i = n - 1; i >= 0; --i) {
		if (p[i] < i) {
			continue;
		}

		bool isOk = true;
		int j = i + 1;
		while (j < p[i]) {
			if (p[j] < j) {
				isOk = false;
				break;
			}
			j = p[j] + 1;
		}
		if (isOk) {
			r[i] = p[i];
			r[i] = max(r[i], r[p[i] + 1]);
		}
	}

	int index = -1, res = 0;
	for (int i = 0; i < n; ++i) {
		if (get(i, r[i]) > res) {
			res = get(i, r[i]);
			index = i;
		}
	}

	if (index == -1) {
		printf("0\n\n");
		return 0;
	} else {
		printf("%d\n", res);
		for (int i = index; i <= r[index]; ++i) {
			printf("%c", s[i]);
		}
		printf("\n");
	}

	return 0;
}