#include <bits/stdc++.h>

using namespace std;



const int K = 6;

const int L = 1 << K;



long double a[L][L], vic[L][K+1], dp[L][K+1];



double tmp[L][K+1];



int main() {

	//freopen("r.in", "r", stdin);

	int h;

	scanf("%d", &h);

	int n = 1 << h;

	for (int i = 0; i < n; i ++) for (int j = 0, x; j < n; j ++) {

		scanf("%d", &x);

		a[i][j] = x / 100.0;

	}

	for (int k = 0; k <= h; k ++) for (int i = 0; i < n; i ++) {

		if (k == 0) tmp[i][k] = 0.5;

		else {

			long double now = 0;

			int st = ((i >> (k - 1)) ^ 1) << (k - 1);

			int en = st + (1 << (k - 1));

			for (int j = st; j < en; j ++) {

				now += tmp[j][k-1] * a[i][j];

			}

			tmp[i][k] = now * tmp[i][k-1] / (0.25 * (1 << (k - 1)));

		}

	}

	for (int k = 1; k <= h; k ++) {

		for (int st = 0; st < n; st += (1 << k)) {

			int en = st + (1 << k);

			long double rlt = 0;

			for (int i = st; i < en; i ++) {

				long double now = 0;

				now = tmp[i][k];

				for (int g = k - 1; g; g --) {

					now += dp[((i>>g)^1)<<g][g];//if (k == 2) printf("(%d %.6lf %d)\n", i, now);

					now += tmp[i][g];//if (k == 2) printf("(%d %.6lf)\n", i, now);

				}

				rlt = max(rlt, now);//if (k == 2) printf("(%d %.6lf)\n", i, now);

			}

			dp[st][k] = rlt;

			//printf("(%d %d %.8lf)\n", st, k, rlt);

		}

	}

	printf("%.20lf\n", (double)dp[0][h]);



	return 0;

}