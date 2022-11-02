#include <bits/stdc++.h>
using namespace std;

#define N 200200

int n, a[N], b[N], id[N];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) scanf("%d", &a[i]), id[a[i]] = i;
    for (int i = 1; i <= n; i ++) scanf("%d", &b[i]);
    int rlt = 0, mn = n + 1;
    for (int i = n; i; i --) {
        if (mn < id[b[i]]) rlt ++;
        mn = min(mn, id[b[i]]);
    }
    printf("%d\n", rlt);
}