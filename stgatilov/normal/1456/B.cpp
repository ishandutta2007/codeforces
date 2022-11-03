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

#define MAXN (100<<10)

int n;
int arr[MAXN];

int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    for (int i = 0; i+2 < n; i++) {
        int x = arr[i], y = arr[i+1], z = arr[i+2];
        if (x > (y ^ z)) {
            printf("1\n");
            return 0;
        }
    }
    assert(n <= 100);

    int ans = INT_MAX;
    for (int l = 0; l <= n; l++)
        for (int m = l+1; m <= n; m++)
            for (int r = m+1; r <= n; r++) {
                int a = 0, b = 0;
                for (int i = l; i < m; i++) a ^= arr[i];
                for (int i = m; i < r; i++) b ^= arr[i];
                int k = (r-m-1) + (m-l-1);
                if (a > b && ans > k)
                    ans = k;
            }

    if (ans == INT_MAX)
        ans = -1;
    printf("%d\n", ans);

	return 0;
}