#include <bits/stdc++.h>
using namespace std;

#define N 105

int n, m;
int a[N][5];

void print(int x) {
    if (x <= m) printf("%d ", x);
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i ++) {
        a[i][0] = 1 + 2 * i;
        a[i][1] = 1 + 2 * i + 2 * n;
        a[i][2] = 2 + 2 * i + 2 * n;
        a[i][3] = 2 + 2 * i;
    }
    for (int i = 0; i < n; i ++) {
        print(a[i][1]);
        print(a[i][0]);
        print(a[i][2]);
        print(a[i][3]);
    }
    return 0;
}