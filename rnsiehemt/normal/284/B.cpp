#include <cstdio>

int main()
{
    int n; scanf("%d", &n);
    int a = 0, i = 0;
    for (int k = 0; k < n; k++) {
        char c; scanf(" %c", &c);
        if (c == 'A') a++;
        else if (c == 'I') i++;
    }
    if (i == 0) printf("%d\n", a);
    else if (i == 1) printf("1\n");
    else printf("0\n");
}