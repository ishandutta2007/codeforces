#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int a, b;
        cin >> a >> b;
        cout << (abs(a - b) + 9) / 10 << '\n';
    }    
}