#include <bits/stdc++.h>

#define debug(x) cout << #x" = " << x;

#define st first
#define nd second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;

const int MAXN = 20, MAXM = 1 << MAXN;

double a[MAXN], ans[MAXN];
int loc[MAXN];
double b[MAXM];
int c[MAXM];

double C[MAXN + 1][MAXN + 1];
double D[MAXN + 1];

int main(){
	for (int i = 0; i <= MAXN; ++i){
		C[i][0] = C[i][i] = 1.0;
		for (int j = 1; j < i; ++j)
			C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
	}

	int n0, K;
	scanf("%d%d", &n0, &K);
	int n = 0;
	for (int i = 0; i < n0; ++i){
		scanf("%lf", &a[n]);
		if (a[n] > 0)
			loc[n++] = i;
	}
	memset(ans, 0, sizeof(ans));

	if (K == 1){
		for (int i = 0; i < n; ++i)
			ans[loc[i]] = a[i];
	}
	else if (K >= n){
		for (int i = 0; i < n; ++i)
			ans[loc[i]] = 1.0;
	}
	else{
		b[0] = 0.0;
		c[0] = 0;
		for (int i = 0; i < n; ++i){
			int j0 = 1 << i;
			for (int j = (1 << i + 1) - 1; j >= j0; --j){
				b[j] = b[j ^ j0] + a[i];
				c[j] = c[j ^ j0] + 1;
			}
		}

		for (int i = 1; i < K; ++i){
			D[i] = 0;
			for (int j = 0; K - 1 - i - j >= 0; ++j)
				if (j & 1)
					D[i] -= C[n - 1 - i][K - 1 - i - j];
				else
					D[i] += C[n - 1 - i][K - 1 - i - j];
//			printf("%d %.3f\n", i, D[i]);
		}

		double tot = 0;
		for (int i = 0; i < n; ++i){
			int mask0 = (1 << n) - 1 ^ 1 << i;
			double s = 0;
			for (int mask = mask0; mask > 0; mask = mask - 1 & mask0){
				if (c[mask] >= K)
					continue;
				if (K - c[mask] & 1)
					s += b[mask] / (1.0 - b[mask]) * D[c[mask]];//, printf("%d %.f\n", mask, D[c[mask]]);
				else
					s -= b[mask] / (1.0 - b[mask]) * D[c[mask]];//, printf("%d %.f\n", mask, -D[c[mask]]);
			}
			s += 1.0;
			s *= a[i];
			ans[loc[i]] = s;
//			printf("%.8f%c", s, "\n "[i + 1 < n]);
			tot += s;
		}
//		printf("%.3f\n", tot);
	}
	for (int i = 0; i < n0; ++i)
		printf("%.8f%c", ans[i], "\n "[i + 1 < n0]);
	return 0;
}