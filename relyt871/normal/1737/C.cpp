#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 200005;

template <typename T> inline void read(T &WOW) {
    T x = 0, flag = 1;
    char ch = getchar();
    while (!isdigit(ch)) {
        if (ch == '-') flag = -1;
        ch = getchar();
    }
    while (isdigit(ch)) {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    WOW = flag * x;
}

LL Calc(LL x) {
    if (x == 0) return 0;
    LL y = sqrt(x), ret = 0;
    while (y * (y + 2) > x) {
        ret += (y * y <= x) + (y * y + y <= x);
        --y;
    }
    ret += y * 3;
    return ret;
}

void solve() {
    int n, r1, c1, r2, c2, r3, c3, x, y;
    read(n);
    read(r1); read(c1); read(r2); read(c2); read(r3); read(c3);
    if (r1 == r3) {
        swap(c1, c3);
    }
    if (r2 == r3) {
        swap(r1, r3);
        swap(c1, c3);
    }
    //now r1 = r2
    if (c2 == c3) {
        swap(c1, c2);
    }
    //now c1 = c3
    read(x); read(y);
    if ((r1 == 1 || r1 == n) && (c1 == 1 || c1 == n)) {
        puts((x == r1 || y == c1)? "YES" : "NO");
        return;
    }
    if (((r1 - x) & 1) && ((c1 - y) & 1)) {
        puts("NO");
    } else {
        puts("YES");
    }
}

int main() {
    int T; read(T);
    while (T--) {
        solve();
    }
    return 0;
}