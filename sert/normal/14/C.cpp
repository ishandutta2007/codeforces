#include <cstdio>
struct pt{
    int x, y;
    pt() {}
    pt(int xx, int yy) {
        x = xx;
        y = yy;
    }
    int operator % (const pt &a) {
        return x * a.x + y * a.y;
    }
    bool operator != (const pt &a) {
        return x != a.x || y != a.y;
    }
    bool operator == (const pt &a) {
        return x == a.x && y == a.y;
    }
    pt operator - (const pt &a) {
        return pt(x - a.x, y - a.y);
    }
};
pt a[5], b[5], x, y, z;
bool victory;
bool check(int g, int h) {
    pt a1, a2, b1, b2;
    a1 = a[g];
    a2 = b[g];
    b1 = a[h];
    b2 = b[h];
    if (a1 == a2 || b1 == b2)
        return false;
    if (a1 != b1 && a1 != b2 && a2 != b1 && a2 != b2)
        return false;
    if (a1 == b2) {
        b2 = a[h];
        b1 = b[h];
    }
    if (a2 == b1) {
        a2 = a[g];
        a1 = b[g];
    }
    if (a2 == b2) {
        a1 = b[g];
        a2 = a[g];
        b1 = b[h];
        b2 = a[h];
    }
    return !((a2 - a1) % (b2 - b1));
}
void go(int c, int d, int e, int f) {
    bool ok = true;
    ok &= check(c, d);
    ok &= check(d, e);
    ok &= check(e, f);
    ok &= check(f, c);
    victory |= ok;
}
int main() {
    //freopen("a.in", "r", stdin);
    for (int i = 0; i < 4; i++)
        scanf("%d%d%d%d", &a[i].x, &a[i].y, &b[i].x, &b[i].y);
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < i; j++)
            for (int ii = 0; ii < j; ii++) {
                x = (i < 4 ? a[i] : b[i - 4]);
                y = (j < 4 ? a[j] : b[j - 4]);
                z = (ii < 4 ? a[ii] : b[ii - 4]);
                if (x == y && y == z && z == x) {
                    printf("NO\n");
                    return 0;
                }
            }
    for (int i = 0; i < 4; i++)
        if ((a[i].x - b[i].x) * (a[i].y - b[i].y)) {
            printf("NO\n");
            return 0;
        }
    go(0, 1, 2, 3);
    go(0, 1, 3, 2);
    go(0, 2, 1, 3);
    go(0, 2, 3, 1);
    go(0, 3, 2, 1);
    go(0, 3, 1, 2);
    if (victory)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}