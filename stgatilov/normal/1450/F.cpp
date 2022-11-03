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

#define MAXN (1<<19)

int n;
int arr[MAXN];
int cnt[MAXN];

int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	

    int tests;
    scanf("%d", &tests);
    for (int tt = 0; tt < tests; tt++) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
            arr[i]--;
        }

        if (n == 1) {
            printf("0\n");
            continue;
        }

        memset(cnt, 0, (n+1) * sizeof(cnt[0]));

        int splits = 0;
        for (int i = 0; i+1 < n; i++) {
            if (arr[i] == arr[i+1]) {
                splits++;
                cnt[arr[i]]++;
                cnt[arr[i+1]]++;
            }
        }
        cnt[arr[0]]++;
        cnt[arr[n-1]]++;
        int ends = 2 * splits + 2;

        int mxCnt = 0;
        int worst = -1;
        for (int i = 0; i < n; i++)
            if (mxCnt < cnt[i]) {
                mxCnt = cnt[i];
                worst = i;
            }
        int rest = ends - mxCnt;

        int ans = splits;
        if (mxCnt - 2 > rest) {
            int adds = 0;
            for (int i = 0; i+1 < n; i++)
                if (arr[i] != arr[i+1])
                    if (arr[i] != worst && arr[i+1] != worst)
                        adds++;
            int need = (mxCnt - 2 - rest);
            need = (need + 1) / 2;
            if (need <= adds)
                ans += need;
            else
                ans = -1;
        }

        printf("%d\n", ans);
    }

	return 0;
}