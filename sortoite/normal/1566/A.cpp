#include <bits/stdc++.h>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
#endif
    int T; cin >> T;
    while(T --) {
        int n, s;
        scanf("%d %d", &n, &s);
        printf("%d\n", s / (n + 2 >> 1));
    }
    return 0;
}