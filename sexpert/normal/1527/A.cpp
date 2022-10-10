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
        int x = 0;
        while(2*x + 1 < n)
            x = 2*x + 1;
        cout << x << '\n';
    }
}