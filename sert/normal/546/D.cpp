#include <bits/stdc++.h>

using namespace std;

const int N = 5e6 + 7;

int kd[N], pr[N];

int getkd(int x) {
    if (kd[x]) return kd[x];
    for (int i = 2; i * i <= x; i++)
    if (x % i == 0) {
        return kd[x / i] + 1;
    }
    return 1;
}

int main() {
    //freopen("a.in", "r", stdin);

    kd[1] = 0;
    pr[1] = 0;
    for (int i = 2; i < N; i++) {
        kd[i] = getkd(i);
        pr[i] = kd[i] + pr[i - 1];
    }

    int a, t, b;
    scanf("%d", &t);
    while (t --> 0) {
        scanf("%d%d", &b, &a);
        printf("%d\n", pr[b] - pr[a]);
    }

    return 0;
}