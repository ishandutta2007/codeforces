#include <bits/stdc++.h>
using namespace std;

#define M 100005

int n, m;
int a[M], b[M], v[M];

int main() {
    scanf("%d %d", &n, &m);
    if (n == 1) {
        if (m == 1) {
            printf("YES\n1\n");
            return 0;
        }
        if (m <= 3) {
            printf("NO\n");
            return 0;
        }
        printf("YES\n");
        if (m == 4) printf("3 1 4 2\n");
        else if (m & 1) {
            for (int i = 1; i <= m; i ++) {
                if (i & 1) {
                    printf("%d ", i + 1 >> 1);
                }
                else printf("%d ", m / 2 + 1 + i / 2);
            }
        }
        else {
            for (int i = 1; i <= m; i ++) {
                if (i & 1) printf("%d ", i + 1 >> 1);
                else printf("%d ", m / 2 + i / 2);
            }
        }
        return 0;
    }
    if (n == 2) {
        if (m <= 3) printf("NO\n");
        else if (m == 4) {
            printf("YES\n3 1 4 2\n6 8 5 7\n");
        }
        else {
            printf("YES\n");
            if (m & 1) {
                for (int i = 1; i <= m; i ++) {
                    if (i & 1) {
                        a[i] = i + 1 >> 1;
                    }
                    else a[i] = m / 2 + 1 + i / 2;
                }
                for (int i = 1; i <= m; i ++) printf("%d ", a[i]);
                printf("\n%d", a[m] + m);
                for (int i = 1; i <= m - 1; i ++) printf(" %d", a[i] + m); puts("");
            }
            else {
                for (int i = 1; i <= m; i ++) {
                    if (i & 1) a[i] = i + 1 >> 1;
                    else a[i] = m / 2 + i / 2;
                }
                for (int i = 1; i <= m; i ++) printf("%d ", a[i]); puts("");
                for (int i = 1; i <= m; i ++) printf("%d ", m + a[(((i - 1) ^ 1) + 1)]); puts ("");
            }
        }
        return 0;
    }
    if (m == 1) {
        if (n == 3) printf("NO\n");
        else if (n == 4) printf("YES\n3\n1\n4\n2\n");
        else if (n & 1) {
            puts("YES");
            for (int i = 1; i <= n; i ++) {
                if (i & 1) {
                    printf("%d\n", i + 1 >> 1);
                }
                else printf("%d\n", n / 2 + 1 + i / 2);
            }
        }
        else {
            puts("YES");
            for (int i = 1; i <= n; i ++) {
                if (i & 1) printf("%d\n", i + 1 >> 1);
                else printf("%d\n", n / 2 + i / 2);
            }
        }
        return 0;
    }
    if (m == 2) {
        if (n <= 3) {printf("NO\n");return 0;}
        for (int i = 1; i <= n; i ++) for (int j = 1; j <= m; j ++) {
            v[i+(j-1)*n] = j + (i-1) * m;
        }
        printf("YES\n");
        if (n == 4) {
            a[1] = 3, a[2] = 1, a[3] = 4, a[4] = 2;
            b[1] = 2, b[2] = 4, b[3] = 1, b[4] = 3;
            for (int i = 1; i <= n; i ++) printf("%d %d\n", v[a[i]], v[b[i]+4]);
        }
        else {
            if (n & 1) {
                for (int i = 1; i <= n; i ++) {
                    if (i & 1) {
                        a[i] = i + 1 >> 1;
                    }
                    else a[i] = n / 2 + 1 + i / 2;
                }
                for (int i = 1; i <= n - 1; i ++) b[i+1] = a[i] + n;
                b[1] = a[n] + n;
                for (int i = 1; i <= n; i ++) printf("%d %d\n", v[a[i]], v[b[i]]);
            }
            else {
                for (int i = 1; i <= n; i ++) {
                    if (i & 1) a[i] = i + 1 >> 1;
                    else a[i] = n / 2 + i / 2;
                }
                for (int i = 1; i <= n; i ++) printf("%d %d\n", v[a[i]], v[n + a[(((i - 1) ^ 1) + 1)]]); puts("");
            }
        }
        return 0;
    }
    if (n == 3 && m == 3) {
        printf("YES\n5 9 1\n7 2 8\n3 4 6\n");
        return 0;
    }
    if (n >= 4) {
        printf("YES\n");
        for (int i = 1; i <= n; i ++) for (int j = 1; j <= m; j ++) {
            v[i+(j-1)*n] = j + (i-1) * m;
        }
        if (n == 4) {
            a[1] = 3, a[2] = 1, a[3] = 4, a[4] = 2;
            b[1] = 2, b[2] = 4, b[3] = 1, b[4] = 3;
        }
        else if (n & 1) {
            for (int i = 1; i <= n; i ++) {
                if (i & 1) {
                    a[i] = i + 1 >> 1;
                }
                else a[i] = n / 2 + 1 + i / 2;
            }
            for (int i = 1; i <= n - 1; i ++) b[i+1] = a[i];
            b[1] = a[n];
        }
        else {
            for (int i = 1; i <= n; i ++) {
                if (i & 1) a[i] = i + 1 >> 1;
                else a[i] = n / 2 + i / 2;
            }
            for (int i = 1; i <= n; i ++) b[i] = a[(((i - 1) ^ 1) + 1)];
        }
        for (int i = 1; i <= n; i ++) {
            for (int j = 1; j <= m; j ++) {
                if (j & 1) printf("%d ", v[a[i] + (j - 1) * n]);
                else printf("%d ", v[b[i] + (j - 1) * n]);
            }
            puts("");
        }
        return 0;
    }
    if (m >= 4) {
        printf("YES\n");
        if (m == 4) {
            a[1] = 3, a[2] = 1, a[3] = 4, a[4] = 2;
            b[1] = 2, b[2] = 4, b[3] = 1, b[4] = 3;
        }
        else if (m & 1) {
            for (int i = 1; i <= m; i ++) {
                if (i & 1) {
                    a[i] = i + 1 >> 1;
                }
                else a[i] = m / 2 + 1 + i / 2;
            }
            for (int i = 1; i <= m - 1; i ++) b[i+1] = a[i];
            b[1] = a[m];
        }
        else {
            for (int i = 1; i <= m; i ++) {
                if (i & 1) a[i] = i + 1 >> 1;
                else a[i] = m / 2 + i / 2;
            }
            for (int i = 1; i <= m; i ++) b[i] = a[(((i - 1) ^ 1) + 1)];
        }
        for (int i = 1; i <= n; i ++) {
            for (int j = 1; j <= m; j ++) {
                if (i & 1) printf("%d ", a[j] + (i - 1) * m);
                else printf("%d ", b[j] + (i - 1) * m);
            }
            puts("");
        }
        return 0;
    }
}