#include <bits/stdc++.h>
using namespace std;

#define N 105

int n, pos, sum;
int a[N];

int main() {
    scanf("%d", &n);
    pos = -1;
    for (int i = 1; i <= n; i ++) {
        scanf("%d", &a[i]);
        if (a[i]) pos = i;
        sum += a[i];
    }
    if (sum) {
        printf("YES\n1\n1 %d\n", n);
    }
    else {
        if (pos == -1) printf("NO\n");
        else printf("YES\n2\n1 %d\n%d %d\n", pos - 1, pos, n);
    }
}