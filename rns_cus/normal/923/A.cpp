#include <bits/stdc++.h>
using namespace std;

#define N 1000100

int p[N];

int main() {
    for (int i = 2; i < N; i ++) {
        int j;
        for (j = 2; j * j <= i; j ++)
            if (i % j == 0) break;
        if (j * j > i) p[i] = i;
        else p[i] = max(j, p[i/j]);
    }
    int x;
    scanf("%d", &x);
    int rlt = x;
    for (int i = x; i > x - p[x]; i --) {
        if (p[i] < i) rlt = min(rlt, i - p[i] + 1);
    }
    printf("%d\n", rlt);

    return 0;
}