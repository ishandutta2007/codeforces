#include <bits/stdc++.h>
using namespace std;

#define N 400400
#define K 20    

int n, Q, fa[N][K], w[N];
long long sum[N][K];

int find(int p, int q) {
    for (int k = K - 1; k >= 0; k --) {
        if (fa[p][k] && w[fa[p][k]] < q) p = fa[p][k];
    }
    return p;
}

int query(int p, long long x) {
    int rlt = 0;
    for (int k = K - 1; k >= 0; k --) {
        if (fa[p][k] && sum[p][k] <= x) x -= sum[p][k], p = fa[p][k], rlt += 1 << k;
    }
    if (sum[p][0] <= x) rlt ++;
    return rlt;
}

int main() {
    scanf("%d", &Q);
    long long last = 0;
    w[++n] = 0;
    while (Q --) {
        int ty;
        long long p, q;
        scanf("%d %I64d %I64d", &ty, &p, &q);
        p ^= last, q ^= last;
        if (ty == 1) {
            w[++n] = q;
            if (w[p] >= q) {
                long long cur = q;
                for (int k = 0; k < K; k ++) fa[n][k] = p, sum[n][k] = cur, cur += sum[p][k], p = fa[p][k];
            }
            else {
                p = find(p, q);
                for (int k = 0; k < K; k ++) fa[n][k] = fa[p][k], sum[n][k] = sum[p][k] - w[p] + q;
            }
        }
        else printf("%d\n", last = query(p, q));
    }

    return 0;
}