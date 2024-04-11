#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        ll x;
        cin >> x;
        if(x < 15) {
            cout << "NO\n";
            continue;
        }
        x %= 14LL;
        if(x >= 1 && x <= 6) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}