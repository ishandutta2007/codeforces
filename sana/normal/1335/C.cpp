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
        int n; cin >> n;
        map<int,int> c;

        int differentElement = 0;
        int repeatedElement = 0;
        for (int j = 0; j < n; j++) {
            int u; cin >> u;
            if (c[u] == 0) differentElement++;
            c[u]++;
            if (c[u] > repeatedElement) repeatedElement = c[u];
        }

        if (differentElement == repeatedElement) repeatedElement--;
        cout << min(differentElement, repeatedElement) << '\n';
    }

    return 0;
}