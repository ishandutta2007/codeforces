#include <stdio.h>

int main() {
    int n, i, j, k, a, b;
    scanf ("%d", &n);
    int sum = 0;
    int cnt=0;
    for (i=0; i<n*2; i++) {
        scanf ("%d.%d", &a, &b);
        sum += b;
        if (b) cnt++;
    }

    int st, en;
    if (n>=cnt) st=0, en=cnt;
    else st=cnt-n, en=n;

    int ans = 1000000000;

    for (i = st; i <= en; i++) {
        int tmp = sum - i*1000;
        if (tmp < 0) tmp = -tmp;
        if (ans > tmp) ans = tmp;
    }

    printf ("%d.%03d", ans / 1000, ans % 1000);

}