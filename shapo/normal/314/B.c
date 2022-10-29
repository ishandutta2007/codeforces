#include <stdio.h>
#include <string.h>

#define maxlen 105
#define alph 26
#define maxp 30
#define maxn 10002014

typedef long long ll;

char a[maxlen], c[maxlen];
int len_a, len_c, b, d;
int next[maxlen][alph];
int to[maxlen];
int used[maxlen];
int f[maxn], cnt, p;
ll sum[maxn];
ll pos[maxlen][maxp];
ll maxsum;

int main() {
	int i, j, cur;
	scanf("%d%d %s %s", &b, &d, a, c);
	len_a = strlen(a), len_c = strlen(c);
	for (i = 0; i < len_a; ++i)
		for (j = 0; j < alph; ++j) {
			cur = 0;
			while (cur != len_a && a[(i + cur) % len_a] != j + 'a') ++cur;
			if (cur == len_a) next[i][j] = -1;
			else next[i][j] = cur;
		}
	for (i = 0; i < len_a; ++i) {
		cur = i;
		for (j = 0; j < len_c && cur != -1; ++j) {
			if (next[cur % len_a][c[j] - 'a'] != -1)
				cur += next[cur % len_a][c[j] - 'a'] + 1;
			else
				cur = -1;
		}
		to[i] = (cur == -1) ? -1 : cur - i;
	}
	if (to[0] == -1) {
		printf("0\n");
		return 0;
	}
	cur = 0;
	memset(used, 0, len_a * sizeof(used[0]));
	for (i = 0; i < d + 2 * len_a; ++i) {
		f[i] = cur;
		sum[i] = ((i == 0) ? 0 : sum[i - 1]) + to[cur];
		used[cur] = 1;
		cur = (cur + to[cur]) % len_a;
	}
	for (i = 0; i < len_a; ++i) pos[i][0] = -1LL;
	memset(used, 0, len_a * sizeof(used[0]));
	for (i = 0; i < len_a * 2; ++i) {
		if (!used[f[i]]) {
			used[f[i]] = 1;
			pos[f[i]][0] = sum[i + d - 1] - ((i == 0) ? 0LL : sum[i - 1]);
		}
	}
	for (i = 1; i < maxp; ++i)
		for (j = 0; j < len_a; ++j)
			if (used[j]) {
				pos[j][i] = pos[j][i - 1] + pos[(j + pos[j][i - 1]) % len_a][i - 1];
			}
	maxsum = (ll)(len_a) * b;
	cur = 0;
	for (i = maxp - 1; i >= 0; --i) {
		if (maxsum >= pos[cur][i]) {
			maxsum -= pos[cur][i];
			p += (1 << i);
			cur = (cur + pos[cur][i]) % len_a;
		}
	}
	printf("%d\n", p);
	return 0;
}