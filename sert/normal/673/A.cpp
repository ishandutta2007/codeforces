//made by Sert
#include <cstdio>
int main() {
    int n, lst, cur = 0;
    scanf("%d", &n);
    while (n--) {
        lst = cur;
        scanf("%d", &cur);
        if (cur - lst > 15) {
            printf("%d\n", lst + 15);
            return 0;
        }
    }
    printf("%d\n", (cur + 15 < 90 ? cur + 15 : 90));
    return 0;
}