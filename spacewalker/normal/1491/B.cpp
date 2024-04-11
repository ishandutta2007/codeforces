#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n, u, v; scanf("%d %d %d", &n, &u, &v);
        vector<int> a(n);
        for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
        int diff = 0;
        for (int i = 0; i + 1 < n; ++i) diff = max(diff, abs(a[i+1] - a[i]));
        if (diff > 1) printf("0\n");
        else if (diff == 1) printf("%d\n", min(u, v));
        else printf("%d\n", min(u + v, 2 * v));
    }
}