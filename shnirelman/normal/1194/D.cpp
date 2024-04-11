#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;

    if(k % 3) {
        cout << (n % 3 ? "Alice" : "Bob") << endl;
    } else {
        //if(n % (k + 1) == 0)
        //    cout << "Alice" << endl;
        //else {
        n %= k + 1;
            //cout << n << endl;
        cout << (n % 3 || n == k ? "Alice" : "Bob") << endl;
        //}
    }
}

int main() {
    int t;
    cin >> t;

    while(t--)
        solve();
}