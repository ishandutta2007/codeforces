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

int n;
char arr[1024];

int cmp(const void *a, const void *b) {
    char ac = *(char*)a;
    char bc = *(char*)b;
    return ac == bc ? 0 : (ac < bc ? -1 : 1);
}

int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	

    int tests;
    scanf("%d", &tests);
    for (int tt = 0; tt < tests; tt++) {
        scanf("%d", &n);
        scanf("%s", arr);
        qsort(arr, n, sizeof(arr[0]), cmp);
        printf("%s\n", arr);
    }

	return 0;
}