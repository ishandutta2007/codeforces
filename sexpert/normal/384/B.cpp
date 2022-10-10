#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m, t;
    cin >> n >> m >> t;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int x;
            cin >> x;
        }
    }
    cout << m*(m - 1)/2 << '\n';
    if(t == 0) {
        for(int bnd = m - 1; bnd >= 1; bnd--) {
            for(int i = 1; i <= bnd; i++) {
                cout << i << " " << i + 1 << '\n';
            }
        }
    }
    else {
        for(int bnd = 2; bnd <= m; bnd++) {
            for(int i = m; i >= bnd; i--) {
                cout << i << " " << i - 1 << '\n';
            }
        }
    }
}