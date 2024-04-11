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

int umin(int a, int b) { return a < b ? a : b; }
int umax(int a, int b) { return a > b ? a : b; }

int n, m;
int arr[1<<20];

int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	

    int tests;
    scanf("%d", &tests);
    for (int tt = 0; tt < tests; tt++) {
        scanf("%d%d", &n, &m);

        if (m < n)
            printf("No\n");
        else if (m == n) {
            printf("Yes\n");
            for (int i = 0; i < n; i++) printf(" 1");
            printf("\n");
        }
        else if (n % 2 == 0 && m % 2 == 0) {
            printf("Yes\n");
            int t = (m - n + 2) / 2;
            printf("%d %d", t, t);
            for (int i = 0; i < n - 2; i++) printf(" 1");
            printf("\n");
        }
        else if (n % 2 == 0 && m % 2 != 0) {
            printf("No\n");
        }
        else {
            assert(n % 2 == 1);
            printf("Yes\n");
            int t = (m - n + 1);
            printf("%d", t);
            for (int i = 0; i < n - 1; i++) printf(" 1");
            printf("\n");
        }
    }

	return 0;
}