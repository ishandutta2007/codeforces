#include <cstdio>
#include <cstring>

const int N = 1e5 + 34;

int n, m, p;

int main() {
    ///freopen("a.in", "r", stdin);
    scanf("%d %d %d", &n, &m, &p);
    printf("%d\n", ((m - 1) * m) / 2);

    if (!p) {
        for (int i = 0; i < m; i++)
            for (int j = i + 1; j < m; j++)
                printf("%d %d\n", i + 1, j + 1);
    } else {
        for (int i = 0; i < m; i++)
            for (int j = i + 1; j < m; j++)
                printf("%d %d\n", j + 1, i + 1);
    }

    return 0;
}