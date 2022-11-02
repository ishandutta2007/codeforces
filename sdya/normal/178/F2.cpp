#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>
#include <cstring>
#include <string>
#include <cmath>
#include <queue>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 2100;

int n, k;
string s[maxN];

int d[maxN][maxN];
int ans[maxN];

struct node {
	int cnt;
	int d[110];
	node * children[26];
	node() {
		for (int i = 0; i < 26; ++i)
			children[i] = NULL;
		cnt = 0;
		for (int i = 0; i < 110; ++i)
			d[i] = -1000000000;
	}
};

void add(node * root, string s) {
	node * cur = root;
	for (int i = 0; i < s.size(); ++i)
		if (cur->children[s[i] - 'a'] != NULL) {
			cur = cur->children[s[i] - 'a'];
		} else {
			cur->children[s[i] - 'a'] = new node();
			cur = cur->children[s[i] - 'a'];
		}
	++cur->cnt;
}

int dp[110][110];

void dfs(node * root, int depth = 0) {
	vector < int > children;
	for (int i = 0; i < 26; ++i)
		if (root->children[i] != NULL) children.push_back(i);

	if (children.size() == 0) {
		for (int i = 0; i <= root->cnt; ++i)
			root->d[i] = (i * (i - 1)) / 2 * depth;
		return ;
	}

	for (int i = 0; i < children.size(); ++i)
		dfs(root->children[children[i]], depth + 1);

	for (int i = 0; i <= children.size(); ++i)
		for (int j = 0; j <= k; ++j)
			dp[i][j] = -1000000000;

	for (int i = 0; i <= root->cnt; ++i)
		dp[0][i] = (i * (i - 1)) / 2 * depth;

	for (int i = 1; i <= children.size(); ++i) {
		for (int j = 0; j <= k; ++j)
			for (int l = 0; l <= k && j + l <= k; ++l)
				if (dp[i - 1][l] != -1000000000 && root->children[children[i - 1]]->d[j] != -1000000000)
					dp[i][j + l] = max(dp[i][j + l], dp[i - 1][l] + root->children[children[i - 1]]->d[j] + j * l * depth);
	}

	for (int i = 0; i <= k; ++i)
		root->d[i] = dp[children.size()][i];
}

void solve() {
	node * root = new node();
	for (int i = 0; i < n; ++i)
		add(root, s[i]);

	dfs(root);
	printf("%d\n", root->d[k]);
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			for (int l = 0; l < s[i].size() && l < s[j].size(); ++l) {
				if (s[i][l] == s[j][l]) d[i][j] = l + 1; else break;
			}
		}
	}

	solve();

	return 0;

	int res = 0;
	for (int i = 0; i < (1 << n); ++i) {
		int bits = 0;
		for (int j = 0; j < n; ++j)
			if (i & (1 << j)) ++bits;

		int score = 0;
		for (int j = 0; j < n; ++j)
			if (i & (1 << j))
				for (int l = j + 1; l < n; ++l)
					if (i & (1 << l))
						score += d[j][l];

		/*if (bits > 1) {
			for (int j = 0; j < n; ++j)
				if (i & (1 << j)) {
					ans[i] = ans[i - (1 << j)];
					for (int l = j + 1; l < n; ++l)
						if (i & (1 << l)) ans[i] += d[j][l];
					break;
				}
		}*/

		if (bits == k) {
			res = max(res, score);
		}
	}
	printf("%d\n", res);

	return 0;
}