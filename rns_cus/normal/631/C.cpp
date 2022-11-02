#include <bits/stdc++.h>

using namespace std;

#define N 200100

int n, m, cnt;
int a[N], t[N], r[N], b[N];

int main() {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i ++) scanf("%d", a + i), b[i] = a[i];
    for(int i = 1; i <= m; i ++) {
        int tt, rr;
        scanf("%d%d", &tt, &rr);
        r[++ cnt] = rr; t[cnt] = tt;
        while(cnt > 1) {
            if(r[cnt - 1] <= rr) {
                r[cnt - 1] = rr;
                t[cnt - 1] = tt;
                cnt --;
            } else {
                break;
            }
        }
    }
    sort(a + 1, a + r[1] + 1);
    int L = 1, R = r[1];
    r[++ cnt] = 0;
    for(int i = 2; i <= cnt; i ++) {
        if(t[i-1] == 1) {
            for(int j = r[i] + 1; j <= r[i-1]; j ++) b[j] = a[R - r[i-1] + j];
            R -= r[i-1] - r[i];
        } else {
            for(int j = r[i] + 1; j <= r[i-1]; j ++) b[j] = a[L + r[i-1] - j];
            L += r[i-1] - r[i];
        }
    }
    for(int i = 1; i <= n; i ++) {
        if(i > 1) printf(" ");
        printf("%d", b[i]);
    }
    puts("");
    return 0;
}