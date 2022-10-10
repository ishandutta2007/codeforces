#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int n, ans = 0;
        cin >> n;
        while(n--) {
            int x;
            cin >> x;
            ans += (x != 2);
        }
        cout << ans << '\n';
    }
}