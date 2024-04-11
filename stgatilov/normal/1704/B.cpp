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

int64 imin(int64 a, int64 b) { return a < b ? a : b; }
int64 imax(int64 a, int64 b) { return a > b ? a : b; }

int arr[256<<10];

int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	

    int tests;
    scanf("%d", &tests);
    for (int tt = 0; tt < tests; tt++) {
        int n, x;
        scanf("%d%d", &n, &x);
        for (int i = 0; i < n; i++)
            scanf("%d", &arr[i]);

        int64 vmin = arr[0];
        int64 vmax = arr[0];
        int ans = 0;
        for (int i = 1; i < n; i++) {
            int64 nmin = imin(vmin, arr[i]);
            int64 nmax = imax(vmax, arr[i]);
            if (nmax - nmin > 2*x) {
                ans++;
                vmin = vmax = arr[i];
            }
            else {
                vmin = nmin;
                vmax = nmax;
            }
        }

        printf("%d\n", ans);
    }

	return 0;
}