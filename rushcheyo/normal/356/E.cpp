#include <bits/stdc++.h>
using namespace std;

typedef long long i64;
typedef unsigned long long hash_t;

const int N = 100005;
const hash_t BSE = 131;

char s[N];
int n, cnt[N][26];
bool dp[N][18];
hash_t pw[N], hs[N];
i64 ans0, delta[N][26], tag[N];

hash_t gethash(int l, int r) {
	return hs[r] - hs[l - 1] * pw[r - l + 1];
}

i64 sq(int x) { return (i64)x * x; }

int getlcp(int i, int j) {
	int l = 0, r = n - j + 1;
	while (l < r) {
		int mid = l + r + 1 >> 1;
		if (gethash(i, i + mid - 1) == gethash(j, j + mid - 1)) l = mid;
		else r = mid - 1;
	}
	return l;
}

int main() {
	scanf("%s", s + 1);
	n = strlen(s + 1);
	for (int i = 1; i <= n; i++) {
		s[i] -= 'a';
		copy(cnt[i - 1], cnt[i - 1] + 26, cnt[i]);
		cnt[i][s[i]]++;
	}
	pw[0] = 1;
	for (int i = 1; i <= n; i++) pw[i] = pw[i - 1] * BSE;
	for (int i = 1; i <= n; i++) hs[i] = hs[i - 1] * BSE + s[i] + 1;
	for (int i = 1; i <= n; i++) {
		dp[i][0] = true;
		for (int j = 1, r; (r = i + (1 << j + 1) - 2) <= n; j++) {
			int mid = i + (1 << j) - 1;
			dp[i][j] = dp[i][j - 1] && gethash(i, mid - 1) == gethash(mid + 1, r) &&
				cnt[r][s[mid]] - cnt[i - 1][s[mid]] == 1;
		}
	}
	for (int i = 1; i <= n; i++)
		for (int j = 0, r; (r = i + (1 << j + 1) - 2) <= n; j++) {
			int mid = i + (1 << j) - 1;
			i64 val = sq((1 << j + 1) - 1);
			if (dp[i][j]) {
				ans0 += val;
				for (int c = 0; c < 26; c++)
					if (c != s[mid] && cnt[r][c] - cnt[i - 1][c] > 0)
						delta[mid][c] -= val;
				if (j != 0) {
					tag[i] -= val,  tag[mid] += val;
					tag[mid + 1] -= val, tag[r + 1] += val;
				}
			} else {
				if (dp[i][j - 1] && gethash(i, mid - 1) == gethash(mid + 1, r))
					for (int c = 0; c < 26; c++)
						if (cnt[r][c] - cnt[i -  1][c] == 0)
							delta[mid][c] += val;
				int lcp = getlcp(i, mid + 1);
				if (lcp < (1 << j) - 1 && gethash(i + lcp + 1, mid - 1) == gethash(mid + lcp + 2, r)) {
					if (dp[i][j - 1]) {
						int c = s[i + lcp];
						if (cnt[r][s[mid]] - cnt[i - 1][s[mid]] - (s[mid + 1 + lcp] == s[mid])
							+ (c == s[mid]) == 1)
							delta[mid + 1 + lcp][c] += val;
					}
					if (dp[mid + 1][j - 1]) {
						int c = s[mid + 1 + lcp];
						if (cnt[r][s[mid]] - cnt[i - 1][s[mid]] - (s[i + lcp] == s[mid])
							+ (c == s[mid]) == 1)
							delta[i + lcp][c] += val;
					}
				}
			}
		}
	i64 ans = 0, pre = 0;
	for (int i = 1; i <= n; i++) {
		pre += tag[i];
		for (int c = 0; c < 26; c++)
			ans = max(ans, pre + delta[i][c]);
	}
	ans += ans0;
	cout << ans << endl;
	return 0;
}