#include <cstdio>
int gcd(int a, int b) {return (b ? gcd(b, a % b) : a);}
int n, g, h, mx;
int main() {
    scanf("%d%d", &n, &g);
    mx = g;
    for (int i = 1; i < n; i++) {
        scanf("%d", &h);
        g = gcd(h, g);
        if (h > mx) mx = h;
    }
    if ((mx / g - n) % 2 == 0) printf("Bob\n"); else printf("Alice\n");
}