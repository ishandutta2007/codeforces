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
	vector < int > d;
	node * children[26];
	node() {
		for (int i = 0; i < 26; ++i)
			children[i] = NULL;
		cnt = 0;
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

int dp[30][maxN];

void dfs(node * root, int depth = 0) {
	vector < pair < int, int > > children;
	for (int i = 0; i < 26; ++i)
		if (root->children[i] != NULL) {
			dfs(root->children[i], depth + 1);
			children.push_back(make_pair(root->children[i]->d.size(), i));
		}

	if (children.size() == 0) {
		for (int i = 0; i <= root->cnt; ++i)
			root->d.push_back((i * (i - 1)) / 2 * depth);
		return ;
	}

	if (root->cnt != 0) {
		children.push_back(make_pair(root->cnt + 1, -1));
	}
	sort(children.begin(), children.end());

	int sum = 0;
	for (int i = 0; i < children.size(); ++i) {
		if (i == 0) {
			int index = children[i].second;
			if (index == -1) {
				for (int j = 0; j <= root->cnt; ++j)
					dp[i][j] = (j * (j - 1)) / 2 * depth;
				sum += root->cnt;
			} else {
				for (int j = 0; j < children[i].first; ++j)
					dp[i][j] = root->children[index]->d[j];
				sum += children[i].first - 1;
			}
		} else {
			int index = children[i].second;
			vector < int > cur;
			if (index != -1) {
				cur = root->children[index]->d;
			} else {
				for (int j = 0; j <= root->cnt; ++j)
					cur.push_back((j * (j - 1)) / 2 * depth);
			}

			for (int j = 0; j <= sum + cur.size() - 1; ++j)
				dp[i][j] = 0;
			for (int j = 0; j <= sum; ++j)
				for (int k = 0; k < cur.size(); ++k) {
					dp[i][j + k] = max(dp[i][j + k], dp[i - 1][j] + cur[k] + k * j * depth);
				}
			sum += cur.size() - 1;
		}
	}

	if (sum == 0) {
		dp[children.size() - 1][0] = 0;
	}

	for (int i = 0; i <= sum; ++i)
		root->d.push_back(dp[children.size() - 1][i]);

	for (int i = 0; i < children.size(); ++i) {
		int index = children[i].second;
		if (index != -1) {
			root->children[index]->d.clear();
		}
	}
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

	solve();

	return 0;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			for (int l = 0; l < s[i].size() && l < s[j].size(); ++l) {
				if (s[i][l] == s[j][l]) d[i][j] = l + 1; else break;
			}
		}
	}

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