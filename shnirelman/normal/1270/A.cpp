#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    int k1, k2;
    cin >> k1 >> k2;
    int ans = 2;
    for(int i = 0; i < k1; i++) {
        int a;
        cin >> a;
        if(a == n)
            ans = 1;
    }

    for(int i = 0; i < k2; i++) {
        int a;
        cin >> a;
    }

    cout << (ans == 1 ? "YES" : "NO") << endl;
}

int main() {
    int t;
    cin >> t;

    while(t--)
        solve();
}