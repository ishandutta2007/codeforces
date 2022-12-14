#include <bits/stdc++.h>

using namespace std;



void fwt(int *a, int len) {

	for (int half = 1; half < len; half <<= 1) {

		for (int i = 0; i < len; i += half << 1) {

			for (int j = 0; j < half; j ++) {

				a[i+j+half] = (a[i+j+half] + a[i+j]);

			}

		}

	}

}



#define N 101010



char s[N], tmp[N];

char t[N];

int to[N];



const int K = 6;

const int L = 1 << K;



int cnt[K];

int a[L], b[L], c[L];



bool dfs(int tot, int s, int k) {

	if (k == K) return tot <= b[s];

	return dfs(tot, s, k + 1) && dfs(tot + cnt[k], s | (1 << k), k + 1);

}



void get_b() {

	int tot = 0;

	for (int i = 0; i < L; i ++) c[i] = a[i], tot += a[i];

	fwt(c, L);

	for (int i = 0; i < L; i ++) b[i] = tot - c[(L-1)^i];

}



int main() {

	//freopen("r.in", "r", stdin);

	scanf("%s", s + 1);

	int n = strlen(s + 1), m;

	scanf("%d", &m);

	for (int i = 1; i <= n; i ++) to[i] = L - 1;

	for (int i = 1, x, y, len; i <= m; i ++) {

		scanf("%d %s", &x, tmp);

		y = 0;

		len = strlen(tmp);

		for (int j = 0; j < len; j ++) y |= 1 << (tmp[j] - 'a');

		to[x] = y;

	}

	for (int i = 1; i <= n; i ++) cnt[s[i]-'a'] ++;

	for (int i = 1; i <= n; i ++) a[to[i]] ++;

	get_b();

	if (!dfs(0, 0, 0)) {

		puts("Impossible");

		return 0;

	}

	for (int i = 1; i <= n; i ++) {

		a[to[i]] --;

		get_b();

		for (int k = 0; k < K; k ++) if (cnt[k] && ((to[i] >> k) & 1)) {

			cnt[k] --;

			if (dfs(0, 0, 0)) {

				printf("%c", k + 'a');

				break;

			}

			cnt[k] ++;

		}

	}







	return 0;

}