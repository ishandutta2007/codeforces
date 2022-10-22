#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    cout << (n + 1) % 2 << endl;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t;
    cin >> t;

    while(t--)
        solve();

}