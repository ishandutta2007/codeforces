#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int main()
{
    int n, k, l, c, d, p, nl, np;
    scanf("%d%d%d%d%d%d%d%d", &n, &k, &l, &c, &d, &p, &nl, &np);
    int m = (l * k) / (n * nl);
    m = min(m, (d * c) / n);
    m = min(m, p / (n * np));
    printf("%d", m);
    return 0;
}