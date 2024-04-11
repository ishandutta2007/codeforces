#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cstring>
#include <cstdlib>
#include <cmath>

using namespace std;

int main()
{
    printf("? ");
    for (int i = 0; i < 100; i++) {
        printf("%d ", i);
    }
    printf("\n");
    fflush(stdout);

    int ans1;
    scanf("%d", &ans1);
    if (ans1 == -1) return 0;
    ans1 >>= 7; ans1 <<= 7;

    printf("? ");
    for (int i = 2; i <= 101; i++) {
        printf("%d ", i << 7);
    }
    printf("\n");
    fflush(stdout);

    int ans2;
    scanf("%d", &ans2);
    if (ans2 == -1) return 0;
    ans2 = ans2 & ((1 << 7) - 1);

    printf("! %d", ans1 | ans2);
    fflush(stdout);
    return 0;
}