#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int stx = 1, sty = 1;
    int edx = n, edy = m;
    while (edx > stx || (stx == edx && edy > sty)) {
        printf("%d %d\n", stx, sty);
        printf("%d %d\n", edx, edy);
        if (sty < m) sty ++;
        else stx ++, sty = 1;
        if (edy > 1) edy --;
        else edx --, edy = m;
    }
    if (stx == edx && sty == edy) printf("%d %d\n", stx, sty);
}