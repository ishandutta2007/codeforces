#include <cstdio>

using namespace std;

int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    int x = a / 2, y = x + 1;
    if ((b == x || b == y) && (c == x || c == y)) {
        printf("NO\n");
    } else {
        printf("YES\n");
    }
    return 0;
}