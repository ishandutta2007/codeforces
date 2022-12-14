#include <bits/stdc++.h>
using namespace std;

#define N 22
const int INF = 1e9;

int n, rmh[N*2][30], flag[44];
char s[N][N];

map <pair<int, int>, int> mp;

int dfs(int k, int cur) {
    if (k == 2 * n - 2) return 0;
    if (mp.count(make_pair(k, cur))) return mp[make_pair(k, cur)];
    int rlt, that = (cur | (cur << 1));
    if (k % 2) {
		rlt = -INF;
		for (int c = 0, now; c < 26; c ++) {
			now = that & rmh[k+1][c];
			if (!now) continue;
			rlt = max(rlt, flag[c] + dfs(k + 1, now));
		}
    }
    else {
		rlt = INF;
		for (int c = 0, now; c < 26; c ++) {
			now = that & rmh[k+1][c];
			if (!now) continue;
			rlt = min(rlt, flag[c] + dfs(k + 1, now));
		}
    }
    mp[make_pair(k, cur)] = rlt;
    return rlt;
}

int main() {
	scanf("%d\n", &n);
	flag[0] = 1;
	flag[1] = -1;
	for (int i = 0; i < n; i ++) gets(s[i]);
	for (int i = 0; i < n; i ++) for (int j = 0; j < n; j ++) s[i][j] -= 'a';
	for (int i = 0; i < n; i ++) for (int j = 0; j < n; j ++) rmh[i+j][s[i][j]] |= (1 << i);
    int ans = flag[s[0][0]] + dfs(0, 1);
    if (ans > 0) puts("FIRST");
    else if (ans < 0) puts("SECOND");
    else puts("DRAW");
	return 0;
}