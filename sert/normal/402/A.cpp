#include <cstdio>
int k, a, b, v, kol, lst;
int main() {
    scanf("%d%d%d%d", &k, &a, &b, &v);
    a = (a + v - 1) / v;
    kol = 0;
    lst = k;
    while (a--) {
        if (lst == k || b == 0) {
            lst = 1;
            kol++;
        } else {
            lst++;
            b--;
        }
    }
    printf("%d\n", kol);
}