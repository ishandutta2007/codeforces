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

int n;
int arr[4<<10];
int answer;

int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	

    int tests;
    scanf("%d", &tests);
    for (int tt = 0; tt < tests; tt++) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &arr[i]);

        answer = arr[n-1] - arr[0];
        for (int i = 0; i < n-1; i++)
            answer = umax(answer, arr[n-1] - arr[i]);
        for (int i = 1; i < n; i++)
            answer = umax(answer, arr[i] - arr[0]);

        for (int r = 0; r < n; r++) {
            arr[n] = arr[0];
            for (int i = 0; i < n; i++)
                arr[i] = arr[i+1];
            answer = umax(answer, arr[n-1] - arr[0]);
        }

        printf("%d\n", answer);
    }

	return 0;
}