#include <cstdio>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int c, sum;
        scanf("%d%d", &c, &sum);
        if (c > sum) {
            printf("%d\n", sum);
        } else {
            printf("%d\n", (sum / c + 1) * (sum / c + 1) * (sum % c) + (sum / c) * (sum / c) * (c - sum % c));
        }
    }
    return 0;
}