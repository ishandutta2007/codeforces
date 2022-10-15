#include <cctype>
#include <cstdio>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

int mod, a1, b1, x1, y1, p1, d1, a2, b2, x2, y2, p2, d2;

inline int getNext1(int a) {
    return (1ll * a * x1 + y1) % mod;
}
inline int getNext2(int a) {
    return (1ll * a * x2 + y2) % mod;
}

inline int findLoop1(int a) {
    int _ = a;
    for (int i = 1; i <= 2000000; i++) {
        a = getNext1(a);
        if (_ == a) { return i; }
    }
    return -1;
}
inline int findLoop2(int a) {
    int _ = a;
    for (int i = 1; i <= 2000000; i++) {
        a = getNext2(a);
        if (_ == a) { return i; }
    }
    return -1;
}

inline int findEnd1(int a) {
    for (int i = 0; i <= 2000000; i++) {
        if (a == b1) { return i; }
        a = getNext1(a);
    }
    return -1;
}
inline int findEnd2(int a) {
    for (int i = 0; i <= 2000000; i++) {
        if (a == b2) { return i; }
        a = getNext2(a);
    }
    return -1;
}

int main() {
    mod = read();
    a1 = read(); b1 = read(); x1 = read(); y1 = read();
    a2 = read(); b2 = read(); x2 = read(); y2 = read();
    for (int i = 0; i < 2000000; i++) {
        if (a1 == b1 && a2 == b2) { printf("%d\n", i); return 0; }
        a1 = getNext1(a1); a2 = getNext2(a2);
    }
    p1 = findLoop1(a1); d1 = findEnd1(a1);
    p2 = findLoop2(a2); d2 = findEnd2(a2);
    if (d1 == -1 || d2 == -1) { printf("-1\n"); return 0; }
    for (int i = 0; i < 2000000; i++) {
        if ((1ll * i * p1 + d1) % p2 == d2) {
            printf("%lld\n", 1ll * i * p1 + d1 + 2000000); return 0;
        }
    }
    printf("-1\n");
    return 0;
}