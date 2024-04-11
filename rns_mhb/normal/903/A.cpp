#include <bits/stdc++.h>
using namespace std;

int T;

int main() {
    scanf("%d", &T);
    while (T --) {
        bool ans = 0;
        int x;
        scanf("%d", &x);
        for (int i = 0; i < 100; i ++) for (int j = 0; j < 100; j ++) if (3 * i + 7 * j == x) ans = 1;
        if (ans) puts("YES");
        else puts("NO");
    }
    return 0;
}