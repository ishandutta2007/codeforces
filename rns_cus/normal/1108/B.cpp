#include <bits/stdc++.h>
using namespace std;

int n, a[200];
bool vis[11111];

int main() {
    scanf("%d", &n);
    int x = 0, y = 0;
    for (int i = 0; i < n; i ++) scanf("%d", &a[i]), x = max(x, a[i]);
    for (int i = 0; i < n; i ++) {
        if (!vis[a[i]] && x % a[i] == 0) vis[a[i]] = 1;
        else y = max(y, a[i]);
    }
    if (x > y) swap(x, y);
    printf("%d %d", x, y);
    return 0;
}