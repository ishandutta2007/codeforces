#include <bits/stdc++.h>
using namespace std;

#define K 22
#define N 1000005

int n;
int a[(1<<K)+5], b[N];

int main() {
    scanf("%d", &n);
    memset(a, -1, sizeof a);
    for (int i = 0; i < n; i ++) {
        int x;
        scanf("%d", &x);
        a[x] = x;
        b[i] = x;
    }
    for (int i = 0; i < K; i ++) {
        for (int j = 0; j < (1 << K); j ++)  {
            if (j & (1 << i)) {
                if (a[j^(1<<i)] != -1) a[j] = a[j^(1<<i)];
            }
        }
    }
    for (int i = 0; i < n; i ++) {
        printf("%d ", a[b[i]^((1<<K)-1)]);
    }
}