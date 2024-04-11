#include <bits/stdc++.h>

using namespace std;

int LSB(int x) {return (x & (-x));}

bool solve() {
    int a, b; scanf("%d %d", &a, &b);
    if (a > b) {
        return false;
    }
    while (a > 0 && b > 0) {
        if (LSB(a) > LSB(b)) return false;
        a -= LSB(a); b -= LSB(b);
    }
    if (a == 0 && b > 0) return false;
    return true;
}

int main() {
    int q; scanf("%d", &q);
    while (q--) {
        printf("%s\n", solve() ? "YES" : "NO");
    }
}