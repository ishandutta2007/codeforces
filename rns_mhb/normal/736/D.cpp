#include <bits/stdc++.h>
using namespace std;

#define N 2005
#define Q 500005

int n, q;
int a[Q], b[Q];
bitset<N> A[N], B[N];

void calc_inv() {
    for (int i = 1; i <= n; i ++) {
        int j = i;
        while (!A[j][i]) j ++;
        swap(A[j], A[i]), swap(B[j], B[i]);
        for (int j = 1; j <= n; j ++) {
            if (j == i || !A[j][i]) continue;
            A[j] ^= A[i], B[j] ^= B[i];
        }
    }
}

int main() {
    scanf("%d %d", &n, &q);
    for (int i = 0; i < q; i ++) {
        scanf("%d %d", &a[i], &b[i]);
        A[a[i]][b[i]] = 1;
    }
    for (int i = 1; i <= n; i ++) B[i][i] = 1;
    calc_inv();
    for (int i = 0; i < q; i ++) {
        if (!B[b[i]][a[i]]) puts("YES");
        else puts("NO");
    }
}