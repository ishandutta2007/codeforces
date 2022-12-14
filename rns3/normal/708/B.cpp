#include <bits/stdc++.h>
using namespace std;
#define M 100100
typedef long long LL;
LL a, ab, ba, b;
LL tot;

void End() {
    puts("Impossible");
    exit(0);
}

void ok(LL &x) {
    LL t = 0;
    //printf("x = %I64d;", x);
    for (t = 1; ; t++) {
        LL s = t * (t - 1) / 2;
        //printf("t = %I64d; s = %I64d\n", s);
        if (s == x) { x = t; return; }
        if (s > x) {
            End();
        }
    }
}

void solve(LL a, LL b, LL ab) {
    if (a == 0) {
        while (b--) putchar('1');puts("");
        return;
    }
    if (b == 0) {
        while (a--) putchar('0');puts("");
        return;
    }
    if (ab >= b) {
        putchar('0');
        solve(a - 1, b, ab - b);
    } else {
        putchar('1');
        solve(a, b - 1, ab);
    }
}

int main() {
    //freopen("B1.in", "r", stdin);
    scanf("%I64d %I64d %I64d %I64d", &a, &ab, &ba, &b);
    tot = a + ab + ba + b;
    if (tot == 0) {
        puts("0");
        return 0;
    }
    if (ab == 0 && ba == 0) {
        if (a && b) End();
        ok(a);
        ok(b);
        if (a > 1 && b > 1) End();
        if (a > 1) while (a--) putchar('0');
        if (b > 1) while (b--) putchar('1');
        puts("");
        return 0;
    }
    ok(a);
    ok(tot);
    //puts("ABC");
    ok(b);

    ///printf("a = %I64d, b = %I64d, tot = %I64d\n", a, b, tot);
    if (tot != a + b) End();
    if (ab + ba != a * b) End();
    solve(a, b, ab);
    return 0;
}