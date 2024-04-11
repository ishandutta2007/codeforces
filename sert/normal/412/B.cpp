#include <cstdio>
#include <algorithm>
const int N = 1e6 + 34;
int a[N], n, m;
int main() {
    scanf("%d%d", &n, &m);
    m = n - m;
    for (int i = 0; i < n; i++)
        scanf("%d", a + i);
    std::nth_element(a, a + m, a + n);
    printf("%d\n", a[m]);
}