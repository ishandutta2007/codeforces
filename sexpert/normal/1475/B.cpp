#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        ll x;
        cin >> x;
        cout << (((x % 2020) <= (x / 2020)) ? "YES" : "NO") << '\n'; 
    }
}