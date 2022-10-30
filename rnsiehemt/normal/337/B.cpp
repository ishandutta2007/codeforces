#include <cstdio>

int a, b, c, d, p, q;

int main()
{
    scanf("%d%d%d%d", &a, &b, &c, &d);
    if (a*d == b*c) printf("0/1\n");
    else {
        if (a*d < b*c) {
            p = b*c-a*d;
            q = b*c;
        }
        else /* b*c < a*d */ {
            p = a*d-b*c;
            q = a*d;
        }
        for (int i = 2; i <= 1000*1000; i++) {
            while ((p%i) == 0 && (q%i) == 0) {
                p /= i;
                q /= i;
            }
        }
        printf("%d/%d\n", p, q);
    }
}