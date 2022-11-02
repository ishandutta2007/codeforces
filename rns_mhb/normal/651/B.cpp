#include <bits/stdc++.h>
using namespace std;

#define N 1005

template <class T> bool chkmax(T &a, T b) { return a < b ? a = b, 1 : 0; }
int n;
int a[N];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) {
        int x;
        scanf("%d", &x);
        a[x] ++;
    }
    int ans = 0;
    for (int i = 1; i < N; i ++) chkmax(ans, a[i]);
    printf("%d\n", n - ans);
    return 0;
}