#include <bits/stdc++.h>

using namespace std;

// tried writing top-down DP because why not

char seq[2][60];

vector<pair<int, int>> subs[26];

bool pos[2][60][60][26], stored[2][60][60][26];

int minSplits[60][60], slen[2];

// could seq[k][i..j] have originated from a single 'c'?
bool canTransform(int k, int i, int j, int c) {
	// printf("check CT %d %d %d %d\n", k, i, j, c);
	if (stored[k][i][j][c]) return pos[k][i][j][c];
	if (i > j) return false;
	if (i == j) return (seq[k][i] == c+'a');
	bool result = false;
	for (int sp = i; sp < j; ++sp) {
		for (auto pps : subs[c]) {
			if (canTransform(k, i, sp, pps.first) && canTransform(k, sp + 1, j, pps.second)) {
				// printf("psplit %d sub %d %d from cct %d %d %d %d\n", sp, pps.first, pps.second, k, i, j, c);
				result = true;
			}
		}
	}
	stored[k][i][j][c] = true;
	return (pos[k][i][j][c] = result);
}

int findMinSplits(int i, int j) {
	// printf("FMS %d %d\n", i, j);
	if (i == slen[0] && j == slen[1]) return 0;
	else if (minSplits[i][j] != -1) return minSplits[i][j];
	int ans = 1000000000; // we shall try to reduce this amount
	for (int iend = i; iend < slen[0]; ++iend) {
		for (int jend = j; jend < slen[1]; ++jend) {
			for (int pickC = 0; pickC < 26; ++pickC) {
				if (canTransform(0, i, iend, pickC) && canTransform(1, j, jend, pickC)) {
					// printf("PS %d %d\n", iend, jend);
					ans = min(ans, findMinSplits(iend+1, jend+1) + 1);
				}
			}
		}
	}
	return minSplits[i][j] = ans;
}

int main() {
	memset(minSplits, -1, sizeof(minSplits));
	scanf("%s %s", seq[0], seq[1]);
	for (int k = 0; k < 2; ++k) slen[k] = strlen(seq[k]);
	int n; scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		char a, b, c; scanf(" %c->%c%c", &a, &b, &c);
		subs[a-'a'].emplace_back(b-'a', c-'a');
		// printf("READ SUB %c->%c%c\n", a, b, c);
	}
	/*
	f(i, i, c) = true iff s[i] = c
	f(i, j, c) = OR {split point k, substitution c->ab} f(i, k, a) && f(k+1, j, b)
	*/
	for (int k = 0; k < 2; ++k) {
		for (int c = 0; c < 26; ++c) {
			for (int i = 0; i < slen[k]; ++i) canTransform(k, i, slen[k]-1, c);
		}
	}
	int ans = findMinSplits(0, 0);
	if (ans == 1000000000) printf("-1\n");
	else printf("%d\n", ans);
	return 0;
}