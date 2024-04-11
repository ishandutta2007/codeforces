#include <cstdio>

using namespace std;

int n, k;
int main()
{
    scanf("%d%d", &n, &k);
    if (n == k) {
        for (int i = 1; i <= n; i++) printf("1");
        return 0;
    }
    if (k == 1) {
        printf("1");
        for (int i = 1; i < n; i++) printf("0");
        return 0;
    }
    int x = (n - k) / 2 + 1;
    for (int i = 0; i < n; i++) {
        printf("%d", i % x == 0 ? 1 : 0);
    }
    return 0;
}