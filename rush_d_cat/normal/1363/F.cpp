#include <bits/stdc++.h>
using namespace std;
const int N = 2002;
int T, n, a[N];
char s[N], t[N];

bool chk() {
	char ss[N], tt[N];
	for (int i = 1; i <= n; i ++) ss[i] = s[i];
	for (int i = 1; i <= n; i ++) tt[i] = t[i];
	sort(ss + 1, ss + 1 + n);
	sort(tt + 1, tt + 1 + n);
	for (int i = 1; i <= n; i ++) if (ss[i] != tt[i]) return 0;
	return 1;
}

int suf_s[N][30]; // s[x] ~ s[n] char c
int suf_t[N][30]; // t[x] ~ t[n] char c
int pre_s[N][30]; // s[1] ~ s[x] the last pos of c
int dp[N][N]; 
const int inf = 1e9;
void init() {
	for (int i = 0; i <= n + 1; i ++) for (int j = 0; j < 26; j ++)
		suf_s[i][j] = suf_t[i][j] = pre_s[i][j] = 0;
	
	for (int i = n; i >= 1; i --) {
		for (int j = 0; j < 26; j ++) suf_t[i][j] = suf_t[i+1][j], suf_s[i][j] = suf_s[i+1][j]; 
		suf_s[i][ s[i] - 'a' ] ++;
		suf_t[i][ t[i] - 'a' ] ++;
	}

	for (int i = 1; i <= n; i ++) {
		for (int j = 0; j < 26; j ++) pre_s[i][j] = pre_s[i-1][j];
		pre_s[i][ s[i] - 'a' ] = i;
	}

	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= n; j ++) {
			dp[i][j] = inf;
		}
	}
	for (int i = 1; i <= n; i ++) {
		if (s[i] == t[n]) dp[n][i] = 0;
	}
}

int main() {	
	scanf("%d", &T);
	while (T --) {
		scanf("%d", &n);
		scanf("%s%s",s+1,t+1);
		if (chk() == false) {
			printf("-1\n"); continue;
		}
		init();
		for (int i = n; i >= 2; i --) {
			for (int j = 1; j <= n; j ++) {
				int id = t[i-1] - 'a';
				int ct = suf_t[i][id];
				int cs = suf_s[j][id];
				if (ct < cs) {
					dp[i-1][j] = min(dp[i-1][j], dp[i][j] + 1);
				}
				if (pre_s[j-1][id])
				dp[i-1][ pre_s[j-1][id] ] = min(dp[i-1][ pre_s[j-1][id] ], dp[i][j]);
			}
		}
		int ans = inf;
		for (int i = 1; i <= n; i ++) ans = min(ans, dp[1][i]);
		printf("%d\n", ans);
	}
}