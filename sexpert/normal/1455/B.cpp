#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int x, y = 0;
        cin >> x;
        for(int st = 1;;st++) {
            y += st;
            if(y == x || y >= x + 2) {
                cout << st << '\n';
                break;
            }
        }
    }
}