//#pragma comment(linker, "/STACK:20000000")
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>

typedef long long int64;
#ifdef HOME
	#define Ef(...) fprintf(stderr, __VA_ARGS__)
#else
	#define Ef(...) ((void)0)
#endif

#define MAXN (100<<10)

int n, p, k;
int x, y;
char arr[MAXN];
int mod[MAXN*2];

int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    int tests;
    scanf("%d", &tests);

    for (int tt = 0; tt < tests; tt++) {
        scanf("%d%d%d", &n, &p, &k);
        p--;
        scanf("%s", arr);
        scanf("%d%d", &x, &y);

        for (int i = 2*n; i >= n; i--)
            mod[i] = 0;
        for (int i = n-1; i >= 0; i--)
            mod[i] = mod[i+k] + (arr[i] == '1' ? 0 : 1);

        int64 minCost = 1000000000000000000LL;
        for (int i = p; i < n; i++) {
            int64 cost = (int64)(mod[i]) * x + (int64)(i-p) * y;
            if (minCost > cost)
                minCost = cost;
        }
        printf("%lld\n", minCost);
    }

	return 0;
}