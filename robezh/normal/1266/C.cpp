#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


int n, m;


int main() {
    cin >> n >> m;
    if(n == 1 && m == 1) return cout << 0 << endl, 0;
    if(m == 1) {
        for(int j = 1; j <= n; j++) cout << j + 1 << '\n';
        return 0;
    }

    for(int i = 1; i <= n; i++) {
        for(int j = n + 1; j <= n + m; j++) {
            cout << i * j << " ";
        }
        cout << '\n';
    }
}