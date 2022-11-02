#include <bits/stdc++.h>
using namespace std;

#define N 2000005

int n;
int a[N];
int c[4];

int ans;
int cnt, p[N];
int phi[N], mu[N];
bool isprime[N];

void ppm() {
    phi[1] = mu[1] = 1;
    for (int i = 2; i < N; i ++) {
        if (!phi[i]) isprime[i] = 1, p[++cnt] = i, phi[i] = i - 1, mu[i] = -1;
        for (int j = 1; j <= cnt && i * p[j] < N; j ++) {
            int k = i * p[j];
            phi[k] = phi[i] * (p[j] - 1);
            if (i % p[j] == 0) {
                phi[k] = phi[i] * p[j];
                break;
            }
            mu[k] = -mu[i];
        }
    }
}

int main() {
    ppm();
    scanf("%d", &n);
    for (int i = 0; i < n; i ++) {
        scanf("%d", &a[i]);
        c[1] += a[i] == 1;
        if (a[i] > 1 && isprime[a[i]+1]) ans = a[i];
    }
    if (ans && c[1] >= 2) {
        printf("%d\n", c[1] + 1);
        printf("%d ", ans);
        while (c[1] --) printf("1 ");
        return 0;
    }
    if (c[1] >= 3) {
        printf("%d\n", c[1]);
        while (c[1] --) printf("1 ");
        return 0;
    }
    if (c[2] >= 1 && c[1] >= 2) {
        printf("3\n2 1 1\n");
        return 0;
    }
    for (int i = 0; i < n; i ++) for (int j = i + 1; j < n; j ++) {
        if (isprime[a[i]+a[j]]) {
            printf("2\n%d %d\n", a[i], a[j]);
            return 0;
        }
    }
    printf("1\n%d\n", a[0]);
    return 0;
}