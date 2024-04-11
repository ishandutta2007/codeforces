#pragma comment(linker, "/STACK:60000000")
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>

typedef long long int64;
#ifdef HOME
	#define Ef(...) fprintf(stderr, __VA_ARGS__)
#else
	#define Ef(...) ((void)0)
#endif

#define MOD 998244353

void add(int *a, int b) {
    *a += b;
    if (*a >= MOD)
        *a -= MOD;
}
int mult(int a, int b) {
    return ((int64)a) * b % MOD;
}
int power(int a, int b) {
    int res = 1;
    int x = a;
    for (; b; b >>= 1) {
        if (b & 1) res = mult(res, x);
        x = mult(x, x);
    }
    return res;
}
int inv(int a) {
     return power(a, MOD-2);
}

#define MAXN (1<<20)

int n;
int fact[MAXN], fact2[MAXN];

int comb(int n, int k) {
    assert(k >= 0 && k <= n);
    return mult(fact[n], inv(mult(fact[k], fact[n-k])));
}

int num12[MAXN];
int sres[MAXN];


int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	

    fact[0] = 1;
    for (int i = 1; i < MAXN; i++)
        fact[i] = mult(fact[i-1], i);

    fact2[0] = 1;
    fact2[1] = 1;
    for (int i = 2; i < MAXN; i++)
        fact2[i] = mult(fact2[i-2], i);

    sres[0] = 1;
    for (int k = 1; k < MAXN; k++) {
        if (k >= 1)
            add(&sres[k], sres[k-1]);
        if (k >= 2)
            add(&sres[k], mult(k-1, sres[k-2]));
    }

    int tests;
    scanf("%d", &tests);
    for (int tt = 0; tt < tests; tt++) {
        scanf("%d", &n);

        int answer = 0;
        for (int t = 0; t <= n/4; t++) {
            int coeff = comb(n - 2*t, 2*t);
            coeff = mult(coeff, power(2, t));
            coeff = mult(coeff, t == 0 ? 1 : fact2[2*t-1]);
            int rem = n - 4*t;

            int tres = sres[rem];
/*            int tres = 0;
            for (int q = 0; q <= rem/2; q++) {
                int qrt = comb(rem, 2*q);
                qrt = mult(qrt, q == 0 ? 1 : fact2[2*q-1]);
                Ef("Q %d: qrt %d\n", q, qrt);
                add(&tres, qrt);
            }*/

            Ef("t = %d: coeff = %d, tres = %d\n", t, coeff, tres);
            add(&answer, mult(coeff, tres));
        }

        printf("%d\n", answer);
    }

	return 0;
}