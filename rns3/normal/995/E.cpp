#include <bits/stdc++.h>

using namespace std;



const int MOD = 1e9 + 7;



int u, v, mod;



int expmod(int a, int b) {

	int rlt = 1;

	while (b) {

		if (b & 1) rlt = 1ll * a * rlt % mod;

		b >>= 1;

		a = 1ll * a * a % mod;

	}

	return rlt;

}



const int K = 90;



#define N 40505



int a[N], b[N];

int A[N], B[N];



int oper(int &now, int &seed) {

	int tmp = seed % 3;

	if (tmp == 0) now = (now + 1) % mod;

	else if (tmp == 1) now = (now + mod - 1) % mod;

	else now = expmod(now, mod - 2);

	seed = 917ll * seed % MOD;

}



int id[N], jd[N];



bool cmp_1(int i, int j) {

	return a[i] < a[j];

}



bool cmp_2(int i, int j) {

	return b[i] < b[j];

}



const int L = 200 - 2 * K;



int put[N], tmp[N];



int convert_1(int seed) {

	return (seed % 3) + 1;

}



int convert_2(int seed) {

	if (seed % 3 == 0) return 2;

	if (seed % 3 == 1) return 1;

	return 3;

}



int near(int x) {

	x = ((x % mod) + mod) % mod;

	if (x > mod / 2) x -= mod;

	return x;

}



bool check(int i, int j) {

	int d = near(a[i] - b[j]);

	if (abs(d) > L) return 0;

	int e = 0, f = 0;

	int seed = A[i];

	int uu = u;

	for (int step = 0; step < K; step ++) {

		put[++e] = convert_1(seed);

		oper(uu, seed);

	}

	seed = B[j];

	int vv = v;

	for (int step = 0; step < K; step ++) {

		tmp[++f] = convert_2(seed);

		oper(vv, seed);

	}

	while (d) {

		if (d > 0) {

			d --;

			put[++e] = 2;

		}

		else {

			d ++;

			put[++e] = 1;

		}

	}

	while (f) {

		put[++e] = tmp[f--];

	}

	printf("%d\n", e);

	for (int i = 1; i <= e; i ++) printf("%d ", put[i]);

	puts("");

	return 1;

}



int main() {

//	freopen("r.in", "r", stdin);

//	freopen("w.out", "w", stdout);

	scanf("%d %d %d", &u, &v, &mod);

	for (int i = 1; i < N; i ++) {

		int now = u;

		int seed = rand();

		A[i] = seed;

		for (int step = 0; step < K; step ++) {

			oper(now, seed);

		}

		a[i] = now;

		id[i] = i;

	}

	for (int i = 1; i < N; i ++) {

		int now = v;

		int seed = rand();

		B[i] = seed;

		for (int step = 0; step < K; step ++) {

			oper(now, seed);

		}

		b[i] = now;

		jd[i] = i;

	}

	sort(id + 1, id + N, cmp_1);

	sort(jd + 1, jd + N, cmp_2);



	int aa = 1, bb = 1;

	while (aa < N && bb < N) {

		if (check(id[aa], jd[bb])) return 0;

		while (aa < N && a[id[aa]] <= b[jd[bb]]) {

			if (check(id[aa], jd[bb])) return 0;

			aa ++;

		}

		if (aa < N && check(id[aa], jd[bb])) return 0;

		while (aa < N && a[id[aa]] >= b[jd[bb]]) {

			if (check(id[aa], jd[bb])) return 0;

			bb ++;

		}

	}



	return 0;

}