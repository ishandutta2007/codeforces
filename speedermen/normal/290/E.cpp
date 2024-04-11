#pragma GCC optimization ("unroll-loops")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4")

#include <bits/stdc++.h>

using namespace std;

char s[1 << 20];

int main() {
//    freopen("input.txt", "r", stdin);
    scanf("%s\n", s + 1);
    int len = strlen(s + 1);
    int total = 0;
    for (int i = 1; i <= len; ++i) {
        if (s[i] == 'Q') {
            total += 1;
        }
    }
    int q = 0;
    while ((q + 1) * (q + 1) <= total) {
        q += 1;
    }
    bool ok = false;
    if (q * q == total && (len - total) % (q + 1) == 0) {
        int h = (len - total) / (q + 1), ih = 0;
        while (ih + 1 <= len && s[ih + 1] == 'H') {
            ih += 1;
        }
        if (ih % 2 == 0) {
            ok = (ih / 2 + h + q <= len);
            for (int i = 1, c = 0; i <= h + q && ok; ++i) {
                if (s[ih / 2 + i] == 'H') {
                    ok &= s[++c] == 'H';
                } else {
                    for (int j = 1; j <= h + q && ok; ++j) {
                        ok &= s[++c] == s[ih / 2 + j];
                    }
                }
            }
        }
    }
    printf(ok || !q ? "Yes\n" : "No\n");
    return 0;
}