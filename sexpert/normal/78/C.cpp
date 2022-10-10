#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    if(n & 1) {
        for(int d = 1; d * d <= m; d++) {
            if(m % d)
                continue;
            if((d >= k && d < m) || (m/d >= k && d > 1)) {
                cout << "Timur\n";
                return 0;
            }
        }
    }
    cout << "Marsel\n";
}