#include <bits/stdc++.h>
using namespace std;

int n, x;
int tot;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i ++) {
        scanf("%d", &x);
        tot += !x;
    }
    if (tot > 1) {
        puts("NO");
        return 0;
    }
    if ((n == 1) ^ !tot) puts("NO");
    else puts("YES");
    return 0;
}