#include <cstdio>

const int N = 1e6 + 34;
int a[N], b[N], n, m, ps;

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int ps = 0;
        for (int j = 0; j < n; j++) {
            scanf("%d", a + j);
            if (a[j] > a[ps])
                ps = j;
        }
        b[ps]++;
    }
    ps = 0;
    for (int i = 0; i < n; i++)
        if (b[i] > b[ps])
            ps = i;
    printf("%d", ps + 1);
}