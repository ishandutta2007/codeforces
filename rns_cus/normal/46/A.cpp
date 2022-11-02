#include <bits/stdc++.h>
using namespace std;

#define N

int main() {
//    freopen("1.in", "r", stdin);
    int st = 2;
    int n;
    scanf("%d", &n);
    for (int i = 2; i <= n; i ++) {
        printf("%d%c", st, " \n"[i==n]);
        st = (st + i - 1) % n + 1;
    }

}