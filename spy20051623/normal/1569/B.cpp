#include <bits/stdc++.h>

using namespace std;

char s[100];
char r[100][100];

void solve() {
	int n;
	scanf("%d", &n);
	scanf("%s", s);
	vector<int> v;
	for (int i = 0; i < n; ++i) {
		if (s[i] == '2') v.push_back(i);
	}
	if (v.size() == 1 || v.size() == 2) {
		printf("NO\n");
		return;
	}
	printf("YES\n");
	memset(r, 0, sizeof r);
	for (int i = 0; i < n; ++i) {
		r[i][i] = 'X';
	}
	for (int i = 0; i < (int) v.size() - 1; ++i) {
		r[v[i]][v[i + 1]] = '+', r[v[i + 1]][v[i]] = '-';
	}
	if (!v.empty()) r[v.back()][v.front()] = '+', r[v.front()][v.back()] = '-';
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (r[i][j] == '\0') r[i][j] = '=';
		}
	}
	for (int i = 0; i < n; ++i) {
		printf("%s\n", r[i]);
	}
}

int main() {
//	freopen("in.txt", "r", stdin);
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}