#include <bits/stdc++.h>
using namespace std;

int n;

#define N 1111111
int res[N], rev[N];

int main() {
    int q, x, type;
    scanf("%d%d", &n, &q);
    int s = 1;
    int ss = 2;
    for(int i = 0; i < q; i ++) {
        scanf("%d", &type);
        if(type == 1) {
            scanf("%d", &x);
            s = (s + x + 2 * n - 1) % n + 1;
            ss = (ss + x + 2 * n - 1) % n + 1;
        } else {
            if(s & 1) s ++; else s --;
            if(ss & 1) ss ++; else ss --;
        }
    }
    res[1] = s; res[2] = ss;
    for(int i = 3; i <= n; i ++) {
        res[i] = res[i - 2] + 2;
        if(res[i] > n) res[i] -= n;
    }
    for(int i = 1; i <= n; i ++) rev[res[i]] = i;
    for(int i = 1; i <= n; i ++) printf("%d ", rev[i]);
    return 0;
}