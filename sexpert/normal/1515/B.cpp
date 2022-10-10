#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        if(n % 2) {
            cout << "NO\n";
            continue;
        }
        int x = sqrt(n);
        bool good = false;
        for(int y = x - 2; y <= x + 2; y++) {
            if(y * y == n) {
                cout << "YES\n";
                good = true;
                break;
            }
        }
        if(good)
            continue;
        n /= 2;
        x = sqrt(n);
        for(int y = x - 2; y <= x + 2; y++) {
            if(y * y == n) {
                cout << "YES\n";
                good = true;
                break;
            }
        }
        if(good)
            continue;
        cout << "NO\n";
    }
}