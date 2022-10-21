#include<bits/stdc++.h>
using namespace std;

int n, m, r, c;

int main() {
    int t;
    for(scanf("%d", &t); t --; ) {
        scanf("%d%d%d%d", &n, &m, &r, &c);
        int ans = max(r - 1, n - r) + max(m - c, c - 1);
        printf("%d\n",ans);
    }
}