#include <bits/stdc++.h>
using namespace std;

#define N 200100

int n, a[N], o[N], id[N];

int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
        scanf("%d", &n);
        for (int i = 1; i < 2 * n; i ++) scanf("%d %d", &a[i], &o[i]), id[i] = i;
        sort(id + 1, id + 2 * n, [&](int i, int j) {return a[i] > a[j];});
        puts("YES");
        printf("%d", id[1]);
        for (int i = 2; i < 2 * n; i += 2) printf(" %d", o[id[i]] > o[id[i+1]] ? id[i] : id[i+1]);
        puts("");
    }

    return 0;
}