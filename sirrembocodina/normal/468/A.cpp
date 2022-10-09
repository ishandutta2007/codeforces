#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int n;
    cin >> n;
    if (n <= 3) {
        printf("NO\n");
        return 0;
    }
    printf("YES\n");
    int ones = 0;
    if (n & 1) {
        for (int i = 6; i < n; i += 2) {
            printf("%d - %d = 1\n", i + 1, i);
            ++ones;
        }
        printf("5 - 2 = 3\n");
        printf("3 - 1 = 2\n");
        printf("2 * 3 = 6\n");
        printf("6 * 4 = 24\n");
    } else {
        for (int i = 5; i < n; i += 2) {
            printf("%d - %d = 1\n", i + 1, i);
            ++ones;
        }
        printf("1 * 2 = 2\n");
        printf("2 * 3 = 6\n");
        printf("6 * 4 = 24\n");
    }
    for (int i = 0; i < ones; ++i) {
        printf("24 * 1 = 24\n");
    }
    return 0;
}