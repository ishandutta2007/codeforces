#include <bits/stdc++.h>
using namespace std;

int a[30];

bool chk(int i, int j, int k, int l) {
    if (a[i] == a[j] && a[j] == a[k] && a[k] == a[l]) return true;
    return false;
}

bool func1() {
    if (!chk(9, 10, 11, 12)) return false;
    if (chk(13, 14, 7, 8) && chk(5, 6, 19, 20) && chk(17, 18, 23, 24) && chk(21, 22, 15, 16)) return true;
    if (chk(13, 14, 23, 24) && chk(5, 6, 15, 16) && chk(17, 18, 7, 8) && chk(21, 22, 19, 20)) return true;
    return false;
}

bool func2() {
    if (!chk(13, 14, 15, 16)) return false;
    if (!chk(17, 18, 19, 20)) return false;
    if (chk(1, 3, 6, 8) && chk(5, 7, 10, 12) && chk(9, 11, 23, 21) && chk(22, 24, 2, 4)) return true;
    if (chk(1, 3, 21, 23) && chk(5, 7, 2, 4) && chk(9, 11, 6, 8) && chk(22, 24, 10, 12)) return true;
    return false;
}

bool func3() {
    if (!chk(5, 6, 7, 8)) return false;
    if (!chk(21, 22, 23, 24)) return false;
    if (chk(9, 10, 18, 20) && chk(17, 19, 1, 2) && chk(3, 4, 13, 15) && chk(14, 16, 11, 12)) return true;
    if (chk(9, 10,13, 15) && chk(17, 19, 11, 12) && chk(3, 4, 18, 20) && chk(14, 16, 1, 2)) return true;
    return false;
}
bool ans;
int main() {
    for (int i = 1; i <= 24; i ++) scanf("%d", a + i);
    if (chk(1, 2, 3, 4)) ans = func1();
    else if (a[1] == a[3] && a[2] == a[4]) ans = func2();
    else if (a[1] == a[2] && a[3] == a[4]) ans = func3();
    if (ans) puts("YES");
    else puts("NO");
}