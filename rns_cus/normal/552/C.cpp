#include <cstdio>

typedef long long LL;

LL w[100];

int cnt;

bool can(LL m) {
    if(m == 1) return 1;
    w[0] = 1;
    int n = 1;
    while(1) {
        w[n] = w[n-1] * w[1];
        if(w[n] >= m) break;
        n ++;
    }
    LL tot = 0;
    if(w[n] == m) return 1;
    for(int i = 0; i < n; i ++) tot += w[i];
    if(tot < m) {
        m = w[n] - m;
        if(tot < m) return 0;
        if(tot == m) return 1;
        return can(m);
    }
    if(tot == m) return 1;
    m -= w[n-1];
    return can(m);
}

int main() {
    LL m;
    scanf("%I64d%I64d", &w[1], &m);
    if(can(m)) puts("YES"); else puts("NO");
    return 0;
}