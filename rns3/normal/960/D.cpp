#include <bits/stdc++.h>

using namespace std;



const int K = 61;

const long long MOD = 1ll << 59;



long long a[K];



long long x, d;



int level(long long x) {

	long long g = 1;

	int rlt = 0;

	while (g <= x) g <<= 1, rlt ++;

	return rlt - 1;

}



long long mod[K];



void prep() {

	mod[0] = 1;

	for (int i = 1; i < K; i ++) mod[i] = mod[i-1] * 2;

}



long long myfind(int k, long long y) {

	return mod[k] + ((a[k] + y) % mod[k]);

}



int main() {

	//freopen("r.in", "r", stdin);

	prep();

	int q, type;

	scanf("%d", &q);

	while (q --) {

		scanf("%d", &type);

		if (type < 3) {

			scanf("%I64d %I64d", &x, &d);

			int k = level(x);

			if (type == 1) a[k] = ((a[k] - d) % mod[k] + mod[k]) % mod[k];

			else {

				for (int h = k; h < K; h ++) {

					a[h] = ((a[h] - d) % mod[h] + mod[h]) % mod[h];

					d = d * 2 % MOD;

				}

			}

		}

		else {

			scanf("%I64d", &x);

			int k = level(x);

			long long y = (x - a[k]) % mod[k];

			while (k >= 0) {

				printf("%I64d ", myfind(k, y));

				k --;

				y >>= 1;

			}

			puts("");

		}



	}





	return 0;

}