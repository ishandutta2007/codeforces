#ifdef LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t; cin >> t;
    for (int i = 0; i < t; i++) {
        int x,n,m;
        cin >> x >> n >> m;

        while (n) {
            int nx = x/2 + 10;
            if (nx > x) break;
            x = nx;
            n--;
        }

        x -= m*10;

        cout << (x <= 0 ? "YES" : "NO") << '\n';
    }

    return 0;
}