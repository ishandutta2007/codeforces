#include <cstdio>

using namespace std;

int main()
{
    int a, ans = 0;
    scanf("%d", &a);
    if (a & 1) ans += 16;
    if (a & 2) ans += 2;
    if (a & 4) ans += 8;
    if (a & 8) ans += 4;
    if (a & 16) ans += 1;
    if (a & 32) ans += 32;
    printf("%d", ans);
    return 0;
}