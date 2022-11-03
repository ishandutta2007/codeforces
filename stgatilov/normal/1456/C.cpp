//#pragma comment(linker, "/STACK:20000000")
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>

#include <algorithm>
#include <set>
#include <functional>
using namespace std;

typedef long long int64;
#ifdef HOME
	#define Ef(...) fprintf(stderr, __VA_ARGS__)
#else
	#define Ef(...) ((void)0)
#endif

#define MAXN (500<<10)

int n, k;
int arr[MAXN];

int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    sort(arr, arr+n, greater<int>());

    k++;
    multiset<int64> groups;
    for (int i = 0; i < k; i++) groups.insert(0);

    int64 ans = 0;
    for (int i = 0; i < n; i++) {
        int x = arr[i];
        auto iter = groups.end(); iter--;
        int64 val = *iter;
        groups.erase(iter);
        ans += val;
        val += x;
        groups.insert(val);
    }

    printf("%lld\n", ans);

	return 0;
}