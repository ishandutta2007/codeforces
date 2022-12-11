#include <bits/stdc++.h>

using namespace std;

vector<vector<bool>> BANNED = 
    {{false, false, true, true},
	{false, true, false, true},
	{true, true, true, false},
	{true, true, true, true}};

constexpr int MOD = 1000000007;

int newHash[18000010];
bool taken[9000010];
int rangeCover[3000][3000];
int unqHash[3000][3000];

int main() {
	int m; scanf("%d", &m);
	vector<bool> bitstr(m);
	for (int i = 0; i < m; ++i) {
		int x;
		scanf("%d", &x);
		bitstr[i] = (x == 1);
	}
	vector<bool> endsBanned(m);
	for (int j = 3; j < m; ++j) {
		bool isAllowed = true;
		for (auto bv : BANNED) {
			bool completeMatch = true;
			for (int k = 0; k < 4; ++k) {
				if (bv[k] != bitstr[j - 3 + k]) completeMatch = false;
			}
			if (completeMatch) isAllowed = false;
		}
		endsBanned[j] = !isAllowed;
	}
	for (int i = 0; i < m; ++i) {
		rangeCover[i][i] = 1;
		for (int j = i + 1; j < m; ++j) {
			for (int jump = 0; jump < 4; ++jump) {
				// elements are from j - jump to j
				if (j - jump < i) continue;
				else if (j - jump == i && jump < 3) rangeCover[i][j] = (rangeCover[i][j] + 1) % MOD;
				else if (jump == 3) {
					// we have to check against the banned patterns
					if (!endsBanned[j]) {
						rangeCover[i][j] = (rangeCover[i][j] + (j - jump == i ? 1 : rangeCover[i][j-4])) % MOD;
					}
				} else {
					rangeCover[i][j] = (rangeCover[i][j] + rangeCover[i][j-jump-1]) % MOD;
				}
			}
		}
	}
	// printf("done phase 1\n");
	// part 2: use the Unequaler
	for (int i = 0; i < m; ++i) {
		unqHash[i][i] = (bitstr[i] ? 0 : 1);
	}
	int cHash = 2;

	for (int k = 1; k < m; ++k) {
		// consider the strings of form [i, i + k]
		for (int j = k; j < m; ++j) {
			int toAdd((bitstr[j] ? 9000000 : 0) + unqHash[j - k][j-1]);
			if (newHash[toAdd] == 0) {
				newHash[toAdd] = cHash;
				++cHash;
			}
			unqHash[j-k][j] = newHash[toAdd];
			// printf("%d %d hash %d\n", j-k, j, unqHash[j-k][j]);
		}
	}
	// printf("done phase 2\n");
	vector<int> ans(m);
	for (int i = 0; i < m; ++i) {
		for (int j = i; j < m; ++j) {
			if (!taken[unqHash[i][j]]) {
				taken[unqHash[i][j]] = true;
				ans[j] = (ans[j] + rangeCover[i][j]) % MOD;
			}
		}
	}
	for (int i = 1; i < m; ++i) {
		ans[i] = (ans[i-1] + ans[i]) % MOD;
	}
	for (int i = 0; i < m; ++i) {
		printf("%d\n", ans[i]);
	}
	return 0;
}