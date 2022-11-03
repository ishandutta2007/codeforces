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
int cnt[MAXN], pos[MAXN];
char ans[MAXN];

int mmin(int a, int b) { return a < b ? a : b; }

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

/*        for (int t = 0; t < n; t++) {
            memset(cnt, 0, sizeof(cnt));
            for (int i = 0; i < n-t; i++)
                cnt[arr[i]]++;

            int bad = 0;
            for (int i = 0; i < n-t; i++)
                if (cnt[i] != 1)
                    bad = 1;

            printf("%d : ", !bad);
            for (int i = 0; i < n-t; i++)
                printf("%d ", arr[i]);
            printf("\n");
            
            for (int i = 0; i < n-t-1; i++)
                arr[i] = mmin(arr[i], arr[i+1]);
        }*/

        memset(cnt, 0, (n+1) * sizeof(cnt[0]));
        memset(ans, '0', (n+1) * sizeof(ans[0]));
        ans[n] = 0;

        for (int i = 0; i < n; i++) {
           cnt[arr[i]]++;
           pos[arr[i]] = i;
        }
        int isperm = 1;
        for (int i = 0; i < n; i++)
            if (cnt[i] != 1)
                isperm = 0;
        if (isperm)
            ans[0] = '1';

        int l = 0, r = n-1;
        for (int t = 0; t < n; t++) {
            if (cnt[t] == 0)
                break;
            ans[n-1-t] = '1';
            if (cnt[t] != 1)
                break;
            if (pos[t] == l)
                l++;
            else if (pos[t] == r)
                r--;
            else
                break;
        }

        printf("%s\n", ans);
    }

	return 0;
}