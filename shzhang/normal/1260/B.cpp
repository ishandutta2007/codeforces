#include <cstdio>

using namespace std;

int main()
{
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        if (a > b) {
            int t = a; a = b; b = t;
        }
        if (a * 2 < b || (a + b) % 3) {
            printf("NO\n");
        } else {
            printf("YES\n");
        }
    }
    return 0;
}