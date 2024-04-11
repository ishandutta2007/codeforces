#include <cstdio>

const int N = 200;

int a[N][N];
int n, m;
bool fail;

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &a[i][j]);
    while (true) {
        if (n % 2)
            break;
        fail = false;
        for (int i = 0; i < n / 2; i++)
            for (int j = 0; j < m; j++)
                if (a[i][j] != a[n - i - 1][j])
                    fail = true;
        if (fail)
            break;
        n /= 2;
    }
    printf("%d\n", n);
    return 0;
}