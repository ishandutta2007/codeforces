#include <bits/stdc++.h>

using namespace std;

struct pt {
	int g;
	int fa;
	int s[2];
	int p;
};

pt m[600000];

vector<int> l[25];

int main() {
//	freopen("in.txt", "r", stdin);
	int k;
	scanf("%d", &k);
	getchar();
	int s = 1;
	for (int i = k - 1; i >= 0; --i) {
		for (int j = 0; j < 1 << i; ++j) {
			l[i].push_back(s++);
		}
	}
	for (int i = k - 1; i > 0; --i) {
		for (int j = 0; j < 1 << i; ++j) {
			m[l[i][j]].fa = l[i - 1][j / 2];
			m[l[i - 1][j / 2]].s[j % 2] = l[i][j];
		}
	}
	for (int i = 1; i < 1 << k; ++i) {
		char ch = getchar();
		if (ch == '?') {
			m[i].g = 2;
			m[i].p = 2;
		} else {
			m[i].g = ch - '0';
			m[i].p = 1;
		}
	}
	for (int i = 1; i < 1 << k; ++i) {
		if (m[i].s[0] == 0 || m[i].s[1] == 0)
			continue;
		if (m[i].g == 2)
			m[i].p = m[m[i].s[0]].p + m[m[i].s[1]].p;
		else {
			m[i].p = m[m[i].s[m[i].g]].p;
		}
	}
	int q;
	scanf("%d", &q);
	while (q--) {
		int i;
		char c;
		scanf("%d %c", &i, &c);
		if (c == '?') {
			m[i].g = 2;
		} else {
			m[i].g = c - '0';
		}
		while (i != 0) {
			if (m[i].g == 2) {
				if (m[i].s[0] == 0 || m[i].s[1] == 0)
					m[i].p = 2;
				else
					m[i].p = m[m[i].s[0]].p + m[m[i].s[1]].p;
			} else {
				if (m[i].s[0] == 0 || m[i].s[1] == 0)
					m[i].p = 1;
				else
					m[i].p = m[m[i].s[m[i].g]].p;
			}
			i = m[i].fa;
		}
		printf("%d\n", m[(1 << k) - 1].p);
	}
	return 0;
}