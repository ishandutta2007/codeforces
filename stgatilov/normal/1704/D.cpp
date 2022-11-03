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


int64 sums[1<<20];

int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	

    int tests;
    scanf("%d", &tests);
    for (int tt = 0; tt < tests; tt++) {
        int n, m;
        scanf("%d%d", &n, &m);

        for (int i = 0; i < n; i++) {
            int64 sum = 0;
            for (int j = 0; j < m; j++) {
                int64 x;
                scanf("%lld", &x);
                sum += j * x;
            }
            sums[i] = sum;
        }

        int64 correct;
        if (sums[0] == sums[1])
            correct = sums[0];
        else if (sums[0] == sums[2])
            correct = sums[0];
        else if (sums[1] == sums[2])
            correct = sums[1];
        else
            assert(0);

        int cnt = 0;
        for (int i = 0; i < n; i++)
            if (sums[i] != correct) {
                printf("%d %lld\n", i+1, sums[i] - correct);
                cnt++;
            }
        assert(cnt == 1);
    }

	return 0;
}