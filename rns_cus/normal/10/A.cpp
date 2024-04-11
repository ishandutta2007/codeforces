#include <stdio.h>

int n, p1, p2, p3, t1, t2;
int a[105], b[105];
int sum;

int main() {
    //freopen("a.in", "r", stdin);
    scanf("%d %d %d %d %d %d", &n, &p1, &p2, &p3, &t1, &t2);
    for (int i = 0; i < n; i ++) {
        scanf("%d %d", &a[i], &b[i]);
    }
    sum =  p1 * (b[0] - a[0]);
    if (n == 1) printf("%d", sum);
    else {
        for (int i = 1; i < n; i ++) {
            sum = sum + p1 * (b[i] - a[i]);
            if ((a[i] - b[i - 1]) > 0 && (a[i] - b[i - 1]) <= t1) sum = sum + p1 * (a[i] - b[i - 1]);
            if ((a[i] - b[i - 1]) > t1 && (a[i] - b[i - 1]) <= t1 + t2) sum = sum + p1 * t1 + p2 * (a[i] - b[i - 1] - t1);
            if ((a[i] - b[i - 1]) > t1 + t2) sum = sum + p1 * t1 + p2 * t2 + p3 * (a[i] - b[i - 1] - t1 - t2);
        }
        printf("%d", sum);
    }
}