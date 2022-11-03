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

int imin(int a, int b) { return a < b ? a : b; }
int imax(int a, int b) { return a > b ? a : b; }

int tests;

int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	

    scanf("%d", &tests);

    for (int tt = 0; tt < tests; tt++) {
        int n, m;
        scanf("%d%d", &n, &m);
        char full[256], sub[256];
        scanf("%s%s", full, sub);

        for (int i = 0; i < n; i++)
            full[i] -= '0';
        for (int i = 0; i < m; i++)
            sub[i] -= '0';

        int res[256][2];
        memset(res, 0, sizeof(res));

        res[1][full[0]] = 1;
        for (int k = 1; k < n; k++) {
            int next = full[k];
            for (int b = 0; b < 2; b++) if (res[k][b]) {
                res[k+1][imin(b, next)] = 1;
                res[k+1][imax(b, next)] = 1;
            }
        }

        int d = n - m;

        int ok = res[d + 1][sub[0]];
        for (int i = 1; i < m; i++)
            ok &= (sub[i] == full[d + i]);

        printf("%s\n", (ok ? "YES" : "NO"));
    }

	return 0;
}