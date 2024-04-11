#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 300000 + 10;
int n, a[N];

int dp[N], mn[2][N];  
int f[2][N], id[2];

int main() {
	while (1) {
			
		scanf("%d", &n);
		for (int i = 1; i <= n; i ++) 
			scanf("%d", &a[i]);
		
		/*
		n = rand() %6;
		for (int i = 1; i <= n; i ++)
			a[i] = rand() % 10 + 1;

		int g[N] = {0};
		printf("!\n");
		for (int i = 2; i <= n; i ++) {
			g[i] = g[i-1] + 1;
			int mn = 1e9, mx = -1e9;
			for (int j = i - 1; j >= 2; j --) {
				mn = min(mn, a[j]);
				mx = max(mx, a[j]);
				if (max(a[j-1], a[i]) < mn) g[i] = min(g[i], g[j-1] + 1);
				if (min(a[j-1], a[i]) > mx) g[i] = min(g[i], g[j-1] + 1);
			}
		}

		printf("#\n");
		printf("%d\n", g[n]);
		*/
		id[0] = id[1] = 0;
		mn[0][0] = mn[1][0] = 1e9;
		for (int i = 1; i <= n; i ++) {
			//printf("i = %d\n", i);
			int m0 = 1e9, m1 = 1e9; 
			bool flag = 0;
			while (id[0] >= 1 && a[i] <= a[f[0][id[0]]]) {
				if (a[i] == a[f[0][id[0]]]) flag = 1;
				m0 = min(m0, dp[ f[0][id[0]] ]);
				-- id[0];
			}

			if (id[0] && ! flag) {
				//if (i == 4) printf("! %d %d\n", f[0][id[0]], dp[ f[0][id[0]] ]);
				m0 = min(m0, dp[f[0][id[0]]]);
			}
			if (i == 4) {
				//printf("!!! %d\n", m0);
			}
			flag = 0;
			while (id[1] >= 1 && a[i] >= a[f[1][id[1]]]) {

				if (a[i] == a[f[1][id[1]]]) flag = 1;
				m1 = min(m1, dp[ f[1][id[1]] ]);
				-- id[1];
			}
			if (id[1] && flag == 0) m1 = min(m1, dp[f[1][id[1]]]);
			dp[i] = 1e9;
			dp[i] = min(dp[i-1] + 1, dp[i]);
			if (a[i-1] > a[i]) {
				dp[i] = min(dp[i], m0 + 1);
			}
			if (a[i-1] < a[i]) {
				dp[i] = min(dp[i], m1 + 1);
			}
			if (i == 1) dp[i] = 0;
			//printf("dp[%d] = %d\n", i, dp[i]);
			//printf("##\n");
			f[0][++id[0]] = i;
			f[1][++id[1]] = i;
			//printf("# %d %d\n", id[0], id[1]);
		}
		//printf("out\n");
		printf("%d\n", dp[n]);
		/*
		if (dp[n] != g[n]) {
			printf("%d\n", n);
			for (int i = 1; i <= n; i ++) {
				printf("%d ", a[i]);
			}
			printf("\n");
			printf("# %d %d\n", g[n], dp[n]);
			return 0;
		}
		*/
		return 0;
	}

}