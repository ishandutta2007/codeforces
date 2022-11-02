#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>

#define N 1000100

using namespace std;

typedef __int64 LL;

LL sto[N];
int cnt;

bool fl[N];
int p[N], cp;
LL P[N];
int CP;

LL S[N];

bool isprime(LL a) {
	for (int i = 1; i <= cp && (LL)p[i] * p[i] <= a; i ++) if (a % p[i] == 0) return 0;
	return 1;
}

LL f[2][N];

vector <int> V[N];

main() {
	for (int i = 2; i * i < N; i ++) if (!fl[i]) {
		for (int j = i; i * j < N; j ++) fl[i * j] = 1;
	}
	for (int i = 2; i < N; i ++) if (!fl[i]) p[++ cp] = i;
	LL n;// = 7420738134810LL;
//	freopen("D.in", "r", stdin);
	scanf("%I64d", &n);
	LL lim = sqrt(n);
//	freopen("D.out", "w", stdout);
	for (int i = 1; i <= cp && p[i] <= n; i ++) {
		LL cur = p[i];
		bool bf = 0;
		while (cur + 1 <= n) {
			if (n % (cur + 1) == 0) {
				bf = 1;
				break;
			}
			if (cur > lim) break;
			cur *= cur;
		}
		if (bf) P[++ CP] = p[i];
	}
	for (int i = 1; (LL)i * i <= n; i ++) {
		LL q = n / i;
		if (n == q * i) {
			sto[++ cnt] = i;
			if (i < q) sto[++ cnt] = q;
		}
	}
	sort(sto + 1, sto + cnt + 1);
	int cont = 0;
	for (int i = 1; i <= cnt; i ++) {
		LL tmp = sto[i] - 1;
		if (tmp <= 1) continue;

		if (tmp >= N && isprime(tmp)) {
			P[++ CP] = tmp;
			S[++ cont] = sto[i];
			V[CP].push_back(cont);
		} else if (tmp < N && !fl[tmp]) {
			S[++ cont] = sto[i];
			int pos = lower_bound(P + 1, P + CP + 1, tmp) - P;
			V[pos].push_back(cont);
		} else {
			int j;
			LL cur;
			bool bf = 0;
			for (j = 1; j <= CP && (LL)P[j] * P[j] <= tmp; j ++) {
				cur = tmp;
				while (cur % P[j] == 0) cur /= P[j];
				if (cur == 1) {
					bf = 1;
					break;
				}
			}
			if (bf) S[++ cont] = sto[i], V[j].push_back(cont);
		}
	}
/*	for (int i = 1; i <= CP; i ++) if ((int)V[i].size() > 0) {
		printf("%I64d\n", P[i]);
		for (int j = 0; j < V[i].size(); j ++) printf("	%I64d\n", S[V[i][j]]);
	}*/
	f[0][1] = 1;
	bool bf = 0;
	for (int i = 1; i <= CP; i ++) if ((int)V[i].size() > 0) {
		for (int j = 1; j <= cnt; j ++) {
			f[bf ^ 1][j] = f[bf][j];
			for (int k = 0; k < V[i].size(); k ++) {
				LL val = S[V[i][k]];
				if (sto[j] % val == 0) {
					LL tmp = sto[j] / val;
					int pos = lower_bound(sto + 1, sto + cnt + 1, tmp) - sto;
					f[bf ^ 1][j] += f[bf][pos];
				}
			}
		}
		bf ^= 1;
	}
	printf("%I64d\n", f[bf][cnt]);
}