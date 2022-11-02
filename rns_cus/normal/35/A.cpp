#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int c;
    scanf("%d", &c);
    for (int i = 0; i < 3; i ++) {
        int u, v;
        scanf("%d %d", &u, &v);
        if (c == u || c == v) c = u ^ v ^ c;
    }
    printf("%d\n", c);

    return 0;
}