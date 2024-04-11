#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        if(n == 1) {
            cout << "9\n";
            continue;
        }
        cout << "98";
        for(int i = 2; i < n; i++) {
            cout << (7 + i) % 10;
        }
        cout << '\n';
    }
}