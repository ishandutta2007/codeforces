#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int x, ans = 720720;
            cin >> x;
            if((i + j) % 2)
                ans -= x * x * x * x;
            cout << ans << " ";
        }
        cout << '\n';
    }
}