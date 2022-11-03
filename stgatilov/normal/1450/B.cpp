//#pragma comment(linker, "/STACK:20000000")
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

#define MAXN 1024

int n, rad;
int px[MAXN], py[MAXN];

int mabs(int x) { return x < 0 ? -x : x; }

int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	

    int tests;
    scanf("%d", &tests);
    for (int tt = 0; tt < tests; tt++) {
        scanf("%d%d", &n, &rad);
        for (int i = 0; i < n; i++)
            scanf("%d%d", &px[i], &py[i]);

        int good = 0;
        for (int i = 0; i < n; i++) {
            int q = 0;
            for (int j = 0; j < n; j++) {
                int dst = mabs(px[i] - px[j]) + mabs(py[i] - py[j]);
                q += (dst <= rad);
            }
            if (q == n)
                good = 1;
        }

        printf("%d\n", (good ? 1 : -1));
    }

	return 0;
}