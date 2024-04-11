#include <bits/stdc++.h>

using namespace std;



#define N 20202

#define K 111



int n, m, p;

int a[N], s[N];



int f[N][K];

int last[K];



const int INF = 1e9;



int main() {

	scanf("%d %d %d", &n, &m, &p);

	for (int i = 1; i <= n; i ++) scanf("%d", &a[i]), a[i] %= p, s[i] = (s[i-1] + a[i]) % p;



	memset(last, -1, sizeof last);



	for (int i = 0; i <= n; i ++) for (int k = 0; k <= m; k ++) f[i][k] = -INF;

	f[n][0] = 0;

	last[s[n]] = n;

	for (int i = 0; i < n; i ++) f[i][1] = (s[n] + p - s[i]) % p;



	for (int i = n - 1; i >= 0; i --) {

		for (int k = 0; k < m; k ++) {

			for (int d = 0; d < p; d ++) {

				int r = (d + s[i]) % p;

				if (last[r] == -1) continue;

				f[i][k+1] = max(f[i][k+1], f[last[r]][k] + d);

			}

		}

		last[s[i]] = i;

	}

	printf("%d\n", f[0][m]);





	return 0;

}