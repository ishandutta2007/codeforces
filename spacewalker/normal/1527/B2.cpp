#include <bits/stdc++.h>

using namespace std;
constexpr int NMAX = 2000;

int bestValue(int tc, int oc) {
    if (tc == 0 && oc == 0) return 0;
    if (oc == 0) return 2;
    else return -oc;
}

int solve() {
    int n; scanf("%d", &n);
    static char str[NMAX];
    scanf("%s", str);
    int tc = 0, oc = 0, special = 0;
    for (int i = 0, j = n - 1; i < j; ++i, --j) {
        if (str[i] == '0' && str[j] == '0') ++tc;
        else if (str[i] == '0' || str[j] == '0') ++oc;
    }
    if (n % 2 == 1 && str[n/2] == '0') ++special;
    if (special == 0) {
        int bv = bestValue(tc, oc);
        if (bv == 0) return 0;
        else if (bv < 0) return 1;
        else return -1;
    } else {
        if (tc == 0 && oc == 0) return -1;
        else if (tc == 0 && oc == 1) return 0;
        else return 1;
    }
}

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int ans = solve();
        if (ans == -1) printf("BOB\n");
        if (ans == 0) printf("DRAW\n");
        if (ans == 1) printf("ALICE\n");
    }
}