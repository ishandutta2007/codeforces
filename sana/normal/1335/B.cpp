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
        int n, a, b; cin >> n >> a >> b;
        for (int j = 0; j < n; j++) {
            cout << (char)((j%b) + 'a');
        }
        cout << '\n';
    }

    return 0;
}