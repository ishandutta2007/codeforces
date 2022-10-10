#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n, k;
    cin >> n >> k;
    if(n >= 2 * k && n % 2 == 0) {
        cout << "YES\n";
        for(int i = 0; i < k - 1; i++)
            cout << "2 ";
        cout << n - 2*(k - 1) << '\n';
        return;
    }
    if(n >= k && n % 2 == k % 2) {
        cout << "YES\n";
        for(int i = 0; i < k - 1; i++)
            cout << "1 ";
        cout << n - k + 1 << '\n';
        return;
    }
    cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}