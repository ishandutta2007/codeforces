#include <cstdio>
#include <cstring>

const int N = 1e5 + 34;

int n, k, kol, l, r;
int a[N], b[N];

int main() {
    ///freopen("a.in", "r", stdin);
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if (!b[a[i]])
            kol++;
        b[a[i]]++;
    }

    if (kol < k) {
        printf("-1 -1\n");
        return 0;
    }

    l = 0;
    r = n - 1;

    for (int i = 0; true; i++) {
        if (kol > k || (kol == k && b[a[i]] > 1)) {
            b[a[i]]--;
            if (!b[a[i]])
                kol--;
            l = i + 1;
        } else
            break;
    }

    for (int i = n - 1; true; i--) {
        if (kol > k || (kol == k && b[a[i]] > 1)) {
            b[a[i]]--;
            if (!b[a[i]])
                kol--;
            r = i - 1;
        } else
            break;
    }

    printf("%d %d\n", l + 1, r + 1);

    return 0;
}