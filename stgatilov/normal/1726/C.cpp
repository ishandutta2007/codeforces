#pragma comment(linker, "/STACK:60000000")
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
char str[2<<20];

int par[2<<20], has[2<<20];
int Head(int x) {
    if (par[x] == x)
        return x;
    else
        return par[x] = Head(par[x]);
}
void Join(int x, int y) {
    x = Head(x);
    y = Head(y);
    par[x] = y;
}

int pos;
void ParseExpr() {
    int prev = -1;

    while (str[pos] == '(') {
        int a = pos++;
        ParseExpr();
        assert(str[pos] == ')');
        int b = pos++;

        Ef("%d %d\n", a, b);
        Join(a, b);

        if (prev >= 0) {
            Ef("%d %d\n", prev, a);
            Join(prev, a);
        }
        prev = a;
    }
}

int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	

    int tests;
    scanf("%d", &tests);
    for (int tt = 0; tt < tests; tt++) {
        scanf("%d%s", &n, str);
        assert(str[2*n] == 0);

        for (int i = 0; i < 2*n; i++)
            par[i] = i;

        pos = 0;
        ParseExpr();
        assert(pos == 2*n);

        memset(has, 0, 2*n * sizeof(has[0]));
        for (int i = 0; i < 2*n; i++)
            has[Head(i)] = 1;

        int answer = 0;
        for (int i = 0; i < 2*n; i++)
            answer += has[i];

        printf("%d\n", answer);
    }

	return 0;
}