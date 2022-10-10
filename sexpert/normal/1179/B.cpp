#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    if(n % 2 == 0) {
        for(int d = 1; 2*d <= n; d++) {
            for(int j = 1; j <= m; j++) {
                cout << d << " " << j << '\n';
                cout << n - d + 1 << " " << m - j + 1 << '\n';
            }
        }
    }
    if(n % 2 == 1) {
        for(int d = 1; 2*d <= n; d++) {
            for(int j = 1; j <= m; j++) {
                cout << d << " " << j << '\n';
                cout << n - d + 1 << " " << m - j + 1 << '\n';
            }
        }
        int x = (n + 1)/2;
        for(int j = 1; 2*j <= m; j++) {
            cout << x << " " << j << '\n';
            cout << x << " " << m + 1 - j << '\n';
        }
        if(m % 2)
            cout << x << " " << (m + 1)/2 << '\n';
    }    
}