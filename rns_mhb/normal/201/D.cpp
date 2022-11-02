#include <bits/stdc++.h>
using namespace std;

template<class T> chkmax(T &a, T b) {if (a < b) a = b;}

int n;
char s[15][20];

const int inf = 1e9;

int dp[1<<15][500];
char t[20];
int prv[500050][20];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i ++) scanf("%s", s[i]);
	int m;
	int val = n * (n - 1) / 2 + 1, id = 0;
	scanf("%d", &m);
	for (int i = 1; i <= m; i ++) {
		int k;
		scanf("%d", &k);
		int last[20] = {};
		for (int j = 0; j < n; j ++) last[j] = -1;
		int tot = 0;
		while (k --) {
			scanf("%s", t);
			int x = 0;
			while (x < n && strcmp(t, s[x])) x ++;
			if (x == n) continue;
			for (int j = 0; j < n; j ++) prv[tot][j] = last[j];
			last[x] = tot;
			tot ++;
		}
		for (int j = 0; j < n; j ++) prv[tot][j] = last[j];
		dp[0][0] = tot;
		int up = n * (n - 1) / 2;
		for (int j = 1; j <= up; j ++) dp[0][j] = -1;
		for (int k = 1; k < (1<<n); k ++) {
			for (int l = 0; l <= up; l ++) dp[k][l] = -1;
			for (int p = 0; p < n; p ++) if ((k>>p)&1) {
				for (int l = 0; l <= up; l ++) if (dp[k^(1<<p)][l] >= 0) {
					chkmax(dp[k][l+__builtin_popcount(((1<<(p+1))-1)&k)-1], prv[dp[k^(1<<p)][l]][p]);
				}
			}
		}
		int mn = 0;
		while (mn <= up && dp[(1<<n)-1][mn] < 0) mn ++;
		if (mn < val) {
			val = mn;
			id = i;
		}
	}
	if (!id) puts("Brand new problem!");
	else {
		cout<<id<<endl;
		putchar('['); putchar(':');
		val = n * (n - 1) / 2 + 1 - val;
		while (val --) {
			putchar('|');
		}
		 putchar(':');putchar(']');
	}
}